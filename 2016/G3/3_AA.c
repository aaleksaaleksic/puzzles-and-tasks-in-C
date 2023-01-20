//
// Created by Korisnik on 1/20/2023.
//
/**
Primer: 345-135-3217
Rezultat: 534-513-7321
 */
#include <stdio.h>
#include <string.h>
void rotirajBroj(int start,int end, char* str){
    char tmp = str[end];
    for(int i = end; i > start; i--){
        str[i] = str[i - 1];
    }
    str[start] = tmp;
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    int start,end;
    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == '-'){
            start = i;
            continue;
        }
        if(i == strlen(str) - 1 || str[i + 1] == '-'){
            end = i;
            rotirajBroj(start,end, str);

        }

    }
    fputs(str,stdout);

    return 0;
}
