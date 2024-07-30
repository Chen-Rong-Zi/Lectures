# include <string>
# include <iostream>

class Passenger;

class Vehicle {
protected:
    int weight;
    int capacity;
protected:
    virtual void setWeight(int) = 0;
public:
    virtual void drive()           = 0;
    virtual void getOn(Passenger)  = 0;
    virtual void getOff(Passenger) = 0;
    virtual void showPassenger()   = 0;
    virtual void showMembers()     = 0;
};

class Car : protected Vehicle{
private:
    void setWeight(int weight) {
        this->weight = weight;
    }
public:
    Car(int weight, int capacity) {
        this->setWeight(weight);
        this->capacity = capacity;
    }
    // void getOn(Passenger people) {
    // }
};

class Passenger {
    std::string name;    // 姓名
    std::string ID;      // 身份ID
    std::string company; // 所在单位
public:
    Passenger(const std::string &name, const std::string &ID,
              const std::string &company)
        : name(name), ID(ID), company(company) {}
    void showInfo(std::ostream &os) {
        os << "来自" << company << "的" << name << ", " << ID << "\n";
    }
};

int main(int arg_number, char **arg_value) {
    Car c(3, 5);
    c.drive();
    Boat b(5, 10);
    b.drive();
    AmphibianCar a(4, 200, true);
    a.drive();
    a.showMembers();
    a.setWeight(3);
    a.setFlag(false);
    a.drive();
    a.ShowMembers();
    return 0;
}
