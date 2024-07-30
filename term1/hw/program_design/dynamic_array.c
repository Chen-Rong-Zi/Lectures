# include <stdlib.h>
# include <stdio.h>
typedef struct{
    int *p;
    int size;
    int capacity;
}Array;

Array *create_array(int value){
    // write your code here......
    Array *pArray;

    pArray = (Array *) malloc(sizeof(Array ));
    pArray->p = (int *) malloc(sizeof(int) * 400);
    *(pArray->p) = value;
    pArray->size = 1;
    pArray->capacity = 1;
    return pArray;
}

void push_back(Array* arr, int value){
    // write your code here......
    if ( (arr->size + 1) > (arr->capacity) )
    {
        int *temp_array = (int *) malloc((arr->size) * 2 * sizeof(int));
        for ( int i = 0; i < arr->size; ++i )
        {
            temp_array[i] = arr->p[i];
        }
//         free(arr->p);
        arr->p = temp_array;
        arr->capacity = arr->capacity * 2;
    }
    arr->p[arr->size] = value;
    arr->size += 1;
}

void pop(Array *arr){
    arr->size -= 1;
}

int get_size(Array *arr){
    return arr->size;
}

int get_capacity(Array *arr){
    return arr->capacity;
}

int main(int arg_number, char **arg_value){
    Array *temp = create_array(0);
    printf("sizeof(temp) = %ld\n", sizeof(temp));
    printf("sizeof(Array) = %ld\n", sizeof(*temp));
    return 0;
}
