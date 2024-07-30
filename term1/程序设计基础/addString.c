# include<stdio.h>

char res[100] = {'\0'};

void swap(char *x, char *y) {
    char i = 0;
    i  = *x;
    *x = *y;
    *y = i;
}


void combineString(char s1[], char s2[]){
    int pos = 0;
    for ( pos = 0; s1[pos] != '\0'; ++pos){
        res[pos] = s1[pos];
    }
    for ( int i = 0; s2[i] != '\0'; ++i, ++pos){
        res[pos] = s2[i];
    }
}

int maxIndex(char array[], int start, int end){
    int index = 0;
    for ( int i = start; i < end; ++i){
        if ( array[i+1] > array[index] ){
            index = i+1;
        }
    }
    return index;
}

void selectSort(char array[]){
    int index = 0, i = 0;
    for ( i = 0; array[i] != '\0'; ++i){}
    for (  i = i-1; array[i] != '\0'; --i){
        index = maxIndex(array, 0, i);
        swap(&array[i], &array[index]);
    }
}


int main(void){
    char string1[100] = {'\0'}, string2[100] = {'\0'};
    scanf("%s %s", string1, string2);
    combineString(string1, string2);
    selectSort(res);
    printf("%s", res);
    return 0;
}
