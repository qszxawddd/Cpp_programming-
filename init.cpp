#include<iostream>

using namespace std;

template <typename T1, typename T2>
T1 init (T1 num1, T1 num2, T2& start);

template <typename T1, typename T2>
T1 init (T1 num1, T1 num2, T2& start) {
    start = 1;
    return num1 + num2;
}

int main()
{
    double n1 = 1.6;
    double n2 = 2.5;
    int start;
    cout << "result = " << init<double, int>(n1, n2, start);
    cout << endl;
    cout << "start = "<< start << endl;
    return 0;
}
