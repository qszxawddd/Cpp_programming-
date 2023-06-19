#include <iostream>

using namespace std;

class vector
{
    private:
        int x,y;
    public:
        vector(int x, int y) {
            this->x= x;
            this->y= y;
        }
        friend int innerProduct(vector, vector);
};

int innerProduct(vector v1, vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    vector v1(x1, y1);
    vector v2(x2, y2);

    cout << innerProduct(v1, v2);

    return 0;
}
