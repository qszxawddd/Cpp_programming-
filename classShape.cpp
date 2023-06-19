#include <iostream>
#include <cstdlib>
using namespace std;

class Shape {
    public:
        string type;
        protected:
            double parameter;
};

class Circle : protected Shape {
    private:
        double area = 0.0;

    public:
        void compute_area() {
        area = 3.14159 * parameter * parameter;
        }
        void setRadius() {
            cin >> parameter;
        }
        double getArea() {
            return area;
        }
};

int main()
{
    Circle obj;
    obj.setRadius();
    obj.compute_area();
    cout << "Area: " << obj.getArea();
    return 0;
}
