# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
int memory[][10] = {{0, 1}};

bool is_bomb(int x, int y, int bomb[][2], int bomb_amount){
    int i = 0;
    for ( i = 0; i < bomb_amount; ++i){
        if ( x == bomb[i][0] && y == bomb[i][1] )
            return true;
    }
    return false;
}

int solder(int x, int y, int bomb[][2], int bomb_amount){
    int i = 0, j = 0, up = 0, left = 0;
    memory[1][0] = 1;
    memory[0][1] = 1;
    for ( i = 0; i < x; ++i){
        for ( j = 0; j < y; ++j){
            up = ((i-1>=0) && (j >= 0) && !is_bomb(i-1, j, bomb, bomb_amount))? memory[i-1][j] : 0;
            left = ((i>=0) && (j-1 >= 0 && !is_bomb(i-1, j, bomb, bomb_amount)))? memory[i][j-1] : 0;
            memory[i][j] += up + left;
        }
    }
    return memory[x][y];
}

void out(int *array, int row, int column){
    int i = 0, j = 0;
    for ( i = 0; i < row * column; ++i){
            printf("%-6d", *(array+i));
        if ( (i+1) % column == 0 )
            printf("\n");
    }
}

int main(void){
    int x = 0, y = 0, bomb_amount = 0, bomb[10][2] = {0}, i = 0;
    scanf("%d %d %d", &x, &y, &bomb_amount);
    for ( i = 0; i < bomb_amount; ++i){
        scanf("%d %d", &bomb[i][0], &bomb[i][1]);
    }
    printf("%d\n", solder(x, y, bomb, bomb_amount));
    out(memory, 10, 10);
    out(bomb, bomb_amount, 2);
    printf("\n\n");
//     out(&bomb, bomb_amount, 2);
    return 0;
}
