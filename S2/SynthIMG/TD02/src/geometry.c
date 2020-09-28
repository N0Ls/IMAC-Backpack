#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/geometry.h"

// Construit le point (x, y, z)
Point3D createPoint(float x, float y, float z){
  Point3D point;
  point.x = x;
  point.y = y;
  point.z = z;

  return point;
}
// Construit le vecteur (x, y, z)
Vector3D createVector(float x, float y, float z){
  Vector3D vector;
  vector.x = x;
  vector.y = y;
  vector.z = z;

  return vector;
}
// Construit le vecteur reliant les points P1 et P2
Vector3D createVectorFromPoints(Point3D p1, Point3D p2){
  Vector3D vector;
  vector.x = p2.x - p1.x;
  vector.y = p2.y - p1.y;
  vector.z = p2.z - p1.z;

  return vector;
}
// Construit le point P + V (i.e. translation de P par V)
Point3D pointPlusVector(Point3D p, Vector3D v){
  Point3D point;
  point.x = p.x+v.x;
  point.y = p.y+v.y;
  point.z = p.z+v.z;

  return point;
}
// Addition et soustraction des vecteurs V1 et V2
Vector3D addVectors(Vector3D v1, Vector3D v2){
  Vector3D vector;
  vector.x = v1.x+v2.x;
  vector.y = v1.y+v2.y;
  vector.z = v1.z+v2.z;

  return vector;
}
Vector3D subVectors(Vector3D v1, Vector3D v2){
  Vector3D vector;
  vector.x = v2.x-v1.x;
  vector.y = v2.y-v1.y;
  vector.z = v2.z-v1.z;

  return vector;
}
// Multiplication et division d'un vecteur V par un scalaire a
Vector3D multVector(Vector3D v, float a){
  Vector3D vector;
  vector.x = v.x * a ;
  vector.y = v.y * a ;
  vector.z = v.z * a ;

  return vector;
}
Vector3D divVector(Vector3D v, float a){
  Vector3D vector;
  vector.x = v.x / a ;
  vector.y = v.y / a ;
  vector.z = v.z / a ;

  return vector;
}
// Produit scalaire des vecteurs V1 et V2
float dot(Vector3D a, Vector3D b){
  return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
}

// Norme d'un vecteur V
float norm(Vector3D v){
  return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
}
// // Construit le vecteur normalisé du vecteur V
Vector3D normalize(Vector3D v){
  return multVector(v,1/norm(v));
}

void printPoint3D(Point3D p){
  printf("Pour ce point, on a : x=%.2f, y=%.2f, z=%.2f\n",p.x,p.y,p.z);
}

void printVector3D(Vector3D v){
  printf("Pour ce vecteur, on a : x=%.2f, y=%.2f, z=%.2f\n",v.x,v.y,v.z);
}
