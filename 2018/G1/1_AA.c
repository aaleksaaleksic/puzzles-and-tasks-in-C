//
// Created by Korisnik on 12/29/2022.
//
#include <stdio.h>
#include <math.h>
#include <limits.h>

int jeProst(int n){
    for(int i = 2; i <= n/2; i++){
        if(!(n % i))
            return 0;
    }
    return 1;
}

int ntiProst(int x){
    int cnt = 0;
    for(int i = 2; i < INT_MAX; i++){
        if(jeProst(i))
            cnt++;
        if(cnt == x)
            return i;
    }
    return  0;
}

int znak(int i){
   return (i % 2) ? 1 : -1;
}
int levi(int n,int i){
    return 65 + n - i;
}
int gore(int i){
    return ntiProst(i);
}
double rek(int n,int i){
    if(i == n)
        return levi(n,i);
    return levi(n,i) + znak(i) * gore(i) / rek(n,i+1);
}
double ite(int n){
    double sum = levi(n,1);

    for(int i = n - 1; i > 0; i--){
        sum = levi(n,i) + znak(i) * gore(i) / sum;
    }
    return sum;

}

int main(){
    int n;
    scanf("%d",&n);
    printf("[REK] %f\n",rek(n,1));
    printf("[ITE] %f\n",ite(n));
    return 0;
}
