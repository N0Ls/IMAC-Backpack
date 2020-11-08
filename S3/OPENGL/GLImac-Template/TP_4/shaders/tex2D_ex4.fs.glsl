#version 300 es
precision mediump float;

uniform sampler2D uTexture;
in vec2 vVertexTexture;
out vec3 fFragColor;

void main() {
  fFragColor=texture(uTexture,vVertexTexture).xyz;
};
