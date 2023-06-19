#include <iostream>

using namespace std;

class Shapes {
public:
    virtual int Area() = 0;
    void set_width(int w);
    void set_height(int h);
    void set_width();
    void set_height();
protected:
    int width;
    int height;
};

void Shapes::set_width(int w) {
    width = w;
}

void Shapes::set_height(int h) {
    height = h;
}

void Shapes::set_width() {
    cin >> width;
}

void Shapes::set_height() {
    cin >> height;
}

class Rectangle: public Shapes {
public:
    int Area();
};

int Rectangle::Area() {
    return width * height;
}

class Triangle: public Shapes {
public:
    int Area();
};

int Triangle::Area() {
    return (width * height) / 2;
}


int main()
{
    Rectangle R;
    Triangle T;

    R.set_height(5);
    R.set_width(10);

    T.set_height();
    T.set_width();

    cout << "1st shape has area " << R.Area() << endl;
    cout << "2nd shape has area " << T.Area() << endl;

    return 0;
}
