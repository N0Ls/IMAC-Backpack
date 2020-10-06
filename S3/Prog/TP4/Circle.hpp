#pragma once

#include "Shape.hpp"

class Circle : public Shape{
  protected :
    double m_radius;
  public :
    Circle();
    Circle(const double radius);
    ~Circle();

    double surface() const override;
    void draw() const override;
};
