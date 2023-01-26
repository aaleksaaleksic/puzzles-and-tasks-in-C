
#include <stdio.h>
#include <limits.h>
/**
 Ulaz: n = 6

8 7 2 6 3 9
3 9 5 8 4 1
4 7 2 9 5 3
12 9 4 10 7 15
8 6 3 10 4 5
11 6 8 10 5 3

 */

void inputMatrix(int mat[100][100],int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
int jeProst(int n){
    if(n == 1)
        return 0;
    for(int i = 2; i <= n/2;i++){
        if(!(n % i))
            return 0;
    }
    return 1;
}

int proveriPodmatricu(int dim_x,int dim_y,int x,int y,int mat[100][100]){
    for(int i = x,j = y; i < x + dim_x; i++){
        if(jeProst(mat[i][j]))
            return 0;
    }
    for(int i = x,j = y; j < y + dim_y; j++){
        if(jeProst(mat[i][j]))
            return 0;
    }
    for(int i = x + dim_x - 1,j = y; j < y + dim_y; j++){
        if(jeProst(mat[i][j]))
            return 0;
    }
    for(int i = x,j = y + dim_y - 1; i < x + dim_x; i++){
        if(jeProst(mat[i][j]))
            return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    inputMatrix(mat,n);

    int max_dim = 0;
    int max_i,max_j;
    int dim_i,dim_j;

    for(int dim_x = 1; dim_x <= n; dim_x++){
        for(int dim_y = 1; dim_y <= n; dim_y++){
            for(int i = 0; i <= n - dim_x; i++){
                for(int j = 0; j <= n - dim_y; j++){
                    if(proveriPodmatricu(dim_x,dim_y,i,j,mat)){
                        if(dim_x*dim_y > max_dim){
                            max_dim = dim_x * dim_y;
                            max_i = i;
                            max_j = j;
                            dim_i = dim_x;
                            dim_j = dim_y;
                        }

                    }
                }
            }
        }
    }

    for(int i = max_i; i < max_i + dim_i; i++){
        for(int j = max_j; j < max_j + dim_j; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}