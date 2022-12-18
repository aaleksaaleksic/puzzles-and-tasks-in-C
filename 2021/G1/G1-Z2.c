#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void loadMatrix(int n,int m, int matrix[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int matrica[n][m];
    loadMatrix(n,m,matrica);
    int dimX = 1;
    int dimY = 1;
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int edge = matrica[i][j];
            printf("ivica u pitanju : %d\n",edge);

            for(int i1 = i; i1 < n-1; i1++){
                for(int j1 = j+1; j1 < m-1; j1++){
                    //printf("trenutna ivica %d, element gledanja : %d\n",edge,matrica[i1][j1]);
                    if(edge != matrica[i1][j1]){
                        flag = 1;
                        dimY++;
                    }else{
                        flag = 0;
                        dimY = 1;
                    }
                }
                if(flag){
                    dimX++;
                }else{
                    dimX = 1;
                }
            }

            if(dimY >= 3 && dimX >= 3 && dimX == dimY){
                printf("i: %d j: %d, dimenzija x: %d, y: %d",i,j,dimX,dimY);
            }
        }
    }












    return 0;
}
/*

4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2




 */