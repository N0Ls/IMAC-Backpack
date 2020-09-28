#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/sphere.h"
#include "../include/geometry.h"

Sphere createSphere(float pX, float pY, float pZ, float r, float g, float b, float radius){
  Sphere sphere;
  sphere.origine = createPoint(pX,pY,pZ);
  sphere.radius = radius;
  sphere.couleur = createColor(r,g,b);


  return sphere;
}
