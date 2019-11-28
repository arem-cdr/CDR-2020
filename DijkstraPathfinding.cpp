#include "DijkstraPathfinding.h"

DijkstraPathfinding::DijkstraPathfinding()
{
    for (int i = 0; i < nbSubX; i++)
    {
        for (int j = 0; j < nbSubY; j++)
        {
            matrix[i][j] = 0.f;
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
        return;
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
        float ncellcost = 1; // By default 1, but check if with function if not near obstacle or obstacle
        float newcost = matrix[ci][cj] +ncellcost;
        float currentcost = matrix[ncelli][ncellj];
        if((currentcost  == -1) || (newcost < currentcost )){
            matrix[ncelli][ncellj] = newcost; // TODO
            /* this.pq.insert(e,newcost);
            this.matrix[e.i][e.j].pi = c.i;
            this.matrix[e.i][e.j].pj = c.j;
            this.matrix[e.i][e.j].w = e.ow;
            if(this.matrix[e.i][e.j].type != ctype.END && e.type != ctype.OBSTACLE && this.matrix[e.i][e.j].type != ctype.START){
            this.matrix[e.i][e.j].type= ctype.TRAIL;
            }*/
        } 
    }
    return returnVector;
}

void DijkstraPathfinding::transformObstacleInWeight()
{
}

void DijkstraPathfinding::transformObstacleInWeightGradient()
{
}