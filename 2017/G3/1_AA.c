//
// Created by Korisnik on 12/11/2022.
//
#include <stdio.h>
#include <math.h>

double rek(int i, double gornji, double donji, int n){

    if(i == n)
        return sqrt(gornji / donji);
    return sqrt(gornji / donji + rek(i + 1, gornji - 11, donji + i, n));
}

double ite(int n){
    int gornji = n * 10 + n - 1,donji = n;
    for(int i = 1; i < n; i++){
        donji += i;
        gornji -= 11;
    }
    double sum = sqrt((double)gornji / donji);
    gornji += 11;
    donji -= n - 1;

    for(int i = n - 1; i > 0; i--){
        sum = sqrt((double )gornji / donji + sum);
        gornji += 11;
        donji -= i - 1;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);

    printf("[REK]  %f\n",rek(1,n * 10 + (n - 1),n,n));
    printf("[ITE]  %f\n",ite(n));

}
