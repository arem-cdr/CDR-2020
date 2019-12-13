#include "stdafx.h"
#include "RRT.h"

bool IntersectObs(sf::Vector2f p1, sf::Vector2f p2, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	for (size_t i = 0; i < obstacles.size(); i++)
	{
		if (IntersectSegCir(p1, p2,
			sf::Vector2f(obstacles[i].getPos().getX(), obstacles[i].getPos().getY()), obstacles[i].getRadius() + radiusObject))
		{
			return true;
		}
	}
	return false;
}

// Node ----------------------------------------
Node::Node() : pos(), parentNode(NULL), distToOrigin(0)
{
	childrenNodes = std::vector<Node*>();
}

Node::Node(const sf::Vector2f pos, Node* parentNode, const float distToOrigin) : pos(pos), parentNode(parentNode), distToOrigin(distToOrigin)
{
	childrenNodes = std::vector<Node*>();
}

Node::~Node()
{
	while (childrenNodes.size() > 0)
	{
		delete childrenNodes[static_cast<int>(childrenNodes.size()) - 1];
		childrenNodes[static_cast<int>(childrenNodes.size()) - 1] = NULL;
		childrenNodes.pop_back();
	}
}

void Node::addChild(const sf::Vector2f posChild)
{
	this->childrenNodes.push_back(new Node(posChild, this, dist(this->pos - posChild) + this->distToOrigin + rotationCost));
}

void Node::linkToTarget(Node& target)
{
	this->childrenNodes.push_back(&target);
	target.setParent(this);
}

void Node::detachTarget(Node& target)
{
	for (size_t i = 0; i < childrenNodes.size(); i++)
	{
		if (childrenNodes[i] == &target)
		{
			childrenNodes.erase(childrenNodes.begin() + i);
		}
	}
	target.setParent(NULL);
}

Node* Node::detachChild(int indChild)
{
	Node* returnNode = this->childrenNodes[indChild];
	childrenNodes.erase(childrenNodes.begin() + indChild);
	return returnNode;
}

void Node::findClosestParcoursRec(sf::Vector2f p, float& d, Node*& closest, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	/*if (this->pos == p)
	{
		closest = this;
		d = 0;
	}*/
	if (this->distToOrigin + dist(p - this->pos) + rotationCost < d && !IntersectObs(p, this->pos, obstacles, radiusObject))
	{
		closest = this;
		d = this->distToOrigin + dist(p - this->pos) + rotationCost;
	}
	for (int i = 0; i < static_cast<int>(childrenNodes.size()); i++)
	{
		childrenNodes[i]->findClosestParcoursRec(p, d, closest, obstacles, radiusObject);
	}
}

// RRT ---------------------------------------------
// Private

Node* RRT::findClosestNode(sf::Vector2f p, const std::vector<MovableRenderObject>& obstacles, float radiusObject) const
{
	Node* closest = NULL;
	float d = 10000.f;
	this->root->findClosestParcoursRec(p, d, closest, obstacles, radiusObject);

	return closest;
}

void RRT::addNode(sf::Vector2f pos, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	Node* indClosest = findClosestNode(pos, obstacles, radiusObject);
	if (indClosest) // si un point a ete trouve
	{
		indClosest->addChild(pos);
	}
}

void RRT::generateTree(int nbIterations, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	for (int i = 0; i < nbIterations; i++)
	{
		sf::Vector2f newNode(radiusObject + 1.f * rand() * (tableLength - 2 * radiusObject) / RAND_MAX,
			radiusObject + 1.f * rand() * (tableWidth - 2 * radiusObject) / RAND_MAX);
		addNode(newNode, obstacles, radiusObject);
	}
}

void RRT::updatePath(sf::Vector2f targetPos, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	// setting target up
	target.setPos(targetPos);
	if (target.getParent())
	{
		target.getParent()->detachTarget(target);
	}

	// finding the best node to link target to
	Node* closest = findClosestNode(targetPos, obstacles, radiusObject);

	if (closest != NULL) // si un point a ete trouve
	{
		closest->linkToTarget(target);

		std::vector<sf::Vector2f> tempPath;
		Node* temp = &target;
		while (temp != NULL)
		{
			tempPath.push_back(temp->getPos());
			temp = temp->getParent();
		}
		if (evaluatePath(tempPath) < pathLength)
		{
			// application du chemin trouvé dans path
			path.resize(tempPath.size(), sf::Vector2f());
			for (int i = 0; i < static_cast<int>(tempPath.size()); ++i)
			{
				path[i] = tempPath[tempPath.size() - 1 - i];
			}
			pathLength = evaluatePath(path);
		}
	}
	if (target.getParent())
	{
		target.getParent()->detachTarget(target);
	}
}

bool RRT::isPathLegit(sf::Vector2f objectPos, sf::Vector2f targetPos, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	if (path.size() == 0 || path[0] != objectPos || path[path.size() - 1] != targetPos)
		return false;

	for (int i = 0; i < static_cast<int>(path.size()) - 1; ++i)
	{
		if (IntersectObs(path[i], path[i + 1], obstacles, radiusObject))
		{
			return false;
		}
	}
	return true;
}

