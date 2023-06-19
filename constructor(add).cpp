#include <iostream>

using namespace std;

class practice {
public:
    practice(int n1, int n2);
    void set_a(int n);
    void set_b(int n);
    int get_a();
    int get_b();
    int add();

private:
    int a;
    int b;
};

practice::practice(int n1, int n2) {
    a = n1;
    b = n2;
}

int practice::add() {
    return get_a() + get_b();
}
void practice::set_a(int n) {
    a = n;
}

void practice::set_b(int n) {
    b = n;
}

int practice::get_a() {
    return a;
}

int practice::get_b() {
    return b;
}

int main() {

    practice constructor(3, 6);

    cout << constructor.add() << endl;
    cout << endl;

    return 0;
}
