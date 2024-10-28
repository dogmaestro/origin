#include "shape.h"
#include <iostream>

int main() {
  Shape *shapes[5];

  shapes[0] = new Line{10, 20, 30, 50};
  shapes[1] = new Square{10, 20, 30, 50, 60, 30, 50, 60};
  shapes[2] = new Cube{10, 20, 50, 60, 10, 20, 50, 60, 50, 60, 10, 20,
                       50, 60, 10, 20, 50, 60, 50, 60, 50, 60, 50, 60};
  shapes[3] = new Circle{10, 20, 30};
  shapes[4] = new Cylinder{10, 20, 30., 40.};

  for (int i = 0; i < 5; i++) {
    shapes[i]->shift(1, 2, 3);
    shapes[i]->scaleX(1);
    shapes[i]->scaleX(2);
    shapes[i]->scaleX(3);
    delete shapes[i];
  }

  return 0;
}