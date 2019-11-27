#include "Robot.h"
#include <cmath>

Robot::Robot(Vector2f initLoc,float initAngle){
    location = initLoc;
    angle = initAngle;
}

Vector2f Robot::getLookAheadPoint(PathSmoother ps){
    int i = 0;
    float goodt=0 ;
    int goodi=0;
    vector<PointS> p = ps.getSPath();
    while(i<(p.size()-1)){
    
      Vector2f d = p[i+1].toV2f()-p[i].toV2f();
      Vector2f f = p[i].toV2f()-location;
      float a = dot(d,d);
      float b = 2*dot(f,d);
      float c = dot(f,f) - lookDistance*lookDistance;
      float discriminant = b*b - 4*a*c;
      float t = 0;
      if (discriminant < 0) {
      }else{
        discriminant = sqrt(discriminant);
        float t1 = (-b - discriminant)/(2*a);
        float t2 = (-b + discriminant)/(2*a);
        if (t1 >= 0 && t1 <=1){
          t = t1;
          goodt = t;
          goodi = i;
        }
        if (t2 >= 0 && t2 <=1){
          t = t2 ;
          goodt = t;
          goodi = i;
        }
      }
      i++;
    }


    Vector2f dd = p[goodi+1].toV2f()-p[goodi].toV2f();
    Vector2f facteur(goodt,goodt);
    Vector2f gg = (facteur*dd) + p[goodi].toV2f();
    return gg;
    
}

float Robot::getCurvature(Vector2f lookp){
    float a = (-1)*tan(angle);
    float b = 1;
    float c = (tan(angle) * location.getX()) - location.getY();
    float xl = abs(a*lookp.getX()+b*lookp.getY() +c)/(sqrt(a*a+b*b));
    float side = (sin(angle)*(lookp.getX()-location.getX())-cos(angle)*(lookp.getY()-location.getY())) < 0 ? -1:1;
    float curvature = (2*xl/(lookDistance*lookDistance))*side;
    return curvature;
    
}
PointS Robot::getNearestPoint(PathSmoother ps){
    vector<PointS> p = ps.getSPath();
    float lastd = distance(location,p[0].toV2f());
    PointS point = p[0];
    int i = 0;
    while(i<(p.size()-1)){

      if(distance(location,p[i].toV2f())<lastd){
        lastd = distance(location,p[i].toV2f);
        point = p[i];
      }
      i++;
    }
    return point;
}
float Robot::getVNormHere(PathSmoother ps){
    return getNearestPoint(ps).getZ; 
}

void Robot::updateVlVr(PathSmoother p){
    Vector2f lookp = getLookAheadPoint(p);
    float curvature = getCurvature(lookp);
    float vnorm = getVNormHere(p);
    float vr = vnorm*(2-curvature*robotWidth)/2;
    float vl = vnorm*(2+curvature*robotWidth)/2;
}


