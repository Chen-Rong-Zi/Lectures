#include <iostream>
using namespace std;
struct Node{
    int content;
    Node *next;
};

Node *deleteed_max(Node *head){
    int max = head->content;
    Node *pnode = head;
    for ( ; pnode != NULL; pnode = pnode->next )
    {
        if ( max < pnode->content )
            max = pnode->content;
    }

    Node **ppnode = &head;
    for ( ; (*ppnode)->content != max; ppnode = &(*ppnode)->next ){}
    *ppnode = (*ppnode)->next;
    return head;
}

int main(){
    Node *head = NULL, *tail = NULL;
    int x;
    while(cin >> x){
        Node *p = new Node;
        p->content = x;
        p->next = NULL;
        if(head == NULL){
            head = tail = p;
        }
        else{
            tail->next = p;
            tail = p;
        }
    }
    head = deleteed_max(head);
    Node *p = head;
    while (p != NULL){
        cout << p->content << endl;
        p = p->next;
    }
    return 0;
}
