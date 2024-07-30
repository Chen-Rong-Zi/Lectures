#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
	double d = 0;
    int array[64] = {0}, i = 0;
	cin >> d;
    unsigned long *pd = (unsigned long *)&d;

    while ( *pd != 0 )
    {
        if ( *pd % 2 == 0 )
            array[i] = 0;
        else
            array[i] = 1;
        *pd = *pd / 2;
        ++i;
    }

    for ( i = 63; i >= 0; --i )
    {
        cout << array[i];
    }
	
	return 0;
}
