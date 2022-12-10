#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int validneKordinate(int i, int j, int n, int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}
int main(){
    int matrica[10][10];
    int n,m,i,j;
    scanf("%d %d",&n,&m);

    int x[] = {-1,0,1,0};
    int y[] = {0,1,0,-1};

    for(i = 0;i < m; i++){
        for (int j = 0; j < m; j++) {
            matrica[i][j] = -1;
        }
    }
    int smer = 0;
    int br = n;
    ///pocetne kordinate broja u matrici
    i = 0;
    j = m-1;
    int brojac = 1;

    while(brojac <= m * m){
        brojac++;
        int ii = i + y[smer];
        int jj = j + x[smer];
        if(validneKordinate(ii,jj,m,m) && matrica[ii][jj] == -1 ){
            matrica[i][j] = br;
            i = ii;
            j = jj;
            continue;
        }
        smer++;
        smer %= 4;
        br+=2;
        br %= 10;
        matrica[i][j] = br;
        i+= y[smer];
        j += x[smer];
    }
    for(i = 0; i < m;i++){
        for(j = 0; j < m; j++){
            printf(" %d ",matrica[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
 *
 *
3 5
 5  3  3  3  3
 5  3  1  1  1
 5  3  1  9  9
 5  5  5  7  9
 7  7  7  7  9
 */
