//
// Created by Korisnik on 1/4/2023.
//


#include <stdio.h>
#include <math.h>
int fakt(int n){
    if(n == 1)
        return 1;
    return n * fakt(n - 1);
}
int broj(int i,int n){
    if(i % 2)
        return n - i/2;
    return i / 2;
}
int faktorijel(int i,int n){
    return fakt(broj(i,n));
}
int levo(int i,int n){
    if(i % 2)
        return i / 2 + 1;
    return n - i / 2 + 1;
}
double rek(int i,int n){
    if(i == n)
        return levo(i,n) + faktorijel(i,n);
    return levo(i,n) + 1.0*faktorijel(i,n) / rek(i + 1,n);
}
double ite(int n){
    double sum = levo(n,n) + faktorijel(n,n);
    for(int i = n - 1; i > 0; i--){
        sum = levo(i,n) + faktorijel(i,n) / sum;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("[REK] %f\n", rek(1,n));
    printf("[ITE] %f\n", ite(n));
    return 0;
}
