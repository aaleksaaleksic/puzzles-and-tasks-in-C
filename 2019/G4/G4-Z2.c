#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
    //ocekuje se da brojevi budu od 0 do 9
    int n;
    scanf("%d",&n);
    int matrica[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    int snake[n*n];//po logici kvadratne matrice
    int snake_index = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for (int j = 0; j < n; j++) {
                snake[snake_index] = matrica[i][j];
                snake_index++;
            }
        }else{
            for (int j = n-1; j >= 0; j--) {
                snake[snake_index] = matrica[i][j];
                snake_index++;
            }
        }
    }
    printf("SNAKE SEQ :");
    for(int i = 0; i < snake_index;i++){
        printf(" %d, ",snake[i]);
    }
    int len = 1;
    int maxLen = INT_MIN;
    for(int i = 0; i < snake_index; i++){
        if(snake[i] < snake[i+1]){
            len++;
        } else{
            if(len > maxLen)
                maxLen = len;
            len = 1;
        }
        printf("\nbr1 : %d , br2 :  %d ,len %d",snake[i],snake[i+1],len);
    }
    printf("\nduzina sekvence %d",maxLen);
    return 0;
}
/*
 * 4
3 4 1 6
2 1 3 1
3 4 5 5
2 3 4 5
 *
 *
 *
 */
