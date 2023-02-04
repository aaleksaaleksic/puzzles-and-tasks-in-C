//
// Created by Korisnik on 1/9/2023.
//
#include <stdio.h>
#define MAX 1000

int main(){
    char s[MAX];
    fgets(s,MAX,stdin);
    fputs(s,stdout);

    return 0;
}