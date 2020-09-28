#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/raytracer.h"
#include "../include/geometry.h"


Ray createRay(float pX, float pY, float pZ, float dX, float dY, float dZ){
  Ray ray;
  ray.origine = createPoint(pX,pY,pZ);
  ray.direction = createVector(dX,dY,dZ);

  return ray;
}

int intersectsSphere(Ray r, Sphere s, Intersection* intersection, float* t){
  float a = pow(r.direction.x,2) + pow(r.direction.y,2) + pow(r.direction.z,2);
  float b = 2*(r.direction.x *(r.origine.x-s.origine.x) + r.direction.y * (r.origine.y-s.origine.y)+ r.direction.z * (r.origine.z-s.origine.z));
  float c = pow(r.origine.x-s.origine.x,2) + pow(r.origine.y-s.origine.y,2) + pow(r.origine.z-s.origine.z,2) - pow(s.radius,2);

  float determinant = pow(b,2) - 4 * a * c;
  printf("a = %f ,b= %f, c= %f \n", a,b,c);
  if(determinant < 0 ){
    return 0;
  }
  //jusque là ok
  else{
    float racine1 = -b + sqrt(determinant) / (2*a);
    float racine2 = -b - sqrt(determinant) / (2*a);
    float racine_finale;

    if((racine1 > 0 && racine1 < racine2) || (racine1 > 0 && racine2 < 0)){
      racine_finale = racine1;
    }
    else{
      racine_finale = racine2;
    }
    Point3D point_inter = createPoint(r.direction.x*racine_finale+r.origine.x,r.direction.y*racine_finale+r.origine.y ,r.direction.z*racine_finale+r.origine.z);
    *t = racine_finale;
    intersection->position = point_inter;
    intersection->couleur = s.couleur;
    return 1;
  }
}
