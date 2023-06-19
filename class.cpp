#include <iostream>

using namespace std;

class A
{
private:
    int private_value;
protected:
    int protected_value;
public:
    A(int private_value,int protected_value)
    {
        this -> private_value = private_value;
        this -> protected_value = protected_value;
    }
    friend class B;
};

class B
{
public:
    void display(A& t)
    {
        cout << "The value of private value = " << t.private_value << endl;
        cout << "The value of protected value = " << t.protected_value << endl;
    }
};
int main(){
    A a(999,100);
    B b;
    b.display(a);
    return 0;
}
