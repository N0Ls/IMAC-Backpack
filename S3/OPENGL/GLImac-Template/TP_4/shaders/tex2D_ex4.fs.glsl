#version 300 es
precision mediump float;

in vec2 vVertexTexture;

uniform vec3 uColor;
uniform sampler2D uTexture;

out vec3 fFragColor;

void main() {
  fFragColor=texture(uTexture,vVertexTexture).xyz;
  //fFragColor=uColor;
};
