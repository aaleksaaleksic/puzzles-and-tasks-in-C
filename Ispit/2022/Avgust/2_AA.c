
#include <string.h>
#include <stdio.h>
/*
hazari azbuka pazar oranje zagor tor
zar
        Izlaz: hazari azbuka oranje tor
*/

int doesItContain(int start, int end, char* s,char* g){
    if((end - start + 1) % 2 == 0)
        return 0;

    for(int j = 0; j < strlen(g); j++){
        int pojavljuje = 0;
        for(int i = start; i <= end; i++){
            if(g[j] == s[i])
                pojavljuje++;
        }
        if(pojavljuje == 0)
            return 0;
    }
    return 1;
}
int main(){
    char s[100],g[100];

    fgets(s,sizeof(s),stdin);
    fgets(g,sizeof(g),stdin);

    s[strlen(s) - 1 ] = 0;
    g[strlen(g) - 1] = 0;
    int start,end;
    int index = 0;

    for(int i = 0; i < strlen(s); i++){
        if(i == 0 || s[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(s) - 1 || s[i + 1] == ' '){
            end = i;
            if( !doesItContain(start,end,s,g)){
                for(int k = start; k <= end; k++){
                    s[index++] = s[k];
                }
                s[index++] = ' ';
            }
        }
    }
    s[index] = 0;
    fputs(s,stdout);
    return 0;
}