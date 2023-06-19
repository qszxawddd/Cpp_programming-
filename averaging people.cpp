#include <iostream>
#include <string>

using namespace std;


class Person {
private:
	double height;
	double weight;
	int ID;
	string name;
public:
    Person() = default;
    Person(double h, double w, int id, string na):
        height(h), weight(w), ID(id), name(na) {}
    ~Person() = default;
    Person(const Person &p) {
        height = p.height;
        weight = p.weight;
        ID = p.ID;
        name = p.name;
    }
    void display() {
        cout << name << ", " << ID << ", " << height << ", "
             << weight << ", " << endl;
    }
    friend Person average(const Person& p1, const Person& p2);
};

Person average(const Person &p1, const Person &p2) {
    double ht = (p1.height + p2.height)/2;
    double wt = (p1.weight + p2.weight)/2;
    int id = (p1.ID + p2.ID)/2;
    string name = p1.name + " and " + p2.name;
    return Person(ht, wt, id, name);
}


int main()
{
    Person p(175.5, 63.2, 893410010, "Joseph Lin");
    Person p2(p);
    Person p1(180, 70, 684710021, "Maggie Kuo");
    Person p3 = average(p1, p2);
    p3.display();
    return 0;
}
