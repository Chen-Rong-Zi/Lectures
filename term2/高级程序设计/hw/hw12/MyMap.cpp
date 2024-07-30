// MyMap.cpp
#include"MyMap.h"
#include <vector>
#include <list>

using namespace std;

Map::Map() : capacity(10), _size(0) {
    table.resize(capacity);
}

Map::~Map() {}

bool Map::insert(const string &key, int value) {
    unsigned int index = hashFunc(key);
    for (auto &kv : table[index]) {
        if (kv.first == key) {
            // 键已存在，更新值
            // kv.second = value;
            return false;
        }
    }
    // 键不存在，插入新元素
    table[index].emplace_back(key, value);
    _size++;
    return true;
}

bool Map::find(const string& key) {
    unsigned int index = hashFunc(key);
    for (const auto& kv : table[index]) {
        if (kv.first == key) {
            return true;
        }
    }
    return false;
}

bool Map::erase(const string& key) {
    unsigned int index = hashFunc(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            _size--;
            return true;
        }
    }
    return false;
}

int & Map::operator[](const string &key) {
    static int defaultValue = 0; // 默认值
    unsigned int index = hashFunc(key);
    for (auto& kv : table[index]) {
        if (kv.first == key) {
            return kv.second;
        }
    }
    // 键不存在，创建新键值对
    table[index].emplace_back(key, defaultValue);
    _size++;
    return table[index].back().second;
}

int Map::size() const {
    return this->_size;
}

int main(const int arg_number, const char **arg_value) {
    Map id2grade;
    // 插入两个键值对
    id2grade.insert("202200001", 99);
    id2grade.insert("202200002", 98);
    std::cout << id2grade.size() << std::endl; // 2
    // 删除一个已经存在的键："202200002"后查找不到改键；删除一个不存在的键；
    std::cout << id2grade.erase("202200002") << std::endl; // 1(true)
    std::cout << id2grade.find("202200002")  << std::endl; // 0(false)
    std::cout << id2grade.erase("202200000") << std::endl; // 0(false)
    std::cout << id2grade.size() << std::endl; // 1
    // 用下标访问方式查询键对应的值，包含已存在的键值对和不存在的键值对
    // 注意，用下标访问的方式访问了不存在的key，你需要为该key创建一个键值对，值的初始值为0
    std::cout << id2grade["202200001"] << std::endl; // 99
    std::cout << id2grade["202200002"] << std::endl; // 0
    std::cout << id2grade.find("202200002") << std::endl; // 1(true)
    std::cout << id2grade.size() << std::endl; // 2
    // 用insert插入键值对，但该键已存在，插入失败，原有的键值对不变
    std::cout << id2grade.insert("202200002", 100) << std::endl; // 0(false)
    std::cout << id2grade["202200002"] << std::endl; // 0
    std::cout << id2grade.size() << std::endl; // 2
    // 用下标访问方式修改键值对
    id2grade["202200002"] = 95;
    id2grade["DZ00001"] = 100;
    std::cout << id2grade["202200002"] << std::endl; // 95
    std::cout << id2grade["DZ00001"] << std::endl; // 100
    std::cout << id2grade.size() << std::endl; // 3
    return 0;
}
