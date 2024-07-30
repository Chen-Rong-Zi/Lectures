# include <string>
# include <functional>
#include "farm.h"

using namespace std;
using namespace fp;
using namespace util;

string type_to_string(int type) {
    if ( type == 0 )
        return "行走菇";
    else if ( type == 1 )
        return "蛇尾鸡";
    else if ( type == 2 )
        return "水息马";
    return "NULL";
}

Farm::Farm(int X,int N){
    this->capacity   = N;
    this->left_coins = X;
    this->head       = NULL;
}

Farm::~Farm(){
    //TODO
    vector<Monster *> pmonsters = this->get_monsters();
    this->left_coins += reduce( [=] ( auto pre, auto curr ) { return pre + curr->been_bought(); }, pmonsters, 0);
    for ( auto i : pmonsters )
        delete i;
    util::print(this->left_coins);
}
int Farm::buyMonster(int type, int num) {
    //TODO 购买种类为type的魔物num只-返回魔物数量
    Monster waste(type);
    if ( this->left_coins < waste.price * num ||
            this->capacity < this->count_head() + num) {
        return this->count_head();
    }

    for ( int i = 0 ; i < num; ++i )
    {
        Monster *mon = new Monster(type);
        this->add_monster(mon);
        this->left_coins -= mon->price;
    }
	return this->count_head();
}


void Farm::saleOneMonster(Monster *pbought_mon) {
    vector<Monster *> left_mons = filter([=] ( Monster *mon ) { return mon != pbought_mon;}, this->get_monsters());
    this->set_monster_head(left_mons);
    this->left_coins += pbought_mon->been_bought();
    delete pbought_mon;
}

int Farm::saleMonster(int type, int num) {
    if ( this->count(type) < num )
        return this->left_coins;

    auto pmonsters = this->get_monsters();
    typedef function<vector<Monster *> (vector<Monster *>)> pmonster_vector_func;

    vector<pmonster_vector_func> working_lst = {
        lazy_filter([=] ( Monster *mon ) { return mon->type == type; }, pmonsters),
        lazy_sorted([=] ( Monster *mon1, Monster *mon2 ) { return mon1->weight > mon2->weight; }, pmonsters),
        [=] ( vector<Monster *> pmons ) { return slice(pmons, 0, num);},
    };
    this->left_coins += reduce([=] ( int pre, Monster *curr ) { return pre + curr->been_bought();}, compose(working_lst, pmonsters), 0);
    for ( auto i : compose(working_lst, pmonsters) ) {
        this->delete_monster(i);
    }
	return this->left_coins;
}

void Farm::raiseMonster(int t){
	//TODO 养魔物t天
    vector<Monster *> pmonsters = this->get_monsters();
    for ( auto i : pmonsters )
        if ( i != NULL )
            i->grow(t);
}

void Farm::print() {
    Monster **ppwalk = &this->head;
    int index = 0;
    while ( *ppwalk != NULL ) {
        util::print("index: ", type_to_string((*ppwalk)->type));
        util::print("weight = ", (*ppwalk)->weight, "\tvalue_per_kg = ", (*ppwalk)->value_per_kg, "\t sum = ", (*ppwalk)->been_bought());
        ppwalk = &(*ppwalk)->next;
        index++;
    }
}


int main(){
    Farm farm1 = Farm(50,10);
    print(farm1.buyMonster(1,1));
    print(farm1.buyMonster(0,2));
    farm1.raiseMonster(7);
    farm1.print();
    farm1.saleMonster(1,1);
}
