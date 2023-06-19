#include <iostream>
using namespace std;

class Matrix_Widget {
    private:
        int mat[3][3];
    public:
        Matrix_Widget();
        Matrix_Widget(int v);
        Matrix_Widget(const Matrix_Widget& other);
        // initialize mat to be v at each position
        void modify(int i, int j, int value);
        void showMatrix();
        ~Matrix_Widget() { cout << "obj deleted" << endl;}
};

Matrix_Widget::Matrix_Widget()
{
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = 0;
            }
        }
    }


Matrix_Widget::Matrix_Widget(int v)
{
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mat[i][j] = v;
            }
        }
}

Matrix_Widget::Matrix_Widget(const Matrix_Widget& other)
{
    // copy all elements from other
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = other.mat[i][j];
        }
    }
}

void Matrix_Widget::modify(int i, int j, int value)
{
    mat[i][j] = value;
}

void Matrix_Widget::showMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Matrix_Widget obj, obj2(1);
    obj.showMatrix();
    obj2.showMatrix();
    obj.modify(1, 2, 9);
    Matrix_Widget obj3(obj);
    obj3.showMatrix();
    return 0;
}
