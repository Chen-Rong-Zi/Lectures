#include <iostream>
#include <vector>
#include <string>

// 乘客类
class Passenger {
private:
    std::string name;
public:
    Passenger(std::string _name) : name(_name) {}
    std::string getName() const { return name; }
};

// 交通工具类
class Vehicle {
protected:
    double weight;
    int capacity;
    std::vector<Passenger> passengers;
public:
    Vehicle(double _weight, int _capacity) : weight(_weight), capacity(_capacity) {}
    void setWeight(double w) { weight = w; }
    virtual void drive() = 0;
    void getOn(const Passenger& passenger) {
        if (passengers.size() < capacity) {
            passengers.push_back(passenger);
            std::cout << passenger.getName() << " boarded the vehicle." << std::endl;
        } else {
            std::cout << "The vehicle is full. " << passenger.getName() << " cannot board." << std::endl;
        }
    }
    void getOff(const Passenger& passenger) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->getName() == passenger.getName()) {
                passengers.erase(it);
                std::cout << passenger.getName() << " left the vehicle." << std::endl;
                return;
            }
        }
        std::cout << passenger.getName() << " is not on the vehicle." << std::endl;
    }
    void showPassengers() const {
        std::cout << "Passengers on the vehicle: ";
        for (const auto& passenger : passengers) {
            std::cout << passenger.getName() << ", ";
        }
        std::cout << std::endl;
    }
    virtual void showMembers() const = 0;
};

// 汽车类
class Car : public Vehicle {
public:
    Car(double _weight, int _capacity) : Vehicle(_weight, _capacity) {}
    void drive() override {
        std::cout << "The car is driving on the road." << std::endl;
    }
    void showMembers() const override {
        std::cout << "Car weight: " << weight << " tons, Capacity: " << capacity << " people" << std::endl;
    }
};

// 船类
class Boat : public Vehicle {
public:
    Boat(double _weight, int _capacity) : Vehicle(_weight, _capacity) {}
    void drive() override {
        std::cout << "The boat is sailing on the water." << std::endl;
    }
    void showMembers() const override {
        std::cout << "Boat weight: " << weight << " tons, Capacity: " << capacity << " people" << std::endl;
    }
};

// 水陆两用汽车类
class AmphibianCar : public Vehicle {
private:
    bool isOnWater;
public:
    AmphibianCar(double _weight, int _capacity) : Vehicle(_weight, _capacity), isOnWater(false) {}
    void drive() override {
        if (isOnWater) {
            std::cout << "The amphibian car is driving on the water." << std::endl;
        } else {
            std::cout << "The amphibian car is driving on the road." << std::endl;
        }
    }
    void setFlag(bool flag) { isOnWater = flag; }
    void showMembers() const override {
        std::cout << "Amphibian car weight: " << weight << " tons, Capacity: " << capacity << " people" << std::endl;
    }
};

int main() {
    Car car(1.5, 4);
    Boat boat(2.5, 6);
    AmphibianCar amphiCar(2.0, 5);

    Passenger p1("Alice");
    Passenger p2("Bob");
    Passenger p3("Charlie");

    car.getOn(p1);
    car.getOn(p2);
    car.showPassengers();
    car.getOn(p3);
    car.showPassengers();
    car.getOff(p1);
    car.showPassengers();

    boat.getOn(p1);
    boat.getOn(p2);
    boat.showPassengers();
    boat.getOn(p3);
    boat.showPassengers();
    boat.getOff(p2);
    boat.showPassengers();

    amphiCar.drive();
    amphiCar.setFlag(true);
    amphiCar.drive();

    return 0;
}

