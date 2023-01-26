#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Prvi string: moral domar romor sumoran temporalni mormonska
Drugi string: mora
Izlaz: moral sumoran temporalni
*/

int daLiSadrzi(char* s, char* g,int start, int end){

    int na_redu = 0;
    int len = strlen(g);
    for(int i = start; i <= end; i++){
        for(int j = 0; j < len; j++){
            if(s[i] == g[j]){
                if(s[i] == g[na_redu]){
                    na_redu++;
                    continue;
                }
                else
                    return 0;
            }
        }
    }
    return 1;


}

void obrisi(char* s, int start, int end){
    int len = end - start + 1;
    for(int i = start; i < strlen(s) - len; i++){
        s[i] = s[i + len];
    }
    s[strlen(s) - len] = 0;
}

int main()
{
    char s[100],g[100];
    fgets(s,sizeof(s),stdin);
    fgets(g,sizeof(g),stdin);
    s[(strlen(s))-1] = 0;
    g[(strlen(g))-1] = 0;
    int start,end;

    for(int i = 0; i < strlen(s); i++){
        if(i == 0 || s[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(s) - 1 || s[i + 1] == ' '){
            end = i;
            if(!daLiSadrzi(s,g,start,end))
                obrisi(s,start,end);

        }

    }
    fputs(s,stdout);

    return 0;
}
