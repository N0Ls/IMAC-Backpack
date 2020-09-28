#ifndef SPHERE_H
#define SPHERE_H

#include "../include/geometry.h"
#include "../include/colors.h"

typedef struct Sphere{
  Point3D origine;
  float radius;
  ColorRGB couleur;
}Sphere;

Sphere createSphere(float pX, float pY, float pZ, float r, float g, float b, float radius);

#endif
