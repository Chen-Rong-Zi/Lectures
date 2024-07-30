// MonsterLand.h
#include<iostream>

class MonsterLand {
private:
    int number;
    int gem[105];
public:
	void game(int n, int *arr);     // 生成今天的游戏中，怪兽的数量和它们的宝石数量
    int quiz();                // 返回小蓝鲸给出的答案
    // 请注意，以上函数的函数体请你在 MonsterLand.cpp中实现！
};
