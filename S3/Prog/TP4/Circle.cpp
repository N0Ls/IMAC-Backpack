#include <iostream>
#include "Circle.hpp"

Circle::Circle():m_radius(0){};
Circle::Circle(const double radius):m_radius(radius){};
Circle::~Circle(){};

double Circle::surface() const {
  return 3.14*m_radius*m_radius;
}
void Circle::draw() const {
  std::cout << "-- circle " << this->surface()<< std::endl ;
}
