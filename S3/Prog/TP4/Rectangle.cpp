#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle():m_width(0), m_height(0){};
Rectangle::Rectangle(const double width, const double height):m_width(width), m_height(height){};
Rectangle::~Rectangle(){};

double Rectangle::surface() const {
  return m_width*m_height;
}
void Rectangle::draw() const {
  std::cout << "-- rectangle " << this->surface()<< std::endl ;
}
