//
// Created by Korisnik on 1/4/2023.
//
#include <stdio.h>
#include <math.h>

double gornji(int i,int n){
    if(i % 2)
        return i / 2 + 1;

    return n - i / 2 + 1;
}

double donji(int i,int n){
    if(i % 2)
        return pow(n - i / 2,2);
    return pow(i / 2, 2);
}

double rek(int i, int n){
    if(i == n)
        return sqrt(gornji(i,n) / donji(i , n));
    return sqrt(1.0 * gornji(i,n) /donji(i,n) + rek(i + 1,n));
}
double ite(int n){
    double sum = sqrt(gornji(n,n)/donji(n,n));
    for(int i = n - 1; i > 0; i--){
        sum = sqrt(gornji(i,n)/ donji(i,n) + sum);
    }
    return sum;
}
int main(){

    int n;
    scanf("%d",&n);

    printf("[REK] %f\n",rek(1,n));
    printf("[ITE] %f\n",ite(n));
    return 0;
}
