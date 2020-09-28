#include <iostream>
#include <iomanip>

int multiplicationRusse(int a,int b){
  int rest = 0 ;
  int res = 0;
  int signe = 1;
  if(b==0 || a==0){
    return 0;
  }
  if(a<0){
    signe = -signe;
    a = -a;
  }
  if(b<0){
    signe = -signe;
    b=-b;
  }
  if(b > a){
    std::swap(b,a);
  }
  while(a > 1){
    if(a%2==0){
      a = a>>1;
      b = b<<1;
    }
    else{
      rest += b;
      a = a>>1;
      b = b<<1;
    }
  }
  res = b + rest;
  return res;
}

int main(int argc, char const *argv[]) {
  std::cout << multiplicationRusse(atof(argv[1]),atof(argv[2])) << '\n';
}
