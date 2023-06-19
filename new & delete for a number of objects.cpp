#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Vehicle {
private:
    int wheel;
    int glass;
    int engine;
    string brand;
    int price;

public:
    Vehicle() = default;
    Vehicle(int w, int g, int e, string b): wheel(w), glass(g), engine(e), brand(b) {
        totalPrice();
    }

    ~Vehicle() {
        cout << "destructor of 'Vehicle' works here" << endl;
    };

    void totalPrice() {
        price = wheel + glass + engine;
    }

    int ShowPrice() {
        return price;
    }

    void ShowBrand() {
        cout << brand << endl;
    }

};

int main() {

    int n;
    cin >> n;

    Vehicle** vehicles = new Vehicle*[n];

    for (int i = 0; i < n; i++) {
        cout << "Constructor works here" << endl;
        int w, g, e;
        string b;
        cin >> w >> g >> e >> b;
        vehicles[i] = new Vehicle(w, g, e, b);
    }

    for (int i = 0; i < n; i++) {
        vehicles[i]->ShowBrand();
        cout << "Total price: " << vehicles[i]->ShowPrice() << endl;
    }

    for (int i = 0; i < n; i++) {
        delete vehicles[i];
    }

    delete[] vehicles;

    return 0;
}
