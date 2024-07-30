struct Element
{
    int num; // 或者其他类型
    bool operator==(const Element e) const {
        return this->num == e.num;
    }
};

class ListNode
{
    Element e;
    ListNode *back = nullptr;
    ListNode *next = nullptr;
    ListNode():
    e(Element(-1))
    {};
    ListNode(const Element &ele) {
        this->e.num = ele.num;
    }
    friend class List; // 为便于测评，这里设置为友元
};
