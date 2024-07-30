#include "Vector.h"
#include <iostream>

using namespace std;

void Vector::output() const {
 // TODO
    int size = this->vec_.size();
    for ( int i = 0; i < size - 1; i++ )
    {
        cout << (this->vec_)[i] << ' ';
    }
    if ( size > 0 ) {
    cout << (this->vec_)[size - 1];
    }
    cout << endl;
}

Vector Vector::map(map_func f) const {
  // TODO
    vector<int> new_vec;
    for (auto &it : (this->vec_))
    {
        new_vec.push_back(f(it));
    }
    return Vector(new_vec);
}

Vector Vector::filter(filter_func f) const {
  // TODO
    vector<int> new_vec;
    for (auto &it : (this->vec_)) {
        if ( f(it) == true ) {
            new_vec.push_back(it);
        }
    }
    return Vector(new_vec);
}

Vector &Vector::for_each(map_func f) {
 // TODO
    for (  int i = 0, size = this->vec_.size(); i < size; ++i )
    {
        (this->vec_)[i] = f((this->vec_)[i]);
    }
    return *this;
}


int neg(int x) {
    return -x;
}

bool is_neg(int x) {
    return x < 0;
}

bool is_even(int x) {
    return x % 2 == 0;
}

int main(int arg_number, char **arg_value) {
    Vector foo({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    foo.filter(is_even).map(neg).output();
    foo.output();
    // foo.map(neg).filter(is_neg).output();
    // foo.filter(is_neg).output();
}
