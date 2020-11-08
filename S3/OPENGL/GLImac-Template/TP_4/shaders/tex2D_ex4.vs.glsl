#version 300 es
precision mediump float;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTexture;
//uniform float uTime;
uniform mat3 uModelMatrix;

out vec2 vVertexTexture;

mat3 rotate(float a){
  float angle = radians(a);
  return mat3(vec3(cos(angle),sin(angle), 0), vec3(-sin(angle),cos(angle), 0), vec3(0, 0, 1));
}

void main() {
  vVertexTexture=aVertexTexture;
  gl_Position = vec4((uModelMatrix*vec3(aVertexPosition, 1)).xy, 0, 1);
};
