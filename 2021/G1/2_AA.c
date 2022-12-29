
#include <stdio.h>
/*
 * 4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2
 */
void popuniMatricu(int n,int m, int mat[100][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}
int isValid(int i, int j, int dim, int mat[100][100]){
    int upper_left = mat[i][j];
    int upper_right = mat[i][j + dim - 1];
    int lower_left = mat[i + dim - 1][j];
    int lower_right = mat[i + dim - 1][j + dim - 1];
    for(int i1 = i; i1 < i + dim; i1++){
        for(int j1 = j; j1 < j + dim; j1++){
            if((i1 == i && j1 == j) || (i1 == i && j1 == j + dim - 1) || (i1 == i + dim - 1 && j1 == j) || (i1 == i + dim - 1 && j1 == j + dim - 1))
                continue;
            if(mat[i1][j1] == upper_left || mat[i1][j1] == upper_right || mat[i1][j1] == lower_left || mat[i1][j1] ==lower_right)
                return 0;

        }
    }
//    printf("(%d,%d) ---> %d X %d\n",i,j,dim,dim);
    return 1;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[100][100];
    popuniMatricu(n,m,mat);
    for(int dim = 3; dim <= n && dim <= m; dim++){ ///PRAVOUGAONA MATRICA JE MORA I USLOV ZA M
        for(int i = 0; i <= n - dim; i++){
            for(int j = 0; j <= m - dim; j++){
                if(isValid(i,j,dim,mat))
                    printf("(%d,%d) ---> %d X %d\n",i,j,dim,dim);
            }
        }
    }
    return 0;
}