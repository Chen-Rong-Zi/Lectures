#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Node{
    int content;
    struct Node *next;
}Node;

Node *make_node(int input){
    Node *pnode = (Node *)malloc(sizeof(Node));
    pnode->content= input;
    pnode->next= NULL;
    return pnode;
}

int append(Node **phead, Node *pnode) {
    Node **pp = phead;
    while ( (*pp) != NULL )
        pp = &((*pp)->next);
    (*pp) = pnode;
    return ((*phead) == NULL)? -1 : 0;
}

int takein(Node **phead){
    int input = 0;
    scanf(" %d", &input);
    while ( input != -999 ){
        Node *pnew_node = make_node(input);
        append(phead, pnew_node);
        scanf(" %d", &input);
    }
    return ((*phead) == NULL)? -1 : 0;
}

int print(Node *head) {
    while ( head != NULL ){
        printf("%d ", head->content);
        head = head->next;
    }
    printf("\n");
    return 0;
}

int output(Node *head, int k) {
    int lenth = 0;
    Node *walk = head;
    for ( ; walk != NULL; walk = walk->next ) lenth += 1;

    int n = 0;
    for ( walk = head; n < lenth - k; ++n, walk = walk->next );
    printf("%d",  walk->content);
    return 0;
}

int insert(Node **phead, Node *pnode) {
    for ( ; (*phead) != NULL && (*phead)->content <= pnode->content; phead = &((*phead)->next) );
    pnode->next = (*phead);
    (*phead) = pnode;
    return 0;
}

int merge(Node **phead1, Node *head2) {
    Node *backup;
    while ( head2 != NULL ){
        backup = head2->next;
        insert(phead1, head2);
        head2 = backup;
    }
    return 0;
}

int main(void) {
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head_merge = NULL;
    takein(&head1);
    takein(&head2);
    merge(&head1, head2);
    head_merge = head1;
    print(head_merge);
    return 0;
}
