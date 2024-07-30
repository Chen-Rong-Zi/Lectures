# include <iostream>

int &min(int &a, int &b) {
    return a;
}

void f(const int& value) {
    std::cout << value << std::endl;
}

int var =100;
const int cvar =200;

void f(int al,int &a2, const int& a3){
    return;
}

int main(int arg_number, char **arg_value) {
//     f(1,2,3);
//     f(1,var var);
//     f(1,cvar,cvar);
//     f(1,var,cvar);
//     f(1,cvar,var);
//     f(var,var,var);
    f(cvar,var,cvar);
    return 0;
}
