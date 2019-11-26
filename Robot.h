#include "Vector2f.h"
#include "PathSmoother.h"
#include "PointS.h"
#include <vector>

class Robot
{

private:
    Vector2f location;
    float angle;
    Vector2f vitesse;
    float lookDistance;
    float robotWidth;

public:
    Robot(Vector2f initLoc, float initAngle);

    Vector2f getLookAheadPoint(PathSmoother ps);
    float getCurvature(Vector2f lookp);
    void updateVlVr(PathSmoother ps);
    float getVNormHere(PathSmoother ps);
};
