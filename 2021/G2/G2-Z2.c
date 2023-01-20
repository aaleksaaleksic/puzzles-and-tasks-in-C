#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void loadMatrix(int n, int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int n, int matrix[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortCollumns(int n, int matrix[n][n]){
    for(int kolona = 0; kolona < n; kolona++){
        for(int element1 = 0; element1 < n - 1; element1++){
            for(int element2 = element1 + 1; element2 < n; element2++){
                if(matrix[element2][kolona] < matrix[element1][kolona]){
                    swap(&matrix[element2][kolona],&matrix[element1][kolona]);
                }
            }
        }
    }
}
void swapCollumn(int n, int matrix[n][n], int kolonaBig, int kolonaSmall){
    for(int i = 0; i < n; i++){
        swap(&matrix[i][kolonaSmall],&matrix[i][kolonaBig]);
    }
}

void swapAccordingToRowNMinus1(int n, int matrix[n][n]){
    for(int z = 0; z < n - 1; z++){
        for(int zed = z+1; zed < n; zed++){
            if(matrix[n-1][z] < matrix[n-1][zed]){
                swapCollumn(n,matrix,z,zed);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    loadMatrix(n,matrix);
    printMatrix(n,matrix);
    sortCollumns(n,matrix);
    printMatrix(n,matrix);
    swapAccordingToRowNMinus1(n,matrix);
    printMatrix(n,matrix);
    return 0;
}

/*
5
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2
 */