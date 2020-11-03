#version 300 es
precision mediump float;

in vec3 vFragColor;
in vec2 vLocalPosition;

out vec3 fFragColor;

vec2 complexSqr(vec2 z){
  return vec2(pow(z.x,2.0)-pow(z.y,2.0),2.0*z.x*z.y);
}

void main() {
  vec2 cplx = vec2(vLocalPosition.x,vLocalPosition.y);
  vec2 current = cplx;
  int i=0;
  int n_Max = 100;
  while(i<n_Max && length(current)<2.0){
    current = complexSqr(current) + cplx;
    i++;
  }
  if(i==n_Max){
      fFragColor = vec3(0.0,0.0,0.0);
  }
  else{
      fFragColor = vec3(0.8*float(i) / float(n_Max),1.2*float(i) / float(n_Max),float(i) / float(n_Max));
  }

};
