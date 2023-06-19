#include <iostream>
#include <string>

using namespace std;


class Person {
private:
	double height;
	double weight;
	int ID;
public:
    Person() = default;
    Person(double h, double w, int id):
        height(h), weight(w), ID(id) {}
    ~Person() = default;
    Person(const Person &p) {
        height = p.height;
        weight = p.weight;
        ID = p.ID;
    }
    void display() {
        cout << ID << ", " << height << ", "
             << weight << ", " << endl;
    }
};



int main()
{
    Person p(175.5, 63.2, 893410010);
    Person p2(p);
    //Person p(175.5, 63.2, 893410010, "Joseph Lin");
    p2.display();
    return 0;
}
