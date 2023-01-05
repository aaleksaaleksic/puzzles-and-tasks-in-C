//
// Created by Korisnik on 1/4/2023.
//
#include <stdio.h>
#include <math.h>

int stepen(int i,int n){
    if(i <= n/2)
        return i;
    else if(i == n && n % 2)
        return 1;
    return (i - n/2);
}
int gornji(int i,int n){
    if(i % 2){
        if(i <= n/2)
            return pow(2 * n - i,stepen(i,n));
        return pow(2 * n - i,stepen(i,n));
    }
    return n - i + 1;
}
int donji(int i,int n){
    if(i % 2)
        return n - i + 1;
    else{
        if(i <= n/2)
            return pow(2 * n - i, stepen(i,n));
        return pow(2 * n - i, stepen(i,n));
    }
}

double rek(int i,int n){
    if(i == n)
        return sqrt(gornji(i,n) / donji(i,n));
    return sqrt(1.0 * gornji(i,n)/ donji(i,n) + rek(i + 1,n));
}
double ite(int n){
    double sum = sqrt(gornji(n,n) / donji(n,n));
    for(int i = n - 1; i > 0; i--){
        sum = sqrt(1.0*gornji(i,n)/donji(i,n) + sum );
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("%d\t", stepen(i,n));
    }
//    printf("[REK] %f\n",rek(1,n));
//    printf("[ITE] %f\n",ite(n));

    return 0;
}