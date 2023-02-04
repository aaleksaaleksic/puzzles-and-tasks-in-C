#include <stdio.h>
#include <string.h>
#define MAX 100



int main(){

    char s[MAX];
    fgets(s,MAX,stdin);
    int n = strlen(s);
    s[n - 1] = 0;

    for(int i = n - 1; i >= 0; i--){
        s[i * 2 + 1] = s[i];
        s[i * 2] = s[i];
    }
    s[n * 2] = 0;
    fputs(s, stdout);

    return 0;
}