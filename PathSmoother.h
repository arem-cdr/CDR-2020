#pragma once

#include <vector>
#include "PointS.h"
#include <iostream>
using namespace std;

class PathSmoother
{   
    private:
        vector<PointS> generatedPath;
        float maxVel;
        float maxAcc;
        float slowdownInCurvesCoef; // BETWEEN 1 and 5

    public:
        PathSmoother(float mVel,float mAcc,float slowdownCoef);
        void generateSPath(vector<Vector2f> v);
        vector<PointS> getSPath() {return generatedPath;};



};