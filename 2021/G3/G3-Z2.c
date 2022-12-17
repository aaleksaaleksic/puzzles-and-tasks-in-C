#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void loadMatrix(int n,int m, int matrix[m][n]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int n,int m, int matrix[m][n]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}

int isPalindrome(int n,int m, int matrix[m][n],int column){
    for(int i = 0; i < n; i++){
        if(matrix[i][column] != matrix[n-1-i][column])
            return 0;
    }
    return 1;
}

int maxN(int n,int m, int matrix[m][n]){


}

void rotate(int n,int m, int matrix[m][n],int k){

}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int matrica[m][n];
    for(int kolona = 0; kolona < m; kolona++){
        if(isPalindrome(n,m,matrica,kolona) == 0)
            rotate(n,m,matrica,kolona);
    }
    printMatrix(n,m,matrica);

/*
4 5
1 2 2 2     6 2 1 2
6 3 1 1     7 3 3 1
5 8 1 1     1 8 1 1
6 3 3 1     6 3 2 1
7 2 1 2     5 2 1 2

 4 5
 1 2 2 2
 6 3 1 1
 5 8 1 1
 6 3 3 1
 7 2 1 2





 */
    return 0;
}