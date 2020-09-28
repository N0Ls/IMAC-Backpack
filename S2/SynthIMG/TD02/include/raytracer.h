#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "../include/geometry.h"
#include "../include/colors.h"
#include "../include/sphere.h"

typedef struct Ray{
  Point3D origine;
  Vector3D direction;
}Ray;

typedef struct Intersection{
  Point3D position;
  ColorRGB couleur;
}Intersection;

Ray createRay(float pX, float pY, float pZ, float dX, float dY, float dZ);
int intersectsSphere(Ray r, Sphere s, Intersection* intersection, float* t);

#endif
