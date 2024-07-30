# include <iostream>
using namespace std;

class A {
   int x;

public:
   A() : x(0) { std::cout << "A" << std::endl; }
   A(int i) : x(i) { std::cout << "A" << x << std::endl; }
   ~A() { std::cout << "~A" << x << std::endl; }
};

class B {
   A a;
   int y;

public:
   B() : y(0) { std::cout << "B" << std::endl; }
   B(int i) : y(i) { std::cout << "B" << y << std::endl; }
   B(int i, int j) : a(j), y(i) { std::cout << "B" << y << std::endl; }
   ~B() { std::cout << "~B" << y << std::endl; }
};

class Rectangle {
public:
    double height;
    double width;
public:
    Rectangle(double height, double width) {
        this->height = height;
        this->width  = width;
    }
    ~Rectangle() {
        std::cout << "Rectangle died\n";
    }
    double calculateArea() {
        return this->height * this->width;
    }
    double calculatePerimeter() {
        return (this->height + this->width) * 2;
    }
};

int main() {
    Rectangle a(10, 30);
    cout << a.calculateArea() << '\n';
    cout << a.calculatePerimeter();
}
