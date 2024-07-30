# include <iostream>
using namespace std;

void fun(int n, char *s);

int main(int arg_number, char **arg_value) {
//     long* const cplVar;
//     const long lcVar;
//     const long* const cplcVar;
//     const long* plcVar;
// 
//     int *pd; int *pi=pd; cout<<*pi;
//     int a[2][3]; a[2][3]=20;
//     int num = 3; const int cptr =&num ;
//     double dval = 3.14; int &ri = dval;
    void (*pf)(int, char *s);
    pf = &fun;
}
