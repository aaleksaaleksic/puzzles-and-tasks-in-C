#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gornji(int n, int i){
    int gornji = 0;
    if(i % 2){
        gornji = i / 2 + 1;
    }else{
        gornji = n - i / 2 + 1;
    }
    printf("ITERACIJA %d, GORNJI : %d\n",i,gornji);
    return gornji;
}

int donji(int n, int i){
    int donji = 0;
    if(i%2){
        donji = (n - i / 2) * (n-i/2);
    }else{
        donji = (i/2) * (i/2);
    }
    printf("ITERACIJA %d, DONJI : %d\n",i,donji);
    return donji;
}
double rek(int n, int i){
    if(i == n){
        return sqrt(gornji(n,i) * 1.0 /donji(n,i));
    }
    return sqrt(gornji(n,i) * 1.0 / donji(n,i) + rek(n,i+1));
}
double iter(int n){
    double res = sqrt(gornji(n,n) *1.0 / donji(n,n));
    for(int i = n-1; i >= 1; i--){
        res = sqrt((gornji(n,i) * 1.0  / donji(n,i)) + res);
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

