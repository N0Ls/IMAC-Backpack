#include "VectorD.hpp"
#include <iostream>
#include <math.h>

VectorD::VectorD(const size_t &size)
:data(size)
{
}

VectorD::~VectorD(){}

VectorD::VectorD(const VectorD &vec)
:data(vec.data)
{
}

void VectorD::displayVector() const{
  for(size_t i=0;i<data.size(); i++){
    std::cout<<data[i]<<std::endl;
  }
}

// VectorD & VectorD::operator=(const VectorD &v){
//   if(&v==this)return *this;
//
//   _data = v.data;
//
//   return *this;
// }

const double& VectorD::operator[](const size_t& i) const{
  return data[i];
}

double& VectorD::operator[](const size_t& i){
  return data[i];
}

double VectorD::dot(const VectorD &vec) const{
  if (this->data.size() != vec.data.size()) {
    std::cout << "Problème de taille de vecteur" << '\n';
    return 0;
  }
  double sum=0;
  for(size_t i=0;i<data.size(); i++){
    sum += this->data[i] * vec.data[i];
  }
  return sum;
}
