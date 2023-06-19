#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
};

int main() {

    Student *p1 = new Student();
    Student *p2 = new Student({123456789,"XXXX"});

    cout << p1->id << "," << p1->name << "\n";
    cout << p2->id << "," << p2->name << "\n";


    delete p1;
    delete p2;

    return 0;
}
