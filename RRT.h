#pragma once

#include "BasicFunctions.h"
#include "Constantes.h"
#include"Point.h"
#include"MovableRenderObject.h"

const float rotationCost = 20.f;

bool IntersectObs(sf::Vector2f p1, sf::Vector2f p2, const std::vector<MovableRenderObject>& obstacles, float radiusObject);

class Node
{
private:
	sf::Vector2f pos; // pos en px

	std::vector<Node*> childrenNodes;
	Node* parentNode;

	float distToOrigin;

public:
	Node();
	Node(const sf::Vector2f pos, Node* parentNode = NULL, const float distToOrigin = 0.f);
	~Node();

	sf::Vector2f getPos() const { return pos; } // renvoie la pos en px
	std::vector<Node*> getChildren() const { return childrenNodes; }
	Node* getParent() const { return parentNode; }
	float getDistToOrigin() const { return distToOrigin; }

	void setDistToOrigin(float d) { distToOrigin = d; }
	void setPos(sf::Vector2f pos) { this->pos = pos; }
	void setParent(Node* parent) { this->parentNode = parent; }

	int nbChildren() const { return childrenNodes.size(); }

	void addChild(const sf::Vector2f posChild);
	void linkToTarget(Node& target);
	void detachTarget(Node& target);

	Node* detachChild(int indChild);

	void findClosestParcoursRec(sf::Vector2f p, float& d, Node*& closest, const std::vector<MovableRenderObject>& obstacles, float radiusObject);
};

class RRT
{
private:
	//std::vector<Node> tree;
	Node* root;
	Node target;
	//std::vector<Node*> orphanTrees;

	std::vector<sf::Vector2f> path;
	float pathLength;

	Node* findClosestNode(sf::Vector2f p, const std::vector<MovableRenderObject>& obstacles, float radiusObject) const;

	float evaluatePath(std::vector<sf::Vector2f> path) const { return dist(path) + path.size() * 20.f; }

	void addNode(sf::Vector2f pos, const std::vector<MovableRenderObject>& obstacles, float radiusObject);

	void generateTree(int nbIterations, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject);

	void updatePath(sf::Vector2f targetPos, const std::vector<MovableRenderObject>& obstacles, float radiusObject);
	bool isPathLegit(sf::Vector2f objectPos, sf::Vector2f targetPos, const std::vector<MovableRenderObject>& obstacles, float radiusObject);

public:
	RRT();
	RRT(Point p1);
	~RRT();

	void resetTree(Point pos);
	void resetPath();

	int countNodes() const;

	void maintainTree(Point objectPos, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject); 

	void update(Point objectPos, Point target, const std::vector<MovableRenderObject>& obstacles, float radiusObject); // fonction principale

	void render(sf::RenderTarget& target);
};
