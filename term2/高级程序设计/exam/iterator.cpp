# include <self/functional.h>
using namespace util;
using namespace fp;
 // TODO: finish the following class, and override the corresponding operator

class MyArray {
    int size;
    bool array_alive;
    int *arr;
public:
    class Iterator {
    private:
        int *it;
        MyArray *pma;
    public:
        Iterator() { };
        ~Iterator() { };
        Iterator(int *it, MyArray *ma) {
            this->it  = it;
            this->pma = ma;
        }
        bool is_valid() const {
            return  this->pma->arr && this->pma->array_alive && this->pma->arr <= this->it && this->it < (this->pma->arr + this->pma->size);
        }
        bool get(int &value) const {
            if ( this->is_valid() ) {
                value = *(this->it);
                return true;
            }
            return false;
        }
        bool put(int value) {
            if ( this->is_valid() ) {
                *it = value;
                return true;
            }
            return false;
        }
        Iterator operator++(int) {
            int *old_it = this->it;
            this->it++;
            return Iterator(old_it, this->pma);
        }

        Iterator &operator++() {
            ++this->it;
            return *this;
        }

        Iterator operator--(int) {
            int *old_it = this->it;
            this->it--;
            return Iterator(old_it, this->pma);
        }

        Iterator &operator--() {
            --this->it;
            return *this;
        }

        bool operator==(const Iterator &other) const {
            return (this->it == other.it) && (this->pma == other.pma);
        }

        bool operator!=(const Iterator &other) const {
            return !(*this == other);
        }

        Iterator operator+(int len) const {
            return Iterator(this->it + len, this->pma);
        }

        Iterator operator-(int len) const {
            return Iterator(this->it - len, this->pma);
        }

        int operator*() const {
            return *(this->it);
        }
    };

public:
    friend class Iterator;
    MyArray(int sz) {
        this->size = sz;
        this->arr  = new int[this->size];
        this->array_alive = true;
    }
    ~MyArray() {
        delete[] this->arr;
        this->array_alive = false;
        this->arr = nullptr;
    }
    Iterator end() {
        int *the_end = this->arr + this->size;
        return Iterator(the_end, this);
    }
    Iterator begin() {
        return Iterator(this->arr, this);
    }
    MyArray(const MyArray&) = delete;
    MyArray& operator=(const MyArray&) = delete;
};

int main(int arg_number, char **arg_value) {
    MyArray a = MyArray(10);
    MyArray b = MyArray(0);
    MyArray::Iterator it;
    it = a.end();
    int c;
    print("*it = ", (++it).get(c));
    print("a.begin().is_valid() = ", a.begin().is_valid(), a.begin().put(1145114));
    print("a[0] = ", *(a.begin() + 1));
    compose(
            [=] (auto i) {return i + 1;},
            [=] (auto i) {return i * 2;}
            )(10);

    int i = 0;
}
