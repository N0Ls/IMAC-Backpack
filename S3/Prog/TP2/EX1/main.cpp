#include "VectorD.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

  VectorD v1(5),v2(5);

  v1.data[2] = 42;
  v1.displayVector();

  for(size_t i=0;i<v2.data.size(); i++){
    v2.data[i]=i;
  }

  std::cout << "Norme : " << v1.norm()<<  '\n';
  std::cout << "Dot : " << v1.dot(v2)<< '\n';

  return 0;
}
