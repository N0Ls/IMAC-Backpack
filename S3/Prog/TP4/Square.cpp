#include <iostream>
#include "Square.hpp"
#include "Rectangle.hpp"

Square::Square(){m_width=0;m_height=0;};
Square::Square(const double side){m_width=side;m_height=side;};
Square::~Square(){};

void Square::draw() const {
  std::cout << "-- square " << this->surface()<< std::endl ;
}
