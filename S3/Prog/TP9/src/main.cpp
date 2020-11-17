#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>

double pow1(const double &x, const unsigned int n){
  if (n != 0)
    return (x * pow1(x, n - 1));
else
    return 1;
}

template<typename Type>
Type pow2(const Type &x, const unsigned int n){
  if(n==0) return static_cast<Type>(1);
  else return x * pow2<Type>(x,n-1);
}

constexpr double pow3(const double &x, const unsigned int n){
  return (n==0) ? 1 : x*pow3(x,n-1);
}

template<typename T>
constexpr T pow4(const T &x, const unsigned int n){
  return (n==0) ? static_cast<T>(1) : x*pow4<T>(x,n-1);
}

template<typename T>
T product(const T &v) {
  return v;
}
template<typename T, typename... Types>
T product(const T &var, const Types... args){
  return var * product(args...);
}

template<typename T>
T selfProduct(const std::vector<T> &vec){
  T res = static_cast<T>(1);
  for(const auto &v : vec)
      res *= v;
  return res;
}

template<typename T>
T selfProduct2(const std::vector<T> &vec){
  T res = static_cast<T>(1);
  std::for_each(vec.begin(), vec.end(),[&res](T const &m){
      res*=m;
  });
  return res;
}

template<typename T>
T selfProduct3(const std::vector<T> &vec){
  return std::accumulate(vec.begin(), vec.end(), static_cast<T>(1), std::multiplies<T>());
}

template<typename T>
std::vector<T> generateVector(const unsigned int size){
    std::vector<T> vec(size);
    T value = static_cast<T>(1);
    std::generate(vec.begin(), vec.end(), [&value] { return value++; });
    return vec;
}


int main(int argc, char const *argv[]) {
  std::cout << pow1(2,3) << '\n';
  std::cout << pow2(2,3) << '\n';
  std::cout << pow3(2,3) << '\n';
  std::cout << pow4(2,3) << '\n';
  std::cout << product<double>(2,2,2) << '\n';

  std::vector<int> v = {1,2,3,4,5};
  std::vector<int> v2 = generateVector<int>(20);
  std::cout << selfProduct(v) << '\n';

  std::cout << selfProduct2(v) << '\n';

  std::cout << selfProduct3(v) << '\n';


  return 0;
}
