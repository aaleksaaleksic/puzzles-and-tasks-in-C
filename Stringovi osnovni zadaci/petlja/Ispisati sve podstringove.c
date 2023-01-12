#include <stdio.h>
#include <string.h>
#define MAX 100

void ispisiPodstring(int poc,int kraj,char* s){
    for(int i = poc; i < kraj; i++){
        putchar(s[i]);
    }
    putchar('\n');
}

int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s);
    s[n - 1] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            ispisiPodstring(i,j,s);
        }
    }
    return 0;
}

