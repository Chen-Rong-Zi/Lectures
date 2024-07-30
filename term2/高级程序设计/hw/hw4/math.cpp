# include <self/functional.h>
# include <string>

using namespace util;

const double PI = (3.1415926);

class Shape {
public:
    string shape;
    Shape() {
        this->shape = "Shape";
    }
};

class Rectangle : public Shape {
public:
    double length;
    double width;
    Rectangle() { }
    Rectangle(double length) {
        print("调用Rectangle(double)");
        this->shape  = "Rectangle";
        this->length = length;
        this->width  = length;
    }
    Rectangle(double length, double width) {
        print("调用Rectangle(double, double)");
        this->shape  = "Rectangle";
        this->length = length;
        this->width  = width;
    }
    Rectangle(const Rectangle &other) {
        this->length = other.length;
        this->width  = other.width;
    }

    bool is_Square() {
        return this->length == this->width;
    }

    double getArea() {
        return this->length * this->width;
    }
};

class Square : public Rectangle {
public:
    Square(double length) {
        this->length = length;
        this->width  = length;
    }
    Square(const Square &other) {
        this->length = other.length;
        this->width = other.width;
    }
};

class Circle : public Shape {
public:
    double radius;

    Circle(){};

    Circle(double radius) {
        this->shape = "Circle";
        this->radius = radius;
    }

    Circle(const Circle &other) {
        this->radius = other.radius;
    }

    double getArea() {
        return PI * this->radius * this->radius;
    }
};

class Ring : public Circle {
public:
    double small_radius;
    double big_radius;
    Ring(double small_radius, double big_radius) {
        this->small_radius = small_radius;
        this->big_radius   = big_radius;
    }
};

int main(int arg_number, char **arg_value) {
    return 0;
}
