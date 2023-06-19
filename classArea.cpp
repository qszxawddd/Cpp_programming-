#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) {
        width = w;
        height = h;

    }
    double area() {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shape;
    Rectangle rect(5.0, 6.0);
    Circle circle(3.0);

    shape = &rect;
    cout << "¯x§Î­±¿n¡G" << shape->area() << endl;

    shape = &circle;
    cout << "¶ê­±¿n¡G" << shape->area() << endl;

    return 0;
}
