#include "VectorD.hpp"
#include <iostream>

void plop(const VectorD &vec){
  double a = vec[3];

  for(unsigned int i=0; i<vec.data.size();i++){
    std::cout << vec[i]<< " ";
  }
}

int main(int argc, char const *argv[]) {

  VectorD vec(5);

  vec[3] = 42;
  vec.displayVector();

  for(size_t i=0;i<vec.data.size(); i++){
    vec[i]=i;
  }
  vec.displayVector();

  double x = vec[3];

  //On force le test en const
  plop(vec);

  //
  // std::cout << "Norme : " << v1.norm()<<  '\n';
  // std::cout << "Dot : " << v1.dot(v2)<< '\n';



  return 0;
}
