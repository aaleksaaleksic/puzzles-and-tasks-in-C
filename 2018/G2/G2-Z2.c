#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int validPos(int brojX, int brojY, int n){
    return (brojX > 0 || brojX < n -1 || brojY > 0 || brojY < n -1)? 1 : 0;
}

void pom(int n, int matrica[n][n],int matricaB[n][n]){
    int sum = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){

        }
    }








}




int main(){
    int n;
    scanf("%d",&n);
    int matrica[n][n];

    //ucitavanje matrice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&matrica[i][j]);
        }
    }
    int matricaB[n][n];
    return 0;
}
/*n = 3
5 3 6 1 13 -2
3 5 1 9 3 13
2 1 3 2 9 -1
 */