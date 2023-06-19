#include <iostream>

using namespace std;

class Vehicle {
private:
    double vehiclePrice;
public:
    Vehicle() = default;
    Vehicle(double price): vehiclePrice(price) {}
    ~Vehicle() = default;
    double get_v_price() { return vehiclePrice; }
};

class FourWheeler : public Vehicle {
//class FourWheeler {
private:
    double wheelsPrice;
public:
    FourWheeler() = default;
    //FourWheeler(double price): wheelsPrice(price) {}
    FourWheeler(double v_price, double w_price): Vehicle(v_price), wheelsPrice(w_price) {}
    ~FourWheeler() = default;
    double get_w_price() { return wheelsPrice; }
};

//class Car : public Vehicle, public FourWheeler {
class Car : public FourWheeler {
private:
    double carPrice;
public:
    Car() = default;
    Car(double v_price, double w_price, double c_price):
    //Vehicle(v_price), FourWheeler(w_price), carPrice(c_price) {}
    FourWheeler(v_price, w_price), carPrice(c_price) {}
    ~Car() = default;
    double totalCost();
};

double Car::totalCost() {
    //return get_w_price() + get_v_price() + carPrice;
    return get_w_price() + get_v_price() + carPrice;
}


int main()
{
    double base_price, wheels_price, car_price;
    cout << "Enter the base price, wheels' price and car price: " << endl;
    cin >> base_price >> wheels_price >> car_price;
    Car c(base_price, wheels_price, car_price);
    cout << "Total cost of the car: " << c.totalCost() << endl;
    return 0;
}
