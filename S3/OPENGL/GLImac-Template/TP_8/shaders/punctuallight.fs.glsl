#version 300 es
precision mediump float;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

vec3 blinnPhong() {
  float dist = distance(vPosition_vs,uLightPos_vs);
  return (uLightIntensity/(dist*dist)) * (uKd * dot(normalize(uLightPos_vs-vPosition_vs), vNormal_vs) + uKs * pow((dot((normalize(-vPosition_vs) + normalize(uLightPos_vs)) / 2.0, vNormal_vs)), uShininess));
}
void main() {
  fFragColor=blinnPhong();
};
