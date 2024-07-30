#include <vector>  
#include <algorithm>  
using namespace std;
const int length = 1100;
bool temp[1100][1100] = { false };
bool compare(bool(*box)[1100], int x, int y) {
    for (int i = 0; i < length;i++) {
        if (box[x][i]==true&&box[y][i]==false) {
            return true;
        }
        else if (box[x][i] == false && box[y][i] == true) {
            return false;
        }
    }
    return false;
}

void move(bool (*box)[1100],int n) {
    for (int i = 0; i < length - 1;i++) {
        box[n][i] = box[n][i + 1];
    }
    box[n][length - 1] = false;
}

struct JumpyDumpty {
    long long operator()(std::vector<int> bombs) const
    {
        long long operations = 0;
        int kick;
        int cnt;
        for (int  i = 0; i < bombs.size(); ++i) {
            kick = bombs[i];
            cnt = length - 1;
            while (kick > 0) {
                if (kick % 2 == 1) {
                    temp[i][cnt] = true;
                }
                cnt--;
                kick = kick / 2;
            }
        }
        for (int i = 0; i < bombs.size()-1; i++) {
            while (compare(temp,i,i+1)==true) {
                move(temp, i + 1);
                operations++;
            }
        }
        return operations;
    }
};
