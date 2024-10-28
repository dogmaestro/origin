#pragma once
#include <cmath>
#include <string>

class Shape {
public:
  virtual ~Shape() = default;
  virtual double area() const = 0;
  virtual double volume() const = 0;
  virtual void shift(int dx, int dy, int dz) = 0;
  virtual void scale(int factorX, int factorY, int factorZ) = 0;
  virtual void scale(int factor) { scale(factor, factor, factor); }
  virtual void scaleX(int factor) { scale(factor, 1, 1); };
  virtual void scaleY(int factor) { scale(1, factor, 1); };
  virtual void scaleZ(int factor) { scale(1, 1, factor); };
};

class Line : public Shape {
public:
  Line(int x1, int y1, int x2, int y2);
  double area() const override { return 0; }
  double volume() const override { return 0; }
  void shift(int dx, int dy, int dz = 0) override;
  void scale(int factorX, int factorY, int factorZ = 1) override;

private:
  int x1, y1, x2, y2;
};

class Square : public Shape {
public:
  Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
  double area() const override;
  double volume() const override { return 0; }
  void shift(int dx, int dy, int dz = 0) override;
  void scale(int factorX, int factorY, int factorZ = 1) override;

private:
  int x1, y1, x2, y2, x3, y3, x4, y4;
};

class Cube : public Shape {
public:
  Cube(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3,
       int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6,
       int x7, int y7, int z7, int x8, int y8, int z8);
  double area() const override;
  double volume() const override;
  void shift(int dx, int dy, int dz) override;
  void scale(int factorX, int factorY, int factorZ) override;

private:
  int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6,
      x7, y7, z7, x8, y8, z8;
};

class Circle : public Shape {
public:
  Circle(int x1, int y1, double radius);
  double area() const override;
  double volume() const override { return 0; }
  void shift(int dx, int dy, int dz = 0) override;
  void scale(int factorX, int factorY, int factorZ = 1) override;

private:
  int x1, y1;
  double radius;
};

class Cylinder : public Shape {
public:
  Cylinder(int x1, int y1, double radius, double height);
  double area() const override;
  double volume() const override;
  void shift(int dx, int dy, int dz = 0) override;
  void scale(int factorX, int factorY, int factorZ) override;

private:
  int x1, y1;
  double radius, height;
};