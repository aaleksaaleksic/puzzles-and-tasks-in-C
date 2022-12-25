//
// Created by Korisnik on 12/25/2022.
//
/*
 *
 * 4
2 2 13 13
5 1 7 19
0 3 1 3
1 2 3 4
 */
#include <stdio.h>
#include <limits.h>

void najveciNeparanUVrsti(int i,int n, int mat[100][100]){
    int flag = 0;
    int cnt = 0;
    int max = INT_MIN;
    for(int j = 0; j < n; j++){
        if(mat[i][j] % 2 && mat[i][j] > max){
            flag = 1;
            max = mat[i][j];
        }
    }
    if(flag == 1){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == max){
                cnt++;
            }
    }
        printf("red %d : %d %d\n",i + 1,max,cnt);
}

    }
void najmanjiParniUKoloni(int j,int n, int mat[100][100]){
    int flag = 0;
    int cnt = 0;
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(!(mat[i][j] % 2) && mat[i][j] != 0 && mat[i][j] < min){
            flag = 1;
            min = mat[i][j];
        }
    }
    if(flag == 1){
        for(int i = 0; i < n; i++){
            if(mat[i][j] == min){
                cnt++;
            }
        }
        printf("kolona %d : %d %d\n",j + 1,min,cnt);
    }

}

int main(){
    int n;
    scanf("%d", &n);
    int mat[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        najveciNeparanUVrsti(i,n,mat);
    }
    for(int j = 0; j < n; j++){
        najmanjiParniUKoloni(j,n,mat);
    }



    return 0;
}
