//
// Created by Korisnik on 12/11/2022.
//
#include <stdio.h>
#include <math.h>

double rek(int i, int p, int q,double denominator, int n){

    if(i == n){
        if (n % 2 == 0)
            return sqrt(q / denominator);
        else
            return sqrt(p / denominator);

    }

    if(i % 2)
        return sqrt(p / denominator + rek(i + 1,p,q + 1, denominator - 2,n));
    else
        return sqrt(q / denominator + rek(i + 1,p - 1, q, denominator - 2, n ));

}
double ite(int n){
    int parni = 1,neparni = n;
    double donji = 2;
    for(int i = 3; i <= n; i++){
        if(i % 2)
            neparni--;
        else
            parni++;
    }


    double sum = (n % 2 == 0) ? (sqrt(parni / donji)) : (sqrt(neparni / donji));

    if(n % 2)
        neparni++;
    else
        parni--;

    donji += 2;
    for(int i = n - 1; i > 0; i--){
        if(i % 2){
            sum = sqrt((double)neparni / donji + sum);
            neparni++;
        }

        else{
            sum = sqrt((double)parni / donji + sum);
            parni--;
        }

        donji += 2;
    }
    return sum;





}

int main(){
    int n;
    scanf("%d",&n);

    printf("[REK] %f\n", rek(1,n,0,2 * n,n));
    printf("[ITE] %f\n", ite(n));

    return 0;
}
