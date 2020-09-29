#ifndef VECTORD_HPP
#define VECTORD_HPP

#include <vector>
#include <math.h>
#include <iostream>

class VectorD {

private :
  std::vector<double> data;

public:

  VectorD(const size_t &size=0);
  ~VectorD();
  VectorD(const VectorD &vec);
  //VectorD & operator=(const VectorD &v);

  void displayVector() const; //const empeche la methode de modifier l'objet
  double dot(const VectorD &vec) const;
  const double& operator[](const size_t& i) const;
  double& operator[](const size_t& i);
  VectorD operator+(const VectorD &v) const;
  VectorD operator-(const VectorD &v) const;
  VectorD operator-() const;
  VectorD operator*(const double &a) const;
  inline double norm() const{return sqrt(this->dot(*this));}
  inline size_t size() const{return data.size();}

};

std::ostream& operator<< (std::ostream& stream, const VectorD& v);

#endif
