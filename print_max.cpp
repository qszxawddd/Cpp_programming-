#include<iostream>

using namespace std;

template <class T>
void print_max(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << max << endl;
}

int main() {
    int a[6] = { 10, 50, 30, 40, 20, -20 };
    float b[] = { 2.3, 0.0, -1.2, 17.2 };
    char c[] = "TKUCS";
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);
    print_max<int>(a, n1);
    print_max<float>(b, n2);
    print_max<char>(c, n3);
    return 0;
}
