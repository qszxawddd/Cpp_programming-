#include <iostream>
using namespace std;

class Animals {
public:
    virtual void sound() {
        cout << "Animals' sound." << endl;
    }
};

class Dogs : public Animals {
public:
    void sound() {
        cout << "Dogs bark!" << endl;
    }
};

class Cats : public Animals {
public:
    void sound() {
        cout << "Cats miao~" << endl;
    }
};

int main() {
    Animals *animal;

    Dogs dog;
    Cats cat;

    animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    return 0;
}
