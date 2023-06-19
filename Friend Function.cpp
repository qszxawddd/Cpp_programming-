#include <iostream>
using namespace std;

class vector {
private:
    int x, y;
public:
    vector(int a, int b) {
        x = a;
        y = b;
    }
    friend int innerProduct(vector v1, vector v2);
};

int innerProduct(vector v1, vector v2) {
    return v1.x * v2.x + v1.y * v2?.y;
}

int main() {
    vector v1(2,3);
    vector v2(-1,9);
    cout << innerProduct(v1, v2) << endl;
    return 0;
}
