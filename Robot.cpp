#include "Robot.h"
//#include "Path.h"
/*
Robot::Robot(Vector2 initLoc,float initAngle){
    location = initLoc;
    angle = initAngle;
}

Vector2 Robot::getLookAheadPoint(Path p){
    int i = 0;
    float goodt=0 ;
    int goodi=0;
    while(i<(p.length-1)){
      Vector2 e = p[i];
      Vector2 l = p[i+1];
      Vector2 d = Vector2.sub(l,e);
      Vector2 f = Vector2.sub(e,location);
      Vector2 a = d.dot(d);
      float b = 2*f.dot(d);
      floatr c = f.dot(f) - lookDistance*lookDistance;
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
        t= t2 ;
        goodt=t;
        goodi=i;
      }
      }
      i++;
    }

    Vector2 ee = p[goodi];
    Vector2 ll = p[goodi+1];
    Vector2 dd = p5.Vector.sub(ll,ee);
    dd.mult(goodt);
    return Vector2.add(ee,dd)
    
}

float Robot::getCurvature(Vector2 lookp){
    float a = (-1)*tan(angle);
    float b = 1;
    float c = (tan(angle) * location.getX()) - location.getY();
    float xl = abs(a*lookp.getX()+b*lookp.getY() +c)/(sqrt(a*a+b*b));
    float side = (sin(this.angle)*(lookp.getX()-location.getX())-cos(this.angle)*(lookp.getY()-location.getY())) < 0 ? -1:1;
    float curvature = (2*xl/(lookDistance*lookDistance))*side;
    
}

float Robot::getVNormHere(Path p){

}
void Robot::updateVlVr(Path p){
    

    Vector2 lookp = getLookAheadPoint(p);
    float curvature = getCurvature(lookp);
    float vnorm = getVNormHere(p);
    float vr = vnorm*(2-curvature*robotWidth)/2;
    float vl = vnorm*(2+curvature*robotWidth)/2;
}
