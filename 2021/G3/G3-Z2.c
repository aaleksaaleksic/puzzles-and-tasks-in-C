#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void loadMatrix(int n,int m,int matrix[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int n,int m,int matrix[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int isPalindrome(int kolona,int n,int m,int matrix[n][m]){
    int flag;
    for(int i = 0; i < n;i++){
        if(matrix[i][kolona] == matrix[n-1-i][kolona]){
            flag = 1;
        }else{
            flag = 0;
        }
    }
    return flag;
}
int maxElement(int kolona,int n,int m, int matrix[n][m]){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][kolona] > max){
                max = matrix[i][kolona];
            }
        }
    }
    return max;
}

void rotate(int brojRotacija,int kolona,int n, int m, int matrix[n][m]){
    for(int v = 0; v < brojRotacija;v++){
        int temp = matrix[n-1][kolona];
        for(int i = n-1; i > 0;i--){
            matrix[i][kolona] = matrix[i-1][kolona];
        }
        matrix[0][kolona] = temp;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int matrica[n][m];
    loadMatrix(n,m,matrica);
    printMatrix(n,m,matrica);
    int rotacija = 0;
    for(int x = 0; x < m; x++){
        printf("KOLONA: %d,MAX ELEMENT: %d\n",x, maxElement(x,n,m,matrica));
        if(isPalindrome(x,n,m,matrica)){
            printf("JESTE PALINDROM\n");
        }else{
            printf("NIJE PALINDROM,elemente rotiram za %d pozicija\n", maxElement(x,n,m,matrica));
            rotacija = maxElement(x,n,m,matrica);
            rotate(rotacija,x,n,m,matrica);
        }
    }
    printMatrix(n,m,matrica);
/*
4 5
1 2 2 2     6 2 1 2
6 3 1 1     7 3 3 1
5 8 1 1     1 8 1 1
6 3 3 1     6 3 2 1
7 2 1 2     5 2 1 2

 5 4
 1 2 2 2
 6 3 1 1
 5 8 1 1
 6 3 3 1
 7 2 1 2
 */
    return 0;
}