#include "AStarPathfinding.h"

// Non member functions
Vector2i mmToIndMatrix(Vector2f const& mm)
{
	if (mm.getX() < 0.f || mm.getX() >= tableLength || mm.getY() < 0.f || mm.getY() >= tableWidth)
		return Vector2i(-1, -1);

	return Vector2i(static_cast<int>(mm.getX() * nbSubX / tableLength), static_cast<int>(mm.getY() * nbSubY / tableWidth));
}

Vector2f indMatrixToMm(Vector2i const& indMatrix)
{
	if (indMatrix.getX() < 0.f || indMatrix.getX() >= nbSubX || indMatrix.getY() < 0.f || indMatrix.getY() >= nbSubY)
		return Vector2f(-1.f, -1.f);

	return Vector2f(indMatrix.getX() * tableLength / nbSubX, indMatrix.getY() * tableWidth / nbSubY);
}

// Private Functions

void AStarPathfinding::clearMatrix()
{
	for (int i = 0; i < nbSubX; i++)
	{
		for (int j = 0; j < nbSubY; j++)
		{
			matrix[i][j] = Node({ true, 0.f, 0.f });
		}
	}
}

void AStarPathfinding::addObstacle(Obstacle obstacle)
{
	for (int i = static_cast<int>(-obstacle.getRayon() * nbSubX / tableLength + mmToIndMatrix(obstacle.getPosition()).getX());
		i <= static_cast<int>(obstacle.getRayon() * nbSubX / tableLength + mmToIndMatrix(obstacle.getPosition()).getX());
		++i)
	{
		for (int j = static_cast<int>(-obstacle.getRayon() * nbSubY / tableWidth + mmToIndMatrix(obstacle.getPosition()).getY());
			j <= static_cast<int>(obstacle.getRayon()* nbSubY / tableWidth + mmToIndMatrix(obstacle.getPosition()).getY());
			j++)
		{
			matrix[i][j].accessible = false;
		}
	}
}

float AStarPathfinding::heuristic(Vector2i NodePos, Vector2f endPos) const
{
	return dist(indMatrixToMm(NodePos), endPos);
}

bool AStarPathfinding::isAccessible(int i, int j) const
{
	return (i >= 0 && i < nbSubX && j >= 0 && j < nbSubY && matrix[i][j].accessible);
}

vector<Vector2i> AStarPathfinding::neighbors(Vector2i node)
{
	vector<Vector2i> returnVector;

	for (int i = node.getX() - 1; i <= node.getX() + 1; ++i)
	{
		for (int j = node.getY() - 1; i <= node.getY() + 1; ++j)
		{
			if ((i != 0 || j != 0) && isAccessible(i, j))
			{
				returnVector.push_back(Vector2i(i, j));
			}
		}
	}

	return returnVector;
}

// Public Functions

// Constructor
AStarPathfinding::AStarPathfinding()
{
	for (int i = 0; i < nbSubX; i++)
	{
		for (int j = 0; j < nbSubY; j++)
		{
			matrix[i][j] = Node( { true, 0.f, 0.f } );
		}
	}

	// tests
	addObstacle(Obstacle(Vector2f(1000.f, 1000.f), 200.f));

	affiche();
}

void AStarPathfinding::updateObstacle(vector<Obstacle> obstacles)
{
	clearMatrix();

	for (unsigned int i = 0; i < obstacles.size(); ++i)
	{
		addObstacle(obstacles[i]);
	}
}

vector<Vector2f> AStarPathfinding::generatePath(Vector2f startPos, Vector2f endPos)
{


	return vector<Vector2f>();
}

void AStarPathfinding::affiche() const
{
	for (int j = 0; j < nbSubY; j++)
	{
		for (int i = 0; i < nbSubX; i++)
		{
			if (matrix[i][j].accessible)
			{
				std::cout << ".";
			}
			else if (!matrix[i][j].accessible)
			{
				std::cout << "x";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}