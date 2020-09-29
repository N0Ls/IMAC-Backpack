#include "VectorD.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>

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

VectorD VectorD::operator+(const VectorD &v) const{
  if(v.size() != this->size()){
    std::cerr << "error : VectorD::operator+: operand with incompatible size" << std::endl;
    return *this;
  }

  VectorD result(size());
  for (size_t i = 0; i < size(); i++) {
    result[i]= data[i] + v[i];
  }
  //Version avancée --- #include <algorithm>
  //std::transform(data.begin(), data.begin()+size(),v.data.begin(),result.data.begin(),std::plus<double>());
  return result;
}

VectorD VectorD::operator-(const VectorD &v) const{
  if(v.size() != this->size()){
    std::cerr << "error : VectorD::operator+: operand with incompatible size" << std::endl;
    return *this;
  }

  VectorD result(size());
  for (size_t i = 0; i < size(); i++) {
    result.data[i]= data[i] - v[i];
  }
  return result;
}

VectorD VectorD::operator-() const{
  VectorD result(size());
  for (size_t i = 0; i < size(); i++) {
    result.data[i]= -data[i];
  }
  return result;
}

VectorD VectorD::operator*(const double &a) const{
  VectorD result(size());
  for (size_t i = 0; i < size(); i++) {
    result.data[i]= data[i]*a;
  }
  return result;
}

std::ostream& operator<< (std::ostream& stream, const VectorD& v){
  if(v.size()==0){
    stream << "Not initialized yet -> size is 0";
    return stream;
  }
  stream << "(";
  for(unsigned int i=0; i<v.size()-1;++i){
    stream << v[i] << ", ";
  }
  stream << v[v.size()-1] << ")";

  return stream;
}
