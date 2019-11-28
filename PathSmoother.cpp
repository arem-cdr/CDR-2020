
#include "PathSmoother.h"

PathSmoother::PathSmoother(float mVel,float mAcc,float slowdownCoef){
    maxVel = mVel;
    maxAcc = maxAcc;
    slowdownInCurvesCoef = slowdownCoef;
}

void PathSmoother::generateSPath(vector<Vector2f> v){


}
