#version 300 es
precision mediump float;

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vLocalPosition;

void main() {
  vFragColor = aVertexColor;
  vLocalPosition = aVertexPosition;
  gl_Position = vec4(vec3(aVertexPosition, 1).xy, 0, 1);
};
