#include <iostream>
using namespace std;

struct Node {
    int val; // It will not be used in this question.
    Node *next;
};

//---------------------edit your code here--------------------

int find_pointer(Node *array[100000], Node *pointer) {
    for ( int i = 0;  array[i] != NULL; ++i ) {
        if ( array[i] == pointer )
            return i;
    }
    return -1;
}

int get_ring_length(Node* head){
    Node *array[100000] = {};
    for ( int i = 0; head != NULL; ++i, head = head->next )
    {
        int index = find_pointer(array, head);
        if ( index != -1 ) return i - index;
        array[i] = head;
    }
    return 0;
}

//------------------------------------------------------------

Node* example1() {
    /*
    n1 -> n2 -> n3 -> n4
    */
    Node *array = (Node *)malloc(4*sizeof(Node));
    Node *n1,*n2,*n3,*n4;
    n1 = &array[0];
    n2 = &array[1];
    n3 = &array[2];
    n4 = &array[3];
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    return n1;
}

Node* example2() {
    /*
    n1 -> n2 -> n3 -> n4 -> n2 -> ...
    */
    Node *array = (Node *)malloc(4*sizeof(Node));
    Node *n1,*n2,*n3,*n4;
    n1 = &array[0];
    n2 = &array[1];
    n3 = &array[2];
    n4 = &array[3];
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    return n1;
}

Node* test();

int main()
{
//     Node* head = test();
    // Uncomment the following to get sample input
//     Node* head = example1();
    Node* head = example2();

    cout << get_ring_length(head) << endl;
    free(head);
    return 0;
}

Node* test() {
    // 这是测试样例的构造方式，请不要尝试改动下面的任何代码
    unsigned char* p = (unsigned char*)malloc(0x1000full-15);
    for(auto i=0; i<0x123full-15; i++){
        *(p+i)=0;
    }
    void* ret, *cur = nullptr;
    int x;
    cin >> x;
    cur = p+x*((0x1full+1)>>1);
    ret = cur;
    while(!cin.eof()){
        cin >> x;
        *(unsigned char**)((unsigned char*)cur+(0x4full - 10 >> 3)) = p+x*((0x1full+1)>>1);
        cur = *(unsigned char**)((unsigned char*)cur+(0x3full + 1 >> 3));
    }
    return (Node*)ret;
}
