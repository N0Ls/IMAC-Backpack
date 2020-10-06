#pragma once

#include "Shape.hpp"

class Rectangle : public Shape{
  protected :
    double m_width;
    double m_height;
  public :
    Rectangle();
    Rectangle(const double width, const double height);
    ~Rectangle();

    double surface() const override;
    void draw() const override;

    inline void setWidth(const double & width){m_width = width;}
    inline  const  double getWidth () const {return m_width ;}
    inline  void setHeight (const  double& height ){m_height = height ;}
    inline  const  double getHeight () const {return m_height ;}
};
