#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <numeric>

void afficheVector1(const std::vector<int> &vec){

    for(auto it = vec.cbegin(); it < vec.cend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void afficheVector2(const std::vector<int> &vec){

    for(const auto & e :vec )
        std::cout << e << " ";
    std::cout << std::endl;
}


int main(int argc, char **argv) {


  std::vector<int> vec;

  //std::vector<int> vec(42);
  //En spécifiant la taille au constructeur, il alloue la taille et remplie le tableau
  //En faisant push_back, on augmente la capacité à chaque fois en ajoutant un élément
  //Dans ce cas il vaut mieux assigner les valeurs avec vec[i]=i;
  const unsigned int maxElement = 42;
  //vec.reserve(maxElement);

  for(unsigned int i=0; i<maxElement; ++i){
      // std::cout << "iteration : " << i << std::endl;
      // std::cout << "size      : " << vec.size() << std::endl;
      // std::cout << "capacity  : " << vec.capacity() << std::endl << std::endl;
      vec.push_back(i);
      //vec.shrink_to_fit();
  }

  std::vector<int>::iterator it;

  // for (it = vec.begin(); it < vec.end(); it++)
  //   std::cout << *it << " ";
  // std::cout << std::endl;
  //
  //
  // afficheVector1(vec);
  // afficheVector2(vec);

  //-----------EX3
  std::vector<int> vec1 = {21, 2, -5, 7, 10, 42, 3, 7};
  std::cout << "vector initial  : ";
  afficheVector2(vec1);

  std::sort(vec1.begin(),vec1.end());
  std::cout << "vector trié     : ";
  afficheVector2(vec1);

  std::sort(vec1.begin(),vec1.end(),[](const int &a, const int &b){if( (a%2)==(b%2) ) return a<b; else return (a%2 == 0) ? true : false; });
  std::cout << "vector trié pair/impair    : ";
  afficheVector2(vec1);

  std::cout << "nb occurences 7 : " << std::count(vec1.begin(), vec1.end(), 7) << std::endl;

  std::vector<int> vec2 = vec1;
  std::cout << "inner product   : " << std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0) << std::endl;
  std::cout << std::endl;


  //----------EX4
  std::list<std::string> phylosophers   = {"Platon", "Aristote", "Descartes", "Kant"};
  std::list<std::string> mathematicians = {"Gauss", "Laplace", "Poincaré", "Descartes"};

  phylosophers.sort();
std::cout << "phylosophers   : ";
for(const auto &e : phylosophers)
    std::cout << e << " - ";
std::cout << std::endl;

mathematicians.sort();
std::cout << "mathematicians : ";
for(const auto &e : mathematicians)
    std::cout << e << " - ";
std::cout << std::endl;

std::list<std::string> all(mathematicians);
all.merge(phylosophers);
std::cout << "merged         : ";
for(const auto &e : all)
    std::cout << e << " - ";
std::cout << std::endl;

all.unique();
std::cout << "unique         : ";
for(const auto &e : all)
    std::cout << e << " - ";
std::cout << std::endl;


  return 0;
}
