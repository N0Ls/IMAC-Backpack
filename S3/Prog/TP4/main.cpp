#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include <iostream>
#include <vector>

void plop(const Shape &shape){
  shape.draw();
}

int main(int argc, char const *argv[]) {
  Circle c(2);
  c.draw();

  Rectangle r(4,5);
  r.draw();
  r.setHeight(10);
  r.draw();

  Square s(5);
  s.draw();
  s.setSide(6);
  s.draw();

  std::cout << "Test avec plop" << std::endl;

  plop(c);
  plop(r);
  plop(s);

  std::vector<Shape *> shapes;

  for(size_t i=0; i<3; i++) shapes.push_back(new Rectangle(i,i+1));
  for(size_t i=0; i<3; i++) shapes.push_back(new Square(i));
  for(size_t i=0; i<3; i++) shapes.push_back(new Circle(i));

  for(size_t i=0; i<shapes.size(); i++) plop(*shapes[i]);

  for(size_t i=0; i<shapes.size(); i++) free(shapes[i]);


  return 0;
};
