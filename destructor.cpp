#include <iostream>
using namespace std;

class rectangle {
    public:
        typedef int unit;
        void area();
        void set(unit wd, unit ht);
        rectangle() = default;
        rectangle(unit wd, unit ht): width(wd), height(ht) { };
        ~rectangle() {};
    private:
        unit width;
        unit height;
    };
    void rectangle::set(unit wd, unit ht)
    {
        width = wd;
        height = ht;
    }
    void rectangle::area()
    {
        cout << "The area: " << width * height << endl;
    }
int main() // DO NOT modify main()
{
    rectangle obj, obj2(2,5);
     //creating object of rectangle class
     rectangle::unit x, y;
     cin >> x;
     cin >> y;
     obj.set(x, y);
     obj.area();
     obj2.area();
     return 0;
}
