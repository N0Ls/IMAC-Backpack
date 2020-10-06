#pragma once

class Shape {
private:
  /* data */

public:

  virtual ~Shape (){};
  virtual void draw() const = 0;
  virtual double surface() const = 0;

};
