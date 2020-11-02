#version 300 es
precision mediump float;

in vec3 vFragColor;
in vec2 vLocalPosition;

out vec3 fFragColor;

void main() {
  float dist = distance(vLocalPosition,vec2(0.0,0.0));
  // float a=
  fFragColor = vFragColor*0.95 * exp(-50.0 * pow(dist, 2.0));
};
