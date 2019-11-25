#include "Vector2.h"

class Robot
{

private:
    Vector2<int> location;
    float angle;
    Vector2<int> vitesse;
    float lookDistance;
    float robotWidth;

public:
    Robot(Vector2<int> initLoc, float initAngle);

    Vector2<int> getNearestPointToPath();
    Vector2<int> getLookAheadPoint();
    float getCurvature();
    void updateVlVr();
    float getVNormHere();
};
