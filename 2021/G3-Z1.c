#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///2021 G3 Z1
///Mladen pravi funkciju za imenilac i brojilca sto je vrlo pametno

int imenilac(int i){
    return i*i;
}

int brojilac(int i,int n){
    if( i <= n / 2){
        return n - i + 1;
    }else{
        return i;
        ///gledano sa strane formule , bolje vratiti "i" nego (n - i + n / 2)
        ///hajde da budemo malo efikasniji i svjesni na okolinu :)
    }
}

double rek(int n,int i){
    if(i == n){
        return sqrt(brojilac(i,n) * 1.0 / imenilac(i));
    }
    return sqrt(brojilac(i,n) * 1.0 / imenilac(i) + rek(n,i+1));
}

double iter(int n){
    double res = sqrt(brojilac(n,n) * 1.0 /imenilac(n));
    for(int i = n - 1; i >= 1; i--){
        res = sqrt(brojilac(i,n) * 1.0 /imenilac(i) + res);
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("Rekurzivno : %lf\n",rek(n,1));
    printf("Iterativno : %lf",iter(n));

    return 0;
}
