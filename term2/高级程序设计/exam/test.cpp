# include <string>
# include <self/functional.h>

using namespace std;
using namespace fp;
using namespace util;

int main(const int arg_number, const char **arg_value) {
    string ans = "";
    for ( auto &it : "ANBCD" )
    {
        if ( it - 20 < 65 ) {
            ans += it + 26 - 20;
        } else {
            ans += it - 20;
        }
        print(ans);
    }
    print(string("asdfasdf").find('a'));
    return 0;
}
