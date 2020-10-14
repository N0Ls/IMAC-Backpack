#include <iostream>
#include <cctype>
#include "Point3D.hpp"

int main(int argc, char const *argv[]) {

  Point3D<int> p1(1,2,9);
  Point3D<int> p2;

  p2=p1;

  p2=p2+p1;

  std::cout << p2 << '\n';

  return 0;
}