// Public
RRT::RRT() : target(sf::Vector2f(-1, -1))
{
	root = new Node();
	path = std::vector<sf::Vector2f>();
	pathLength = 5000.f;
}

RRT::RRT(Point p1) : target(sf::Vector2f(-1, -1))
{
	this->root = new Node(sf::Vector2f(cmToPx(p1.getX()), cmToPx(p1.getY())));
	root->setPos(sf::Vector2f(cmToPx(p1.getX()), cmToPx(p1.getY())));
	
	path = std::vector<sf::Vector2f>();
	pathLength = 5000.f;
}

RRT::~RRT()
{
	if (target.getParent())
	{
		target.getParent()->detachTarget(target);
	}
	delete root;
}

void RRT::resetTree(Point pos)
{
	if (root)
		delete root;
	root = new Node(sf::Vector2f(pos.getX(), pos.getY()));
}

void RRT::resetPath()
{
	path.resize(0, sf::Vector2f());
	pathLength = 5000.f;
}

int RRT::countNodes() const
{
	int returnNb = 0;

	std::vector<Node*> toVisit = std::vector<Node*>();
	toVisit.push_back(this->root);
	Node* current;
	while (toVisit.size() > 0)
	{
		returnNb++;

		current = toVisit[static_cast<int>(toVisit.size()) - 1];
		toVisit.pop_back();

		for (size_t i = 0; i < current->getChildren().size(); i++)
		{
			toVisit.push_back(current->getChildren()[i]);
		}
	}
	return returnNb;
}

void RRT::maintainTree(Point objectPos, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	root->setPos(sf::Vector2f(objectPos.getX(), objectPos.getY()));
	std::vector<Node*> toCheck, orphanBranches;
	toCheck.push_back(root);
	Node* current;

	while (toCheck.size() > 0)
	{
		current = toCheck[static_cast<int>(toCheck.size()) - 1];
		toCheck.pop_back();
		if (current->getParent())
		{
			current->setDistToOrigin(dist(current->getParent()->getPos() - current->getPos()) + current->getParent()->getDistToOrigin() + rotationCost);
		}
		for (size_t i = 0; i < current->getChildren().size(); i++)
		{
			if (IntersectObs(current->getPos(), current->getChildren()[i]->getPos(), obstacles, radiusObject))
			{ 
				Node* toDelete = current->detachChild(i);
				delete toDelete;
				//delete current->getChildren()[i];
			}
			else
			{
				toCheck.push_back(current->getChildren()[i]);
			}
		}
	}
}

void RRT::update(Point objectPos, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject)
{
	if (!isPathLegit(sf::Vector2f(objectPos.getX(), objectPos.getY()), sf::Vector2f(target.getX(), target.getY()), obstacles, radiusObject))
		resetPath();

	int iterations = 0;
	//while (!isDone(sf::Vector2f(target.getX(), target.getY()), obstacles, radiusObject) && iterations < 50)
	{
		//++iterations;
		updatePath(sf::Vector2f(target.getX(), target.getY()), obstacles, radiusObject);
		//if (countNodes() < 1000)
		{
			generateTree(1, target, obstacles, radiusObject);
		}
	}
}

void RRT::render(sf::RenderTarget& target)
{
	std::vector<sf::Vertex> vertices;

	// dessin de l'arbre

	/*std::vector<Node*> toVisit = std::vector<Node*>();
	toVisit.push_back(this->root);
	Node* current;
	while (toVisit.size() > 0)
	{
		current = toVisit[static_cast<int>(toVisit.size()) - 1];
		toVisit.pop_back();
		for (size_t i = 0; i < current->getChildren().size(); i++)
		{
			vertices.push_back(sf::Vertex(cmToPx(current->getPos()) +
				sf::Vector2f((windowPxLength - tablePxLength) * .5f, (windowPxWidth - tablePxWidth) * .5f)));
			vertices.push_back(sf::Vertex(cmToPx(current->getChildren()[i]->getPos()) +
				sf::Vector2f((windowPxLength - tablePxLength) * .5f, (windowPxWidth - tablePxWidth) * .5f)));
			toVisit.push_back(current->getChildren()[i]);
		}
	}

	if (vertices.size())
		target.draw(&vertices[0], vertices.size(), sf::Lines);*/

		// dessin du path retenu
	vertices.resize(0, sf::Vertex());
	for (int i = 0; i < static_cast<int>(path.size()) - 1; i++)
	{
		vertices.push_back(sf::Vertex(cmToPx(path[i]) +
			sf::Vector2f((windowPxLength - tablePxLength) * .5f, (windowPxWidth - tablePxWidth) * .5f)));
		vertices[vertices.size() - 1].color = sf::Color(250, 50, 50);

		vertices.push_back(sf::Vertex(cmToPx(path[i + 1]) +
			sf::Vector2f((windowPxLength - tablePxLength) * .5f, (windowPxWidth - tablePxWidth) * .5f)));
		vertices[vertices.size() - 1].color = sf::Color(250, 50, 50);
	}

	if (vertices.size())
		target.draw(&vertices[0], vertices.size(), sf::Lines);
}

