#include "Vector2.h"

class Robot{
    
    private:
        Vector2 location;
        float angle;
        Vector2 velocity; // last Vl and Vr calculated
        float lookDistance;
        float robotWidth;

    public:
        Robot(Vector2 initLoc,float initAngle);

        Vector2 getNearestPointToPath();
        Vector2 getLookAheadPoint();
        float getCurvature();
        void updateVlVr();
        float getVNormHere();











};
