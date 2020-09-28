#include <iostream>
int main(int argc, char const *argv[]) {

  int u_input;

  std::cout << "Entrez un entier" << std::endl;
  std::cin >> u_input;

  if(u_input == 42){
    std::cout << "Parfait" << std::endl;
  }
  else if(u_input <= 0){
    std::cout << "Négatif" << std::endl;
  }
  else{
    std::cerr << "Strictement positif" << std::endl;
  }
  return 0;
}
