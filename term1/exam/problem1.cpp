#include <iostream>
#include <cstring>

using namespace std;

const int MAX_R = 150;
const int MAX_LEN = 300;

// 函数声明
bool isRepeatSequence(char str[], int r, char result[MAX_R][MAX_LEN]);
void printResult(int r, char result[MAX_R][MAX_LEN]);

int main() {
    int r;
    cin >> r;

    char str[MAX_LEN + 1];
    cin >> str;

    char result[MAX_R][MAX_LEN] = {0};  // 二维数组存储转换结果

    // 进行转换并判断是否是串联重复基因序列
    if (isRepeatSequence(str, r, result)) {
        printResult(r, result);
    } else {
        cout << "N" << endl;
    }

    return 0;
}

// 判断是否是串联重复基因序列并进行转换
bool isRepeatSequence(char str[], int r, char result[MAX_R][MAX_LEN]) {
    int len = strlen(str);
    int rows = len / r;
    int remainder = len % r;

    if (remainder != 0) {
        // 如果转换后的 r 行字符串的长度不都相等，输出 N
        return false;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < rows; ++j) {
            result[i][j] = str[i + j * r];
        }
        // 检查每行是否都是同一种字符
        for (int j = 1; j < rows; ++j) {
            if (result[i][j] != result[i][0]) {
                // 如果某行不是同一种字符，输出 N
                return false;
            }
        }
    }

    return true;
}

// 输出转换结果
void printResult(int r, char result[MAX_R][MAX_LEN]) {
    for (int i = 0; i < r; ++i) {
        cout << result[i] << endl;
    }
}

