//
// Created by Korisnik on 12/15/2022.
//

#include <stdio.h>
#include <limits.h>
/**
2 3 5 7 5
3 5 9 2 8
1 8 2 5 6
7 3 4 5 4
1 3 9 6 5
 */

int vratiNajmanji(int x,int y,int n,int mat[][100]){

    int min = INT_MAX;


    for(int i = x,j = 0; j < n; j++){
        if(mat[i][j] < min)
            min = mat[i][j];


        }
    for(int i = 0,j = y; i < n; i++){
        if(mat[i][j] < min)
            min = mat[i][j];


    }
   return min;






//    return min;

}

int main(){

    int n;
    scanf("%d", &n);
    int mat[100][100];
    int a[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = vratiNajmanji(i,j,n,mat);


        }
    }




    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d",a[i][j]);

        }
        printf("\n");
    }






    return 0;
}
