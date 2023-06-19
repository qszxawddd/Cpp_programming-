#include <iostream>

using namespace std;

class classA {
private:
    int numA;
    friend class classB;

public:
    classA() = default;
    classA(int a): numA(a) {}
    ~classA() = default;
};

class classB {
private:
    int numB;
public:
    classB(): numB(0) {}
    classB(int b): numB(b) {}
    ~classB() = default;
    int getNum(classA obj) { return obj.numA; }
};

int main()
{
    classA ca(100);
    classB cb(200);
    cout << cb.getNum(ca) << endl;

    return 0;
}
