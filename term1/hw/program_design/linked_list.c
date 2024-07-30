#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

typedef struct Node{
    int content;
    Node *next;
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
//     printf("*pp = %p (*pp)->content = %d\n", *pp, (*pp)->content);
    return ((*phead) == NULL)? -1 : 0;
}

int takein(Node **phead){
    int input = 0;
    scanf(" %d", &input);
    while ( input != -999 ){
        printf("input = %d \n", input);
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
    for ( ; walk != NULL; walk = walk->next )
        lenth += 1;

    int n = 0;
    for ( walk = head; n < lenth - k; ++n, walk = walk->next );
    printf("%d",  walk->content);
    return 0;
}

int main(void) {
    Node *head = NULL;
    int k = 0;
    takein(&head);
    scanf(" %d", &k);
    print(head);
    output(head, k);
    return 0;
}
