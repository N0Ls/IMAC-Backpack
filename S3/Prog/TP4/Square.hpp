#pragma once

#include "Shape.hpp"
#include "Rectangle.hpp"

class Square : public Rectangle{
  public :
    Square();
    Square(const double side);
    ~Square();

    void draw() const override;

    inline void setWidth(const double & width)=delete;
    inline  const  double getWidth () const {return m_width ;}
    inline  void setHeight (const  double& height )=delete;
    inline  const  double getHeight () const {return m_height ;}
    inline void setSide(const double & side) {m_height = side ; m_width=side;};
};
