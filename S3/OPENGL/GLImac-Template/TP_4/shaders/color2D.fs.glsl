#version 300 es
precision mediump float;

in vec3 vFragColor;
in vec2 vLocalPosition;

out vec3 fFragColor;

void main() {
  float dist = distance(vLocalPosition,vec2(0.0,0.0));

  //Particule
  //fFragColor = vFragColor*0.95 * exp(-50.0 * pow(dist, 2.0));

  //Procedural
  //fFragColor = vFragColor*length(fract(5.0 * vLocalPosition));
  //fFragColor = vFragColor*length(fract(5.0 * dist));
  //fFragColor = vFragColor*length(abs(fract(5.0 * vLocalPosition) * 2.0 - 1.0));
  //fFragColor = vFragColor*length(abs(fract(5.0 * dist) * 2.0 - 1.0));
  //fFragColor = vFragColor*mod(floor(10.0 * vLocalPosition.x) + floor(10.0 * vLocalPosition.y), 2.0);
  //fFragColor = vFragColor*smoothstep(0.3, 0.32, length(fract(5.0 * vLocalPosition) - 0.5));
  fFragColor = vFragColor*smoothstep(0.4, 0.5, max(abs(fract(8.0 * vLocalPosition.x - 0.5 * mod(floor(8.0 * vLocalPosition.y), 2.0)) - 0.5), abs(fract(8.0 * vLocalPosition.y) - 0.5)));
};
