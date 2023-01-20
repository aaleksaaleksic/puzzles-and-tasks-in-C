

#include <stdio.h>
#include <limits.h>
/**
 Primer (n = 6):
Ulaz:
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
int najveciProst(int n,int mat[100][100]){
     int max = INT_MIN;
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
             if(jeProst(mat[i][j]) && mat[i][j] > max)
                 max = mat[i][j];
         }
     }
    return max;
}
int najmanjiProst(int n,int mat[100][100]){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(jeProst(mat[i][j]) && mat[i][j] < min)
                min = mat[i][j];
        }
    }
    return min;
}
int proveriPodmatricu(int x,int y,int min,int max,int dim_x,int dim_y,int mat[100][100]){
     int flag_min = 0;
     int flag_max = 0;
    for(int i = x; i < x + dim_x; i++){
        for(int j = y; j < y + dim_y; j++){
            if(mat[i][j] == min)
                flag_min++;
            if(mat[i][j] == max)
                flag_max++;
        }
    }
    if(flag_min != 0 && flag_max != 0)
        return 1;
    return 0;

 }
int main(){
    int n;
    scanf("%d",&n);
    int mat[100][100];
    inputMatrix(mat,n);
    int min = najmanjiProst(n,mat);
    int max = najveciProst(n,mat);
    int min_dim = INT_MAX;
    int min_x;
    int min_y;
    int min_i,min_j;

    for(int dim_x = 1; dim_x <= n; dim_x++){
        for(int dim_y = 1; dim_y <= n; dim_y++){
            for(int i = 0; i <= n - dim_x; i++){
                for(int j = 0; j <= n - dim_y; j++){
                    if(proveriPodmatricu(i,j,min,max,dim_x,dim_y,mat)){
                        if(dim_x * dim_y < min_dim){
                            min_dim = dim_x * dim_y;
                            min_x = dim_x;
                            min_y = dim_y;
                            min_i = i;
                            min_j = j;
                        }
                    }
                }

            }
        }
    }

    for(int i = min_i; i < min_i + min_x; i++){
        for(int j = min_j; j < min_j + min_y ; j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }


}
