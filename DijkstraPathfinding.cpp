#include "DijkstraPathfinding.h"

DijkstraPathfinding::DijkstraPathfinding()
{
    for (int i = 0; i < nbSubX; i++)
    {
        for (int j = 0; j < nbSubY; j++)
        {
            Vector2f init(1,-1); // COUT DE LA CASE / COUT ACTUEL
            matrix[i][j] = init;
        }
    }
}

void DijkstraPathfinding::updateObstacle(vector<Obstacle> obstacles)
{
}

vector<Vector2f> DijkstraPathfinding::generatePath(Vector2f startPos, Vector2f endPos)
{
    vector<Vector2f> returnVector;
    int cellsize = sizeX/nbSubX;
    int si = startPos.getX()/cellsize;
    int sj = startPos.getY()/cellsize;
    int ei = endPos.getX()/cellsize;
    int ej = endPos.getY()/cellsize;

    bool flag = false;
  
    //TODO WHILE JUSQUA FILE DE PRIO VIDE OU FLAG
    Vector2i cell(0,0); //TODO: CREER UNE FILE DE PRIO ET DEPILER DANS cell
    int ci = cell.getX();
    int cj = cell.getY();
    if(ci==ei && cj == ej){
        flag = true;
        return returnVector;
    }
    Vector2i up(cell.getX(),cell.getY()+1);
    Vector2i down(cell.getX(),cell.getY()+1);
    Vector2i left(cell.getX()-1,cell.getY());
    Vector2i right(cell.getX()+1,cell.getY()+1);

    Vector2i nei[4] = {up,down,left,right};

    for(int h=0; h<4;h++){
        Vector2i ncell = nei[h];
        int ncelli = ncell.getX();
        int ncellj = ncell.getY();
        if(ncelli<0 || ncellj<0 || ncelli> (nbSubX)-1 ||ncellj> (nbSubY)-1)continue; // CHECKS IF CELL IS VALID

        float newcost = matrix[ci][cj].getY() +matrix[ncelli][ncellj].getX();
        float currentcost = matrix[ncelli][ncellj].getY();
        if((currentcost  == -1) || (newcost < currentcost )){
            Vector2f newc(matrix[ncelli][ncellj].getX(),newcost);
            matrix[ncelli][ncellj] = newc; 
            /* this.pq.insert(e,newcost);
            this.matrix[e.i][e.j].pi = c.i;
            this.matrix[e.i][e.j].pj = c.j;
            this.matrix[e.i][e.j].w = e.ow;
            */
        } 
    }
    //TODO: USE THE CALCULUS TO REVERSE FROM END POINT THE PATH TO START POINT
    return returnVector;
}

void DijkstraPathfinding::transformObstacleInWeight()
{
}

void DijkstraPathfinding::transformObstacleInWeightGradient()
{
}