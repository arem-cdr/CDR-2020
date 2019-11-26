#include "Vector2f.h"

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

    Vector2f getNearestPointToPath();
    Vector2f getLookAheadPoint();
    float getCurvature();
    void updateVlVr();
    float getVNormHere();
};
