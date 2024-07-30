#include <string>
#include <iostream>
using namespace std;

class CallMyName
{
    void **all_functions;
public:
    CallMyName(void *af[5]){
        all_functions=af;
    }

    int call(const string &my_call) {
        int lb_index = my_call.find('('), rb_index = my_call.find(')'), length = my_call.length();
        string func_name = my_call.substr(0, lb_index);
        if ( func_name == "funcMyAbs" ) {
            string number_str = my_call.substr(lb_index + 1, rb_index - 1);
            return ((int (*)(int))(all_functions[0]))(stoi(number_str));
        }

        int comma_index = my_call.find(',');
        string a_str = my_call.substr(lb_index+1, comma_index-1);
        string b_str = my_call.substr(comma_index+1, rb_index-1);
        if ( func_name == "funcMyAdd" ) {
            int a = stoi(a_str), b = stoi(b_str);
            return ((int (*)(int, int))all_functions[3])(a, b);
        }
        if ( func_name == "funcMySub" ) {
            int a = stoi(a_str), b = stoi(b_str);
            return ((int (*)(int, int))all_functions[1])(a, b);
        }
        if ( func_name == "funcMyHash" ) {
            int a = stoi(a_str), b = stoi(b_str);
            return ((int (*)(int, int))(all_functions[2]))(a, b);
        }
        if ( func_name == "funcMySum" ) {
            int comma_index_again = comma_index + 1;
            for (  ; comma_index_again < length; ++comma_index_again )
            {
                if ( my_call[comma_index_again] == ',' )
                    break;
            }
            char a_str[10] = {}, b_str[10] = {}, c_str[10] = {};
            for (  int j = 0, i = lb_index + 1; i < comma_index; ++i, ++j )
            {
                a_str[j] = my_call[i];
            }
            for (  int j = 0, i = comma_index + 1; i < comma_index_again; ++i, ++j )
            {
                b_str[j] = my_call[i];
            }
            for (  int j = 0, i = comma_index_again + 1; i < rb_index; ++i, ++j )
            {
                c_str[j] = my_call[i];
            }
            int a = stoi(a_str), b = stoi(b_str), c = stoi(c_str);
            return ((int (*)(int, int, int))(all_functions[4]))(a, b, c);
        }
        return 0;
    }
};

