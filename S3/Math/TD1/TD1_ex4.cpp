#include <iostream>
#include <iomanip>

int main()
{
  std::cout << "0.1 + 0.2   = " << 0.1 + 0.2 << std::endl;
  std::cout << std::setprecision(20) << "0.1f + 0.2f = " << 0.1f + 0.2f << std::endl;
  std::cout << std::setprecision(20) << "0.1  + 0.2  = " << 0.1  + 0.2  << std::endl;
  std::cout << std::setprecision(20) << "0.1L + 0.2L = " << 0.1L + 0.2L << std::endl;

  std::cout << std::setprecision(20) << "1.0f + 2.0f = " << 1.0f + 2.0f << std::endl;
  std::cout << std::setprecision(20) << "1.0  + 2.0  = " << 1.0  + 2.0  << std::endl;
  std::cout << std::setprecision(20) << "1.0L + 2.0L = " << 1.0L + 2.0L << std::endl;

  std::cout << std::setprecision(20) << "0.5L + 0.25L = " << 0.5L + 0.25L << std::endl;


  std::cout << std::endl;
  std::cout << std::setprecision(20) << "0.1f - 0.1L = " << 0.1f - 0.1L << std::endl;

  return 0;
}
