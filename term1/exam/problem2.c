# include <stdio.h>
# include <stdlib.h>

typedef struct Point Pt;
struct Point
{
    int lon;    // 0 < lon <= 18000
    Pt* next;
};

Pt *takein() {
    int lon = 0;
    Pt *head = NULL;

    scanf("%d", &lon);
    while ( lon != -1 )
    {
        Pt *new_pt = (Pt *) calloc(1, sizeof(Pt));
        Pt **phead = &head;
        while ( *phead != NULL )
            phead = &((*phead)->next);

        new_pt->lon = lon;
        new_pt->next = *phead;
        *phead = new_pt;
        scanf("%d", &lon);
    }
    return head;
}

double averge(Pt **phead) {
    double sum = 0;
    int count = 0;
    while ( *phead != NULL )
    {
        sum += (*phead)->lon;
        count += 1;
        phead = &((*phead)->next);
    }
    return sum / count;
}

Pt *check(Pt *head, double avg) {
    Pt **phead = &head;
    while ( *phead != NULL ){
        if ( (*phead)->lon == 0 ) {
            (*phead) = (*phead)->next;
            return head;
        }
        phead = &((*phead)->next);
    }

    phead = &head;
    while ( *phead != NULL ) {
        if ( (*phead)->lon > avg ) {
            (*phead) = (*phead)->next;
            return head;
        }
        phead = &((*phead)->next);
    }
    return head;
}

Pt *sort(Pt *head) {
    if ( head == NULL || head->next == NULL )
        return head;
    Pt *head_next = sort(head->next);
    Pt **phead = &head_next;
    while ( *phead != NULL && (*phead)->lon <= head->lon )
        phead = &((*phead)->next);

    head->next = *phead;
    *phead = head;
    return head_next;
}

int main(int arg_number, char **arg_value) {
    Pt *head = takein();
    double avg = averge(&head);
    head = check(head, avg);
    head = sort(head);

    Pt **phead = &head;
    while ( *phead != NULL ) {
        printf("%d", (*phead)->lon);
        if ( (*phead)->next != NULL )
            printf(" ");
        phead = &((*phead)->next);
    }
    return 0;
}
