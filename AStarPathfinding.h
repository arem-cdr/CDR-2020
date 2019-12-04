#pragma once

#include <iostream>

#include "Pathfinding.h"

struct Node
{
	bool accessible;
	float costToReach;
	float distToEnd;
};

Vector2i mmToIndMatrix(Vector2f const& mm);
Vector2f indMatrixToMm(Vector2i const& indMatrix);

class AStarPathfinding : public Pathfinding
{
private:
    Node matrix[nbSubX][nbSubY];

	void clearMatrix();
	void addObstacle(Obstacle obstacle);

	float heuristic(const Vector2i nodePos, const Vector2f endPos) const;
	bool isAccessible(int i, int j) const;
	vector<Vector2i> neighbors(Vector2i node);

public:
    AStarPathfinding();

    virtual void updateObstacle(vector<Obstacle> obstacles);
    virtual vector<Vector2f> generatePath(Vector2f startPos, Vector2f endPos);
	virtual void affiche() const;
};