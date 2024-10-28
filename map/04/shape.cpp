#include "shape.h"
#include <cmath>
#include <string>

Line::Line(int _x1, int _y1, int _x2, int _y2)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

void Line::shift(int dx, int dy, int dz) {
  x1 += dx;
  y1 += dy;
  x2 += dx;
  y2 += dy;
}

void Line::scale(int factorX, int factorY, int factorZ) {
  x1 *= factorX;
  y1 *= factorY;
  x2 *= factorX;
  y2 *= factorY;
}

Square::Square(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4,
               int _y4)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4) {}

double Square::area() const { return std::abs(x1 - x2) * std::abs(y1 - y2); }

void Square::shift(int dx, int dy, int dz) {
  x1 += dx;
  y1 += dy;
  x2 += dx;
  y2 += dy;
  x3 += dx;
  y3 += dy;
  x4 += dx;
  y4 += dy;
}

void Square::scale(int factorX, int factorY, int factorZ) {
  x1 *= factorX;
  y1 *= factorY;
  x2 *= factorX;
  y2 *= factorY;
  x3 *= factorX;
  y3 *= factorY;
  x4 *= factorX;
  y4 *= factorY;
}

Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3,
           int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5,
           int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7,
           int _x8, int _y8, int _z8)
    : x1(_x1), y1(_y1), z1(_z1), x2(_x2), y2(_y2), z2(_z2), x3(_x3), y3(_y3),
      z3(_z3), x4(_x4), y4(_y4), z4(_z4), x5(_x5), y5(_y5), z5(_z5), x6(_x6),
      y6(_y6), z6(_z6), x7(_x7), y7(_y7), z7(_z7), x8(_x8), y8(_y8), z8(_z8) {}

double Cube::area() const {
  int a = std::abs(x1 - x2);
  int b = std::abs(y1 - y2);
  int c = std::abs(z1 - z2);
  return 2 * (a * b + a * c + b * c);
}

double Cube::volume() const {
  int a = std::abs(x1 - x2);
  int b = std::abs(y1 - y2);
  int c = std::abs(z1 - z2);
  return a * b * c;
}

void Cube::shift(int dx, int dy, int dz) {
  x1 += dx;
  y1 += dy;
  z1 += dz;
  x2 += dx;
  y2 += dy;
  z2 += dz;
  x3 += dx;
  y3 += dy;
  z3 += dz;
  x4 += dx;
  y4 += dy;
  z4 += dz;
  x5 += dx;
  y5 += dy;
  z5 += dz;
  x6 += dx;
  y6 += dy;
  z6 += dz;
  x7 += dx;
  y7 += dy;
  z7 += dz;
  x8 += dx;
  y8 += dy;
  z8 += dz;
}

void Cube::scale(int factorX, int factorY, int factorZ) {
  x1 *= factorX;
  y1 *= factorY;
  z1 *= factorZ;
  x2 *= factorX;
  y2 *= factorY;
  z2 *= factorZ;
  x3 *= factorX;
  y3 *= factorY;
  z3 *= factorZ;
  x4 *= factorX;
  y4 *= factorY;
  z4 *= factorZ;
  x5 *= factorX;
  y5 *= factorY;
  z5 *= factorZ;
  x6 *= factorX;
  y6 *= factorY;
  z6 *= factorZ;
  x7 *= factorX;
  y7 *= factorY;
  z7 *= factorZ;
  x8 *= factorX;
  y8 *= factorY;
  z8 *= factorZ;
}

Circle::Circle(int _x1, int _y1, double _radius)
    : x1(_x1), y1(_y1), radius(_radius) {}

double Circle::area() const { return M_PI * radius * radius; }

void Circle::shift(int dx, int dy, int dz) {
  x1 += dx;
  y1 += dy;
}

void Circle::scale(int factorX, int factorY, int factorZ) {
  radius *= std::sqrt(factorX * factorY);
}

Cylinder::Cylinder(int _x1, int _y1, double _radius, double _height)
    : x1(_x1), y1(_y1), radius(_radius), height(_height) {}

double Cylinder::area() const { return 2 * M_PI * radius * (radius + height); }

double Cylinder::volume() const { return M_PI * radius * radius * height; }

void Cylinder::shift(int dx, int dy, int dz) {
  x1 += dx;
  y1 += dy;
}

void Cylinder::scale(int factorX, int factorY, int factorZ) {
  radius *= std::sqrt(factorX * factorY);
  height *= factorZ;
}
