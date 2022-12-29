//
// Created by Korisnik on 12/11/2022.
//
#include <stdio.h>
#include <math.h>

double rek(int i, int n,int parni,int neparni,double gornji){
    if(i == n){
        if(n % 2 == 0)
            return parni;
        else
            return neparni;
    }
    if(i % 2)
       return neparni + gornji / rek(i + 1, n, parni, neparni - 1, gornji - 2);
    else
      return  parni + gornji / rek(i + 1, n, parni + 1, neparni, gornji - 2);

}
double ite(int n){
    int parni = 1, neparni = n;
    double gornji = 4;
    for(int i = 3; i <= n; i++){
        if(i % 2)
            neparni--;
        else
            parni++;

    }
    double sum = 0;
    if(n % 2){
        sum = neparni;
        neparni++;
    }
    else{
        sum = parni;
        parni--;
    }
    for(int i = n - 1; i >= 1; i--){
        if(i % 2){
            sum = neparni + gornji / sum;
            neparni++;
        }

        else{
            sum = parni + gornji / sum;
            parni--;
        }
        gornji += 2;

    }
    return sum;
}


int main(){
    int n;
    scanf("%d", &n);

    printf("[REK]  %f\n",rek(1,n,1,n,2 * n));
    printf("[ITE]  %f\n",ite(n));;

}