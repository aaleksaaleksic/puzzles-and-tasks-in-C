//
// Created by Korisnik on 1/5/2023.
//

#include <stdio.h>
#include <math.h>

int stepen(int i){
    return i + 1;
}

int levo(int i, int n) {
    if(!(i % 2)){
        return pow(n * 8 - (i * i + i),stepen(i));
    }
    return n * 8 - (i * i + i);
}
int desno(int i,int n){
    if(!(i % 2)){
        if(i < n /2)
            return n - i;
        else if(i == n / 2 && !(n % 2))
            return n / 2 + 1;
        return i + 1;
    }
    else{
        if(i < n /2)
            return pow(n - i, stepen(i));
        else if(i == n / 2 && !(n % 2))
            return pow(n / 2 + 1, stepen(i));
        return pow(i + 1, stepen(i));
    }

}
double rek(int i, int n){
    if(i + 1 == n)
        return levo(i, n) + desno(i, n);
    return levo(i,n) + 1.0 * desno(i,n) / rek(i + 1, n);
}
double ite(int n){
    double sum = levo(n - 1,n - 1) + desno(n - 1,n - 1);
    for(int i = n - 2; i >= 0; i--){
        sum = levo(i, n) + desno(i, n) / sum;
    }
    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("[REK] %f\n",rek(0,n));
    printf("[ITE] %f\n",ite(n));
    return 0;
}
