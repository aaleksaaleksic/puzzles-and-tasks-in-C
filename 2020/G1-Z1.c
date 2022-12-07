#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stepen(int a,int b){
    int res = 1;
    while(b){
        res *= a;
        b--;
    }
    return res;
}

int lijevi(int n, int i){
    int lijevi = 0;
    if(n%2){
        if(i%2){
            lijevi = stepen((n * (n+1)) - i*i+i, i % (n/2+1));
        }else{
            lijevi = (n * (n+1)) - i*i+i;
        }
    }else{
        if(i%2){
            lijevi = (n * (n+2)) - i*i+i;
        }else{
            lijevi = stepen((n * (n+2)) - i*i+i, i % (n/2+1));
        }
    }
    printf("ITERACIJA : %d, LIJEVI : %d\n", i , lijevi);
    return lijevi;
}

int gornji(int n, int i){
    int gornji = 0;
    ///ako je N neparan broj //////////////////////////////////
    if(n%2){
        if(i <= n/2){               ///manji od pola
            if(i % 2){
                gornji = n - i +1;
            }else{
                gornji = stepen(n - i +1, i);
            }
        }else if(i == n/2+1){       ///na polovini
            if(i % 2){
                gornji = i;
            }else{
                gornji = stepen(i,i);
            }
        }else{                      ///ispod polovine
            if(i % 2){
                gornji = i;
            }else{
                gornji = stepen(i,i);
            }
        }
        ///ako je N paran broj ////////////////////////////////////
    }else{
        if(i <= n/2){                       ///manji od pola
            if(i%2){
                gornji = stepen(n - i + 1,i);
            }else{
                gornji = n - i + 1;
            }
        }else if(i ==  n/2 || i == n/2+1){ /// na polovini
            if(i%2){
                gornji = stepen(n - i + 1,i);
            }else{
                gornji = n - i + 1;
            }
        }else{                              ///ispod polovine
            if(i%2){
                gornji = i;
            }else{
                gornji = i;
            }
        }
    }
    printf("ITERACIJA : %d, GORNJI : %d\n", i , gornji);
    return gornji;
}

double rek(int n, int i){
    if(i == n){
        return lijevi(n,i) + gornji(n,i);
    }
    return lijevi(n,i) + gornji(n,i)*1.0 / rek(n,i+1);
}

double iter(int n){
    double res = lijevi(n,n) + gornji(n,n);
    for(int i = n - 1; i >= 1; i--){
        res = lijevi(n,i) + gornji(n,i) / res;
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
