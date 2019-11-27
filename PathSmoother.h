#pragma once

#include <vector>
#include "PointS.h"
#include <iostream>
using namespace std;

class PathSmoother
{   
    private:
        vector<PointS> generatedPath;

    public:
        PathSmoother();
        void generateSPath(vector<Vector2f> v);
        vector<PointS> getSPath() {return generatedPath;};



};