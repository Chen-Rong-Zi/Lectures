#include<iostream>
#include<vector>
# include <self/functional.h>

using namespace fp;
using namespace std;

//Monster
class Monster{
	public:
		int type;//0 1 2
        int weight;
        int value_per_kg;
        int price;
		Monster *next;
        //补充需要的数据成员和成员函数

    public:
        int been_bought() {
            return this->value_per_kg * this->weight;
        }

        void grow(int days) {
            if ( this->type == 0 ) {
                // 行走菇
                this->weight += 2 * days;
            }
            else if ( this->type == 1 ) {
                // 蛇尾鸡
                this->weight += 1 * days;
            }
            else if ( this->type == 2 ) {
                // 水息马
                this->weight += 2 * days;
            }
        }

        Monster(int type) {
            this->type   = type;
            if ( type == 0 ) {
                // 行走菇
                this->price        = 5;
                this->weight       = 1;
                this->value_per_kg = 1;
            }
            else if ( type == 1 ) {
                // 蛇尾鸡
                this->price        = 20;
                this->weight       = 2;
                this->value_per_kg = 4;
            }
            else if ( type == 2 ) {
                // 水息马
                this->price        = 84;
                this->weight       = 4;
                this->value_per_kg = 6;
            }
        }
};

//Farm
class Farm{
	private:
        //补充需要的数据成员
        vector<Monster *> get_monsters_helper(Monster *) {
            Monster *walk = head;
            vector<Monster *>pmonsters;
            while ( walk != NULL ) {
                pmonsters.push_back(walk);
                walk = walk->next;
            }
            return pmonsters;
        }

        void set_monster_head_helper(vector<Monster *> pmon_lst, Monster *head) {
            this->head = fp::reduce(
            [=] ( Monster *pre, Monster *curr ) {
                curr->next = pre;
                return curr;
            }, pmon_lst, head);
        }
	public:
		Monster *head;
        int capacity;
        int left_coins;
		Farm(int X,int N);
		~Farm();//输出把现有魔物全部卖出后的金币数
		vector<Monster *> get_monsters() { //返回所有的魔物指针 
            return get_monsters_helper(this->head);
        }
		int buyMonster(int type, int num);//返回总的魔物数量
		int saleMonster(int type, int num);//返回卖出后的总金币数
		void saleOneMonster(Monster *);
		void raiseMonster(int t);//养魔物t天
        void print();

        void delete_monster(Monster *pmon) {
            this->set_monster_head(filter( [=] ( Monster *mon ) { return pmon != mon;}, this->get_monsters()));
            delete pmon;
        }

        void set_monster_head(vector<Monster *> pmon_lst) {
            this->set_monster_head_helper(pmon_lst, NULL);
        }

        void add_monster(Monster *mon) {
            mon->next = this->head;
            this->head = mon;
        }

        int count_head() {
            return this->get_monsters().size();
        }

        int count(int type) {
           return filter( [=] ( Monster *mon ) { return mon->type == type; }, this->get_monsters()).size();
        }
        //以上函数请在farm.cpp中实现
};

