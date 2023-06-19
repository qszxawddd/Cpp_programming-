#include <iostream>
#include <string>

using namespace std;

class TwoDim
{
    protected:
        double x, y; // x, y:  coordinates
    public:
        //constructor
        TwoDim(double i, double j):
            x(i), y(j) {}
            // member functions
            void setX(double newX){x = newX;}
            void setY(double newY){y = newY;}
            double getX() const {return x;}
            double getY() const {return y;}
};

class ThreeDim : public TwoDim {
protected:
    double z;
public:
    // constructor
    ThreeDim(double i, double j, double k) : TwoDim(i, j), z(k) {}
    // member functions
    void setZ(double newZ) { z = newZ; }
    double getZ() const { return z; }
};

int main()
{
    ThreeDim v(1,2,3);
    cout << v.getX() << ", " << v.getY() << ", " << v.getZ() << endl;
    v.setX(-1);
    v.setY(-2);
    cout << v.getX() << ", " << v.getY() << ", " << v.getZ() << endl;
    return 0;
}
