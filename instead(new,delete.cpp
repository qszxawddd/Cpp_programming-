#include <iostream>
#include <memory>

using namespace std;

class Grade {
private:
    int math;
    int eng;
    int sum;
public:
    Grade() = default;
    Grade(int m, int e): math(m), eng(e) {};
    ~Grade() { cout << "destructor of 'Grade' works here" << endl; } ;
    void SumUp() { sum = math + eng; }
    int ShowSum() { return sum; }
};


int main()
{
    Grade *ptr = new Grade(100, 90);
    ptr->SumUp();
    cout << "The total grades: " << ptr->ShowSum() << endl;
    delete ptr;
    return 0;
}
