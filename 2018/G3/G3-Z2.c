#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void nova_matrica(int n, int matrica[n][n]){
    int matricaB[n][n];
    int max;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            max = INT_MIN;

            for(int i1 = 0; i1 < n; i1++){
                for(int j1 = 0; j1 < n; j1++){
                    if(i1 != i && j1 != j){
                        if(matrica[i1][j1] > max){
                            max = matrica[i1][j1];
                            //printf("MAX %d\n",max);
                        }
                    }
                }
            }
            matricaB[i][j] = matrica[i][j] + max;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%-4d ",matricaB[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int matrica[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    nova_matrica(n,matrica);
    return 0;
}
/*
 * 3
 * 5 3 7
 * 3 5 1
 * 2 1 3
 *
 *
 *
 * */
