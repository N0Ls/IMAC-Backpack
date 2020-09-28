#include <stdlib.h>
#include <stdio.h>
#include "../include/geometry.h"
#include "../include/colors.h"
int main (int argc, char** argv)
{
  Point3D point1 = createPoint(0,0,0);
  Vector3D vector1 = createVector(1.0,2.0,0.0);
  Vector3D res1=pointPlusVector(point1,vector1);

  Vector3D vector2 = createVector(0.5,1.0,-2.0);
  Vector3D vector3 = createVector(0.2,-1.0,0.0);
  Vector3D res2 = addVectors(vector2,vector3);
  Vector3D res3 = subVectors(vector2,vector3);

  Vector3D res4 = multVector(vector2,2.0);
  Vector3D res5 = multVector(vector2,0.0);

  Vector3D res6 = divVector(vector2, 2.0);
  Vector3D res7 = divVector(vector2, 0.0);

  Vector3D vector4 = createVector(1,0,0);
  Vector3D vector5 = createVector(2,0,0);
  Vector3D vector6 = createVector(0,1,0);
  float res8 = dot(vector4, vector5);
  float res9 = dot(vector4, vector6);

  float res10 = norm(vector5);
  float res11 = norm(createVector(1.0,1.0,1.0));


  printVector3D(res1);
  printVector3D(res2);
  printVector3D(res3);
  printVector3D(res4);
  printVector3D(res5);
  printVector3D(res6);
  printVector3D(res7);
  printf("Produit scalaire : %.2f\n",res8 );
  printf("Produit scalaire : %.2f\n",res9 );
  printf("Produit scalaire : %.2f\n",res10 );
  printf("Produit scalaire : %.2f\n",res11);
  printVector3D(normalize(createVector(1,1,1)));
  printVector3D(normalize(createVector(0,0,0)));

return EXIT_SUCCESS;
}
