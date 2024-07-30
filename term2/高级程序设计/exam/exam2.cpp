# include <cstdio>
# include <iostream>
# include <vector>
#include<cstring>
#include<iostream>
using namespace std;

int len(const char *string) {
    int i = 0;
    for (  i = 0; string[i] != '\0'; ++i );
    return i + 1;
}

int index(const char *string, char target) {
    for (  int i = 0; i < len(string); ++i ) {
        if ( target == string[i] )
            return i;
    }
    return -1;
}

// 补充solution函数，参数为题目输入的str，在该函数内输出结果
void solution(const char *str)
{
    int n_index = index(str, 'N');
    int j_index = index(str, 'J');
    int u_index = index(str, 'U');
    if ( n_index < 0 || j_index < 0 || u_index < 0 )
        cout << "No";
    else if ( n_index < j_index && j_index < u_index )
        cout << "Yes";
    else
        cout << "No";

}

// 我们为你提供了main函数，处理了输入，你只需要关注solution函数
// 如果你需要对string类型直接进行操作，可自行修改，测评只关注输出的内容
int main()
{
    string s1;
    cin >> s1 ;

    const char *str = s1.c_str();

    solution(str);

    return 0;
}
