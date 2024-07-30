// MyMap.h
// 注意：当前文件为MyMap.h，请在MyMap.cpp中实现各成员函数！
// 注意：当前文件为MyMap.h，请在MyMap.cpp中实现各成员函数！
// 注意：当前文件为MyMap.h，请在MyMap.cpp中实现各成员函数！
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

class Map {
private:
    int capacity; // 哈希表的容量
    int _size; // 当前元素数量
    std::vector<std::list<std::pair<std::string, int>>> table; // 哈希表
    /*
     * 数据成员
     * 不做规定，由你自己实现
     */
inline unsigned hashFunc(const string & s)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        hash = hash * seed + (s[i]);
    }

    return (hash & 0x7FFFFFFF) % capacity;
}
public:
    Map(); // 构造函数，构造一个空映射表，初始化数据成员
   ~Map(); // 析构函数，释放申请的内存空间

   bool insert(const string& key, int value); // 插入键值到映射表中
   // 成功插入返回true；若对应键已存在旧值，插入失败，返回false

   bool erase(const string &key); // 删除该键的键值对
   // 成功删除返回true；若不存在对应键的键值对，删除失败，返回false

   bool find(const string &key); // 返回映射表中是否含有对应键的键值对

   int & operator[](const string &key); // 数组下标访问操作符重载
   // 可以通过下标访问的方式直接用键得到值的引用
   // 需要注意的是，如果用下标访问的方式访问了不存在的key，你需要为该key创建一个键值对
   // 此法创建的值初始为0，你需要返回该值的引用

   int size() const; // 返回映射表中当前记录的键值对总数
};
