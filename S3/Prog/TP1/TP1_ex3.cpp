#include <iostream>
int main(int argc, char const *argv[]) {

  std::string u_input;

  std::cout << "Entrez une chaîne de caractères" << std::endl;
  std::cin >> u_input;

  std::cout << "Taille de la chaîne de caractères : " <<u_input.size() << "\nDernier caractère : " << u_input.back() << std::endl;

  //u_input.pop_back();

  std::cout << u_input << std::endl;

  //u_input.insert(0, "IMAC");
  for (int y = 0; y < (int)u_input.size()/2; y++) {
    std::swap(u_input[y],u_input[u_input.size()-y-1]);
  }
  std::cout << u_input << std::endl;


  return 0;
}
