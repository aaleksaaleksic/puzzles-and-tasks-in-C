#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stepen(int a, int b){
    int res = 1;
    while(b){
        res *= a;
        b--;
    }
    return res;
}

int lijevi(int n,int i){
    int lijevi = 0;
    if(i%2){
        lijevi = stepen((2*n) - i, i%(n/2+1));
    }else{
        lijevi = i;
    }
    //printf("ITERACIJA : %d, LIJEVI : %d \n",i,lijevi);
    return lijevi;
}

int gornji(int n,int i){
    int gornji = 0;
    if(i % 2){
        gornji = i;
    }else{
        gornji = stepen((2*n) - i,i%(n/2+1));
    }
    //printf("ITERACIJA : %d, GORNJI : %d \n\n",i,gornji);
    return gornji;
}

double rek(int n,int i){
    if(i == n){
        return lijevi(n,i) + gornji(n,i);
    }
    return lijevi(n,i) + gornji(n,i) * 1.0 / rek(n,i+1);
}


double iter(int n){
    double res = lijevi(n,n) + gornji(n,n);
    for(int i = n - 1; i >= 1; i--){
        res = lijevi(n,i) + gornji(n,i) * 1.0 / res;
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("Rekurzivno : %lf\n\n",rek(n,1));
    printf("Iterativno : %lf\n",iter(n));

    return 0;
}

