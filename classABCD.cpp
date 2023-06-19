#include <iostream>
#include <cstdio>
using namespace std;

class A {
    public:
        int x = 0;
        int get_pvt() {
            return z;
        }
        protected:
            int y = 1;
        private:
            int z = 2;
};
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};
class C : protected A {
public:
    int y;
    C(){
        y = A::y;
    }
    // x is protected
    // y is protected
    // z is not accessible from C
};
class D : private A {
public:
    int y;
    D(){
        y = A::y;
    }
    // 'private' is default for classes
    // x is private
    // y is private
    // z is not accessible from D
};

int main (){
    B obj1;
    C obj2;
    D obj3;
    cout << obj1.x << obj2.y << obj3.y;
     // try to print these values
     // by adding appropriate member
     //functions
     return 0;
}
