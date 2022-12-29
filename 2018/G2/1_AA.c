//
// Created by Korisnik on 12/29/2022.
//
#include <stdio.h>
#include <math.h>
#include <limits.h>

int ntiFibonacijev(int x){
    if(x == 1 || x == 2)
        return 1;
    int prev = 1;
    int tren = 1;
    int fibonacci = 0;
    int count = 2;
    for(int i = 0; i < INT_MAX; i++){
        fibonacci = prev + tren;
        prev = tren;
        tren = fibonacci;
        count++;
        if(count == x)
            return fibonacci;
    }
    return 0;
}

//int ntiFibonacijev(int x){
//    if(x == 1 || x == 2)
//        return 1;
//    int count = 0;
//    for(int i = 1; i < x*2; i++){
//        if(i == jeFibonacijev(i))
//            count++;
//        if(count == x)
//            return i;
//
//    }
//    printf("count %d\n",count);
//    return 0;
//}
int levi(int i){
    return ntiFibonacijev(i);
}
int desni(int p){
    return 3*p;
}
int znak(int i){
   return (i % 2) ? 1 :-1;
}
double rek(int i,int n,int p){
    if(i == n)
        return levi(i);
    return levi(i) + znak(i) * desni(p) / rek(i + 1, n, p - 1);
}
double ite(int n){
    double sum = levi(n);
    int count = 2;
    for(int i = n - 1; i >= 1; i--){
        sum = levi(i) + znak(i) * desni(count) / sum;
        count++;
    }
    return sum;
}


int main(){

    int n;
    scanf("%d",&n);
    printf("[REK] %f\n",rek(1,n,n));
    printf("[ITE] %f\n",ite(n));


    return 0;
}