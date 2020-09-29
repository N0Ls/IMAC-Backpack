#include "VectorD.hpp"
#include <iostream>

void plop(const VectorD &vec){
  double a = vec[3];

  for(unsigned int i=0; i<vec.size();i++){
    std::cout << vec[i]<< " ";
  }
}

int main(int argc, char const *argv[]) {

  VectorD vec(5);

  //NE FONCTIONNE PLUS MTN car privé
  //vec.data[3] = 42;
  vec[3]=42;
  vec.displayVector();

  //vec.data.size() ne fonctionne plus
  for(size_t i=0;i<vec.size(); i++){
    vec[i]=i;
  }
  vec.displayVector();

  return 0;
}
