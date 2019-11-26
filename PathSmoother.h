#pragma once

#include <vector>
#include "PointS.h"
#include <iostream>

class PathSmoother
{   
    private:
        vector<PointS> generatedPath;

    public:
        PathSmoother();
        vector<PointS> generateSPath();



};