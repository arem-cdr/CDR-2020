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
        vector<PointS> generateSPath();



};