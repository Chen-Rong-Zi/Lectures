#include <iostream>
#include <assert.h>
using namespace std;

struct Node{
    int cost;
    Node *next; // 下一个节点
};

void print_node(Node *head) {
    if ( (head == NULL) ) return;
    while ( head != NULL ){
        printf(" %d", head->cost);
        head = head->next;
    }
    printf("\n");
    return;
}

Node *arrange(Node *head){
    if ( head == NULL || head->next == NULL ) return head;

    /*  arrange remainning list  */
    head->next = arrange(head->next);

    /*  get the second node address  */
    Node *next_head = head->next;
    Node **walk = &next_head;

    /*  skip nodes that have smaller cost  */
    while ( ((*walk) != NULL) && (*walk)->cost < head->cost )
        walk = &((*walk)->next);

    head->next = *walk;
    *walk = head;
    return next_head;
}
void test(int vals[], int n){

    auto head = new Node;
    auto tail = head;
    tail->cost = vals[0];
    for(int i=1; i<n; i++){
        tail->next = new Node;
        tail = tail->next;
        tail->cost = vals[i];
    }
    tail->next = nullptr;
    Node **ptrs = new Node*[n];
    tail = head;
    for(int i=0; i<n; i++){
        ptrs[i] = tail;
        tail = tail->next;
    }
    head = arrange(head);
    tail = head;
    for(int i=0; i<n; i++){
        assert(tail != nullptr);
        cout << tail->cost << " ";
        // Check that you must not have modified the value of the node or created a new node
        bool pass = false;
        for(int j=0; j<n; j++){
            if(tail == ptrs[j]){
                assert(tail->cost == vals[j]);
                pass = true;
                break;
            }
        }
        assert(pass);
        tail = tail->next;
    }
    // check length
    assert(tail == nullptr);
    delete[] ptrs;
}
int main()
{
    int n;
    cin >> n;
    int* vals = new int[n];
    for(int i=0; i<n; i++){
        cin >> vals[i];
    }
    test(vals, n);
    delete[] vals;
    return 0;
}

