#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
  double u_0 = 1.0/3.0;
  double next;
  double previous;

  previous = u_0;
  for (int i = 0; i < 100; i++) {
    next = 4*previous - 1;
    std::cout << std::setprecision(20)<< next << std::endl;

    previous = next;
  }
  return 0;
}
