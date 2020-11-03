#version 300 es
precision mediump float;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vLocalPosition;

mat3 translate(float tx, float ty){
  return mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
}

mat3 scale(float tx, float ty){
  return mat3(vec3(tx, 0, 0), vec3(0, ty, 0), vec3(0, 0, 1));
}

mat3 rotate(float a){
  float angle = radians(a);
  return mat3(vec3(cos(angle),sin(angle), 0), vec3(-sin(angle),cos(angle), 0), vec3(0, 0, 1));
}



void main() {
  vFragColor = aVertexColor;
  vLocalPosition = aVertexPosition;
  gl_Position = vec4(vec3(aVertexPosition, 1).xy, 0, 1);


  //gl_Position = vec4((vec3(aVertexPosition, 1)).xy, 0, 1);
};
