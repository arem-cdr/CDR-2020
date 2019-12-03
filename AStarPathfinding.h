#pragma once

#include <iostream>

#include "Pathfinding.h"

class AStarPathfinding : public Pathfinding
{
private:
    float matrix[nbSubX][nbSubY];

    Vector2i mmToIndMatrix(Vector2f mm);
    Vector2f indMatrixToMm(Vector2i indMatrix);

	void clearMatrix();
	void addObstacle(Obstacle obstacle);

	float heuristic(Vector2i nodePos, Vector2f endPos);
	bool isAccessible(int i, int j);
	vector<Vector2i> neighbors(Vector2i node);

public:
    AStarPathfinding();

    virtual void updateObstacle(vector<Obstacle> obstacles);
    virtual vector<Vector2f> generatePath(Vector2f startPos, Vector2f endPos);
	virtual void affiche() const;
};