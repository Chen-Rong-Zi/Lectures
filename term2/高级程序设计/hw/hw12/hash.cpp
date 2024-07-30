# include <string>
# include <vector>
# include <iostream>

using namespace std;

inline unsigned hashFunc(const string &s)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        hash = hash * seed + (s[i]);
    }

    return (hash & 0x7FFFFFFF);
}

int main(const int arg_number, const char **arg_value) {
    vector<int> a;
    auto b = a[1000];
    return 0;
}
