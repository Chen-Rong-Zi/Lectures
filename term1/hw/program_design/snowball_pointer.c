# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    char unit_type; // 单元类型
    struct Node *top; // 上面的节点
    struct Node *bottom; // 下面的节点
    struct Node *left; // 左边的节点
    struct Node *right; // 右边的节点
}Node;

int takein(Node **phead, int row, int col) {
    Node *pleft_node = NULL, *ptop_node = NULL;
    for ( int i = 0; i < row; ++i )
    {
        for ( int j = 0; j < col; ++j )
        {
            Node *pnode = (Node *) malloc(sizeof(Node));
            scanf(" %c", &pnode->unit_type);
            if ( i == 0 && j == 0 ) *phead = pnode;

            /*  ther is some text  */
            and we will do that
            pnode->left = pleft_node;
            (pnode->left != NULL) && (pnode->left->right = pnode);
            pnode->top = ptop_node;
            (pnode->top != NULL) && (pnode->top->bottom = pnode);

            pleft_node = pnode;
            ( ptop_node != NULL ) && (ptop_node = ptop_node->right);
        }
        while ( pleft_node->left != NULL ) pleft_node = pleft_node->left;
        ptop_node = pleft_node;
        pleft_node = NULL;
    }
    return 0;
}

Node *get_snowball_grid() {
    int row = 0, col = 0;
    scanf(" %d %d", &row, &col);

    Node *head = NULL;
    takein(&head, row, col);
    Node *pfirst_node = head;

    while ( pfirst_node != NULL )
    {
        /*  do some stuff  */
        for ( int j = row - 2; j >= 0; --j )
        {
            Node *walk = pfirst_node;
            for ( int k = 0; k < j; ++k ) walk = walk->bottom;

            if ( walk->unit_type == '.' || walk->unit_type == '#' ) continue;

            else if ( walk->bottom->unit_type == '.' && walk->unit_type == 'o' ){
                while ( walk->bottom != NULL && walk->bottom->unit_type == '.' ){
                    walk->bottom->unit_type = 'o';
                    walk->unit_type = '.';
                    walk = walk->bottom;
                }
            }
        }
        pfirst_node = pfirst_node->right;
    }
    return head;
}

int main(void) {
    get_snowball_grid();
}
