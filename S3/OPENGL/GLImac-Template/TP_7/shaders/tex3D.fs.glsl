#version 300 es
precision mediump float;

uniform sampler2D uTexture;

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

void main() {
  fFragColor=texture(uTexture,vTexCoords).xyz;
};
