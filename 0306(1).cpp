#include <vector>
#include <memory>
#include <iostream>
#include <cassert>

class Shape {
public:
  virtual ~Shape() = default;
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
};

class Triangle final : public Shape {
private:
  double side1, side2, side3;

public:
  Triangle(double s1, double s2, double s3)
      : side1(s1), side2(s2), side3(s3) {}

  double perimeter() const override final {
    return side1 + side2 + side3;
  }

  double area() const override final {
    double p = perimeter() / 2;
    return std::pow((p * (p - side1) * (p - side2) * (p - side3)), 0.5);
  }
};

class Square final : public Shape {
private:
  double side;

public:
  Square(double s) : side(s) {}

  double perimeter() const override final {
    return 4 * side;
  }

  double area() const override final {
    return side * side;
  }
};

class Circle final : public Shape {
private:
  double radius;

public:
  Circle(double r) : radius(r) {}

  double perimeter() const override final {
    return 2 * 3.14 * radius;
  }

  double area() const override final {
    return 3.14 * radius * radius;
  }
};

void test_triangle(Triangle t) {
  assert(t.area() == 6);
  assert(t.perimeter() == 12);
}

void test_circle(Circle c) {
  assert(c.perimeter() == 2);
  assert(c.area() == 1 / 3.14);
}

void test_square(Square s) {
  assert(s.perimeter() == 12);
  assert(s.area() == 9);
}


int main() {
  int side1 = 3;
  int side2 = 4;
  int side3 = 5;

  double radius = 1 / 3.14;

  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.push_back(std::make_unique<Triangle>(side1, side2, side3));
  shapes.push_back(std::make_unique<Circle>(radius));
  shapes.push_back(std::make_unique<Square>(side1));

  auto triangle = dynamic_cast<Triangle*>(shapes[0].get());
  test_triangle(*triangle);

  auto circle = dynamic_cast<Circle*>(shapes[1].get());
  test_circle(*circle);

  auto square = dynamic_cast<Square*>(shapes[2].get());
  test_square(*square);

  return 0;
}
