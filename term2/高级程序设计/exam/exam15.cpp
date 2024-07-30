#ifndef JUMPYDUMPTY_HPP_
#define JUMPYDUMPTY_HPP_
# include <vector>
# include <cmath>
using namespace std;
// 你可以根据你的需要,添加各种成员变量或者成员函数

unsigned long long break_down_by_2(unsigned long long x) {
    if ( x == 0 )
        return 0;
    else if ( x % 2 == 1 )
        return 0;
    return 1 + break_down_by_2(x / 2);
}

struct BigInteger {
public:
    unsigned long long origin;
    unsigned long long power;

    BigInteger(unsigned long long origin) {
        unsigned long long twonums = break_down_by_2(origin);
        if ( twonums == 0 )
            this->origin = origin;
        else
            this->origin = origin / pow(2, twonums);
        this->power = twonums;
    }

    unsigned long long bitnum() const {
        return 64 - __builtin_clzll(this->origin) + this->power ;
    }

    unsigned long long nth_bit(unsigned long long x) const {
        unsigned long long origin_bitnum = 64 - __builtin_clzll(this->origin);
        if ( x > origin_bitnum )
            return 0;
        return ((this->origin >> origin_bitnum - x) & 1);
    }

    bool operator<(const BigInteger &other) {
        if ( this->bitnum() < other.bitnum() )
            return true;
        else if ( this->bitnum() > other.bitnum() )
            return false;
        for ( int i = 1; i < this->bitnum() + 1; i += 1 ) {
            if ( this->nth_bit(i) < other.nth_bit(i) )
                return true;
            else if ( this->nth_bit(i) > other.nth_bit(i) )
                return false;
        }
        return false;
    }

    void operator<<(unsigned long long n) {
        this->power += n / 2;
    }
};

struct JumpyDumpty {
    unsigned long long operator()(std::vector<int> bombs) {
        unsigned long long sum = 0;
        std::vector<BigInteger> big_ints;
        for ( auto it : bombs )
            big_ints.push_back(BigInteger(it));

        for ( size_t i = 1; i < big_ints.size(); i++ )
        {
            while ( big_ints[i] < big_ints[i - 1] ) {
                big_ints[i] << 2;
                sum += 1;
            }
        }
        return sum;
    }
};

#endif
