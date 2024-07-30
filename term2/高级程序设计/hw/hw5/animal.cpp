# include <iostream>

class Animal {
protected:
    int name;
    int age;
    int color;
public:
    void makeSound() {
        std::cout << "Ready" << std::endl;
    }
    Animal(){}
    Animal(int name, int age, int color) {
        this->name  = name;
        this->age   = age;
        this->color = color;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "woof, woof" << std::endl;
    }
    Dog(int name, int age, int color) : Animal(name, age, color) { }
    int get_age() {
        return this->age;
    }
};

class Cat : protected Animal {
public:
    void makeSound() {
        std::cout << "meow, meow" << std::endl;
    }
    Cat(int name, int age, int color) : Animal(name, age, color){}
};

int main(int arg_number, char **arg_value) {
    Animal a(1, 2, 3);
    Dog d(1, 2, 3);
    Cat c(1, 2, 3);
    d.makeSound();
    c.makeSound();
    std::cout << d.get_age() << std::endl;
    return 0;
}
