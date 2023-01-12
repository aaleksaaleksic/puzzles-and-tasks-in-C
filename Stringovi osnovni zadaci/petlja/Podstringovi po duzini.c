//
// Created by Korisnik on 1/10/2023.
//
#include <stdio.h>
#include <string.h>
#define MAX 1000

void write(int pocetak,int kraj, char* s){
    for(int i = pocetak; i < kraj; i++){
        putchar(s[i]);
    }
    putchar('\n');
}
int main(){
    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s);
    s[n - 1] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n - i; j++)
            write(j,j + i,s);
    }
    return 0;
}