#include<iostream>
using namespace std;
class A {
    int x;
    public:
        A() = default;
        A(int i) { x = i; }
        void print() { cout << x; }
};
class B: virtual public A {
    public:
        B():A(10) {}
};
class C:
    virtual public A {
        public:
            C():A(20) {}
    };
class D: public B, public C {
    //answer
public:
    D() : A(20) {}
};

int main()
{
    D d;
    d.print();
    return 0;
}
