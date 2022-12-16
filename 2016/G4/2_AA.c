//
// Created by Korisnik on 12/16/2022.
//
#include <stdio.h>
/**
2 3 5 2 1
3 5 1 2 1
1 2 2 5 3
7 3 2 5 4
1 3 3 1 5
 */

int vratiZbirSusednih(int x,int y,int n,int mat[100][100]){
    int zbir = 0;
    if(y == 0){
        zbir = mat[x][y + 1];
    }
    else if(y == n - 1)
        zbir = mat[x][y - 1];
    else
        zbir = mat[x][y - 1] + mat[x][y + 1];

    return zbir;
}

int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    int a[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = vratiZbirSusednih(i,j,n,mat);
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

