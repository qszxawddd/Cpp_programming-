#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void printInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : virtual public Person {
protected:
    std::string studentID;

public:
    Student(const std::string& n, int a, const std::string& id) : Person(n, a), studentID(id) {}

    virtual void printInfo() {
        Person::printInfo();
        std::cout << "Student ID: " << studentID << std::endl;
    }
};

class Employee : virtual public Person {
protected:
    std::string employeeID;

public:
    Employee(const std::string& n, int a, const std::string& id) : Person(n, a), employeeID(id) {}

    virtual void printInfo() {
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

class Manager : public Student, public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int a, const std::string& studentID, const std::string& employeeID, const std::string& dept) :
        Person(n, a), Student(n, a, studentID), Employee(n, a, employeeID), department(dept) {}

    virtual void printInfo() {
        Person::printInfo();
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {
    Manager manager("Alice", 30, "123456", "7890", "Sales");
    manager.printInfo();

    return 0;
}
