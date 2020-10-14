#include <iostream>
#include <cctype>

template <typename T>
const T &getMinimum(const T &a, const T &b){
  return a < b ? a : b;
}

//QUESTION 3
template<>
  const char &getMinimum(const char &a, const char &b){
  return std::toupper(a) < std::toupper(b) ? a : b;
}

int main(int argc, char const *argv[]) {

  //QUESTION 1
  //Test ok
  std::cout << getMinimum(79,67) << '\n';
  std::cout << getMinimum(7.9,6.7) << '\n';
  std::cout << getMinimum('a','z') << '\n';


  //QUESTION 2
  //Test pas ok
  //ça ne compile pas à cause d'un pb de type
  //std::cout << getMinimum(7.9,67) << '\n';

  //Solution
  //on force le type de template que on veut
  std::cout << getMinimum<double>(7.9,67) << '\n';

  //QUESTION 3
  std::cout << getMinimum('a','Z') << '\n';

  return 0;
}
