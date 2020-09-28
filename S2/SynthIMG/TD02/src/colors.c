#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/colors.h"
// Construit la couleur (r, g, b)
ColorRGB createColor(float r, float g, float b){
  ColorRGB color;
  color.r=r;
  color.g=g;
  color.b=b;

  return color;
}
// Addition, soustraction et multiplication des couleurs C1 et C2
ColorRGB addColors(ColorRGB c1, ColorRGB c2){
  ColorRGB color;
  color.r=c1.r+c2.r;
  color.g=c1.g+c2.g;
  color.b=c1.b+c2.b;

  return color;
}

ColorRGB subColors(ColorRGB c1, ColorRGB c2){
  ColorRGB color;
  color.r=c2.r-c1.r;
  color.g=c2.g-c1.g;
  color.b=c2.b-c1.b;

  return color;
}

ColorRGB multColors(ColorRGB c1, ColorRGB c2){
  ColorRGB color;
  color.r=c1.r*c2.r;
  color.g=c1.g*c2.g;
  color.b=c1.b*c2.b;

  return color;
}
// Multiplication et division d une couleur C par un scalaire a
ColorRGB multColor(ColorRGB c, float a){
  ColorRGB color;
  color.r=c.r*a;
  color.g=c.g*a;
  color.b=c.b*a;
  return color;
}
ColorRGB divColor(ColorRGB c, float a){
  ColorRGB color;
  color.r=c.r/a;
  color.g=c.g/a;
  color.b=c.b/a;
  return color;
}
