#ifndef VECTORD_HPP
#define VECTORD_HPP

#include <vector>
#include <math.h>

class VectorD {

public:
  std::vector<double> data;

  VectorD(const size_t &size=0);
  ~VectorD();
  VectorD(const VectorD &vec);
  //VectorD & operator=(const VectorD &v);

  void displayVector() const; //const empeche la methode de modifier l'objet
  double dot(const VectorD &vec) const;
  const double& operator[](const size_t& i) const;
  double& operator[](const size_t& i);
  inline double norm() const{return sqrt(this->dot(*this));}

};

#endif
