#include <stdio.h>
#include <string.h>

/*
 Primer:

P: asadadio
S: gladansam

Izlaz: aaaddaaasaaa
 */

int brojPonavljanja(char* p, char x){
    int cnt = 0;
    for(int i = 0; i < strlen(p); i++){
        if(p[i] == x)
            cnt++;
    }
    return cnt;
}

int main(){

    char p[100],s[100];
    fgets(p,100,stdin);
    fgets(s,100,stdin);

    p[strlen(p) - 1] = 0;
    s[strlen(s) - 1] = 0;
    int i = 0;
    while(s[i]){
        if(strchr(p,s[i]) == NULL){
            for(int j = i; j < strlen(s); j++){
                s[j] = s[j + 1];
            }
        }
        else{
            int bp = brojPonavljanja(p, s[i]);
            for(int k = 1; k < bp; k++){
                int len = strlen(s);
                for(int p = len; p > i; p--){
                    s[p] = s[p-1];
                }
                s[len + 1] = 0;
            }
            i += bp;
        }
    }
    fputs(s,stdout);

    return 0;
}