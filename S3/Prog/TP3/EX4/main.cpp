#include "VectorD.hpp"
#include <iostream>

void plop(const VectorD &vec){
  double a = vec[3];

  for(unsigned int i=0; i<vec.size();i++){
    std::cout << vec[i]<< " ";
  }
}

int main(int argc, char const *argv[]) {

  VectorD vec(5),vec2(5);

  for(size_t i=0;i<vec.size(); i++){
    vec[i]=i;
    vec2[i]=i;
  }

  VectorD vecResPlus = vec + vec2;
  VectorD vecResMoins = vec - vec2;
  VectorD vecResMoinsU = - vec2;
  VectorD vecResMult = vec2*3;

  std::cout << vecResPlus << std::endl;
  std::cout << vecResMoins << std::endl;
  std::cout << vecResMoinsU << std::endl;
  std::cout << vecResMult << std::endl;

  return 0;
}
