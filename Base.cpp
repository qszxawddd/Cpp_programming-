#include <iostream>
using namespace std;
class Base {
    public:
        virtual void print() {
            cout << "Base Function" << endl;
        }
};

class Derived : public Base {
    protected:
        void print(){
            cout << "Derived Function" << endl;
        }
};

int main() {
    Derived derived1;
    Base bObj;
    Base* ptr = &derived1;
    Base &obj = derived1;
    ptr->print();
    obj.print();
    return 0;
}
