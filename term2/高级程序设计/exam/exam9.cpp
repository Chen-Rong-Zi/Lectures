# include "List.h"
# include <string>
# include <self/functional.h>

using namespace std;
using namespace util;

List::List()
{
    this->size_ = 0;
    this->head.next = &head;
    this->head.back = &head;
}

List::List(const List &lst)
{
    if ( &(lst.head) == &(this->head) )
        return;

    this->size_ = 0;
    this->head.next = &head;
    this->head.back = &head;

    ListNode *pwalk = lst.head.next;
    while ( 1 ) {
        if ( pwalk == &(lst.head) )
            break;
        else {
            this->push_back(pwalk->e);
            pwalk = pwalk->next;
        }
    }
}

List::~List()
{
    ListNode *pwalk = this->head.next;
    while ( 1 ) {
        if ( pwalk == &(this->head) )
            return;
        else {
            ListNode *temp = pwalk;
            pwalk = pwalk->next;
            delete temp;
        }
    }
}

void List::operator=(const List &lst)
{
    if ( &(lst.head) == &(this->head) )
        return;

    ListNode *pwalk = lst.head.next;
    while ( 1 ) {
        if ( pwalk == &(lst.head) )
            break;
        else {
            this->push_back(pwalk->e);
            pwalk = pwalk->next;
        }
    }
}

bool List::push_front(const Element &e)
{
    ListNode *pNode = new ListNode(e);
    pNode->next = this->head.next;
    this->head.next  = pNode;

    pNode->back = &(this->head);
    pNode->next->back = pNode;

    this->size_ += 1;
    return true;
}

bool List::push_back(const Element &e)
{
    ListNode *pNode = new ListNode(e);
    pNode->back = this->head.back;
    this->head.back = pNode;

    pNode->next = &(this->head);
    pNode->back->next = pNode;

    this->size_ += 1;
    return true;
}

bool List::pop_front()
{
    if ( this->size() <= 1 )
        return false;
    ListNode *temp = this->head.next;
    this->head.next = this->head.next->next;
    this->head.next->back = &(this->head);
    delete temp;
    return true;
}

bool List::pop_back()
{
    if ( this->size() == 0 )
        return false;
    ListNode *temp = this->head.back;
    this->head.back       = this->head.back->back;
    this->head.back->next = &(this->head);
    delete temp;
    return true;
}

bool List::remove(const Element &e)
{
    ListNode *pwalk = this->head.next;
    bool deleteLeastOne = false;
    while ( 1 ) {
        if ( pwalk == &(this->head) ) {
            break;
        }
        else if ( pwalk->e == e ) {
            ListNode *temp = pwalk;
            pwalk->back->next = pwalk->next;
            pwalk->next->back = pwalk->back;
            pwalk = pwalk->next;
            this->size_ -= 1;
            deleteLeastOne = true;
            delete temp;
        }
        else {
            pwalk = pwalk->next;
        }
    }
    return deleteLeastOne;
}

bool List::insert(const Element &e, ListNode *ln)
{
    ListNode *aNode = new ListNode(e);
    aNode->next = ln->next;
    ln->next    = aNode;

    aNode->back = ln;
    aNode->next->back = aNode;
    this->size_ += 1;
    return true;
}

void List::erase(ListNode *ln)
{
    ln->back->next = ln->next;
    ln->next->back = ln->back;
    this->size_ -= 1;
    delete ln;
}

ListNode *List::operator[](size_t i)
{
    ListNode *pwalk = this->head.next;
    size_t index = i;
    while ( 1 ) {
        if ( pwalk == &(this->head) )
            break;
        else if ( index == 0 ) {
            return pwalk;
        }
        else {
            pwalk = pwalk->next;
            index -= 1;
        }
    }
    return nullptr;
}

void List::print()
{
    ListNode *pwalk = this->head.next;
    while ( 1 ) {
        if ( pwalk == &(this->head) ) {
            std::cout << std::endl;
            break;
        }
        else {
            std::cout << ' ' << pwalk->e.num;
            pwalk = pwalk->next;
        }
    }
}

/**
 * 测试push_front push_back
 * 注意:同样需要保证构造函数、析构函数和print正确实现
 */

void test1()
{
    List l;
    l.push_front({2});
    l.push_back({3});
    l.push_front({1});
    l.push_back({4});
    l.print();
}
/** 输出
 * 1 2 3 4
 */
/**
 * 测试pop_front pop_back
 */
void test2()
{
    List l;
    l.push_back({1});
    l.push_back({2});
    l.pop_front();
    l.print();
    l.push_back({4});
    l.push_front({3});
    l.pop_back();
    l.print();
}
/** 输出
 * 2
 * 3 2
 */
/**
 * 测试pop_front pop_back
 */
void test3()
{
    List l;
    l.push_back({7890});
    l.pop_back();
    l.pop_front();
    l.push_front({2});
    l.push_back({3});
    l.push_front({1});
    l.push_back({4});
    l.print();
    l.pop_front();
    l.pop_back();
    l.print();
    l.pop_back();
    l.pop_front();
    l.print();
}
/** 输出
 * 1 2 3 4
 * 2 3
 *
 */
/**
 * 测试remove
 */
void test4()
{
    List l;
    l.push_front({1});
    l.push_front({2});
    l.push_front({3});
    l.push_front({1});
    l.push_front({3});
    l.push_front({1});
    l.print();
    l.remove({1});
    l.print();
    l.remove({2});
    l.print();
}
/** 输出
 * 1 3 1 3 2 1
 * 3 3 2
 * 3 3
 */
/**
 * 测试insert和earse
 */
void test5()
{
    List l;
    l.push_back({1});
    l.push_back({2});
    l.push_back({3});
    l.push_back({4});
    l.push_back({5});
    l.push_back({6});
    l.print();
    l.insert({23},l[1]);
    l.insert({56},l[5]);
    l.print();
    l.erase(l[5]);
    l.erase(l[1]);
    l.print();
}
/** 输出
 * 1 2 3 4 5 6
 * 1 2 23 3 4 5 56 6
 * 1 23 3 4 56 6
 */
/**
 * 测试拷贝构造函数和赋值操作符
 */
void test6()
{
    List l;
    l.push_back({1});
    l.push_back({2});
    l.push_back({3});
    l.push_back({4});
    l.push_back({5});
    l.push_back({6});
    List l_cp=l;
    l.remove({4});
    l.remove({2});
    List l_assign;
    l_assign=l;
    l_cp.print();
    l_assign.print();
}
/** 输出
 * 1 2 3 4 5 6
 * 1 3 5 6
 */

int main(const int arg_number, const char **arg_value) {
    try {
        throw List();
        throw 1;
        throw string("string");
    } catch (string) {
        print("found a error");
    } catch (int) {
        print("found a int");
    } catch (List) {
        print("found a list");
    }
    test6();
    return 0;

