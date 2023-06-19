#include <iostream>
#include <string>


using namespace std;

class Person {
public:
    Person() = default;
    Person(string n, string g, int a): name(n), gender(g), age(a) {}
    string getName() { return name; }
    string getGender() { return gender; }
    int getAge() { return age; }
protected:
    string name;
    string gender;
    int age;
};

class Student : public Person {
public:
    Student() = default;
    Student(string n, string g, int a, string sid, string sch): Person(n, g, a), studentID(sid), school(sch) {}
    string getStudentID() { return studentID; }
    string getSchool() { return school; }
private:
    string studentID;
    string school;
};

class Employee : public Person {
public:
    Employee() = default;
    Employee(string n, string g, int a, string eid, string pos): Person(n, g, a), employeeID(eid), position(pos) {}
    string getEmployeeID() { return employeeID; }
    string getPosition() { return position; }
private:
    string employeeID;
    string position;
};

int main() {
    // ¿é¤JStudent¸ê®Æ

    string sname, sgender, sid, sch;
    int sage;
    getline(cin, sname);
    getline(cin, sgender);
    cin >> sage;
    cin.ignore();
    getline(cin, sid);
    getline(cin, sch);

    Student student(sname, sgender, sage, sid, sch);

    cout << "Name: " << student.getName() << endl;
    cout << "Gender: " << student.getGender() << endl;
    cout << "Age: " << student.getAge() << endl;
    cout << "Student ID: " << student.getStudentID() << endl;
    cout << "School: " << student.getSchool() << endl;

    string ename, egender, eid, pos;
    int eage;
    getline(cin, ename);
    getline(cin, egender);
    cin >> eage;
    cin.ignore();
    cin >> eid;
    cin.ignore();
    getline(cin, pos);

    Employee employee(ename, egender, eage, eid, pos);

    cout << "Name: " << employee.getName() << endl;
    cout << "Gender: " << employee.getGender() << endl;
    cout << "Age: " << employee.getAge() << endl;
    cout << "Employee ID: " << employee.getEmployeeID() << endl;
    cout << "Position: " << employee.getPosition() << endl;

    return 0;
}
