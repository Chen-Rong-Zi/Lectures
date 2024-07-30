# include <stdio.h>
# include <math.h>

int m = 0;
int map1[2][2] = {0};
int map2[128][128] = {0};

void initalize(){
    for ( int i = 0; i < 128; ++i){
        for ( int j = 0; j < 128; ++j){
            map1[i][j] = -1;
            map2[i][j] = -1;
        }
    }
}

void takein(void){
    int temp = 0;
    scanf("%d", &m);
    for ( int i = 0; i < 2; ++i){
        scanf("%d", &map1[i][0]);
        temp = map1[i][0];
        map1[i][0] = temp / 10;
        map1[i][1] = temp % 10;
        map2[i][0] = map1[i][0];
        map2[i][1] = map1[i][1];
    }
}

void fractal(int m){
    if ( m == 0 ){
        return;
    }
    fractal(m-1);
    int shift = pow(2, m);
    for ( int i = shift-1; i != -1; --i ){
        for ( int j = shift-1; j != -1; --j ){
            if ( map2[i][j] == 1 ){
                map2[i * 2][j * 2] = map1[0][0];
                map2[i * 2][j * 2+1] = map1[0][1];
                map2[i * 2+1][j * 2] = map1[1][0];
                map2[i * 2+1][j * 2+1] = map1[1][1];
            }
            else{
                map2[i * 2][j * 2] = 0;
                map2[i * 2][j * 2+1] = 0;
                map2[i * 2+1][j * 2] = 0;
                map2[i * 2+1][j * 2+1] = 0;
            }
        }
    }
}

void output(){
    for ( int i = 0; i < pow(2, m+1); ++i ){
        for ( int j = 0; j < pow(2, m+1); ++j){
            printf("%d", map2[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    initalize();
    takein();
    fractal(m);
    output();
    return 0;
}
