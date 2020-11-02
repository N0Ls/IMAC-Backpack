#version 300 es
precision mediump float;

in vec3 vFragColor;

out vec3 fFragColor;

void main() {

  float M = dot(vFragColor.rgb, vec3(0.299, 0.587, 0.114));
  fFragColor = vec3(M, M , M);
};
