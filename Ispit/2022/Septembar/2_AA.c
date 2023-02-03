#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Prvi string: moral domar romor sumoran temporalni mormonska
Drugi string: mora
Izlaz: moral sumoran temporalni
*/

/*Kada pisemo funckiju koja proverava da li se isti karakteri pojavljuju u istom poretku u stringu s i stringu g
 * prolazimo kroz svako slovo stringa velikog stringa i fiksiramo ga i onda trazimo poklapanje sa slovom koje je na redu
 * da se prikaze u stringu g, i ako poklapanje nije tacno vrati 0*/

int doesItContain(int start, int end, char* s,char* g){
    int g_index = 0;
    for(int i = start; i <= end; i++){
        for(int j = 0; j < strlen(g); j++){
            if(s[i] == g[j]){
                if(s[i] == g[g_index])
                    g_index++;
                else
                    return 0;
            }

        }
    }
    return 1;
}


int main()
{
    char s[100],g[100];
    fgets(s,sizeof(s),stdin);
    fgets(g,sizeof(g),stdin);
    s[(strlen(s))-1] = 0;
    g[(strlen(g))-1] = 0;
    int start,end;

    int index = 0;

    for(int i = 0; i < strlen(s); i++){
        if(i == 0 || s[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(s) - 1 || s[i + 1] == ' '){
            end = i;

            if(doesItContain(start,end,s,g)){
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
