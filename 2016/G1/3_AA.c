#include <stdio.h>
#include <string.h>
#define MAX 100

void pregaziRec(int poc,char* s){
    
}

int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s) - 1;
    s[n] = 0;



    fputs(s, stdout);

    return 0;
}