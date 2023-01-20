
///  Primer: prvi drugi prvi treci prvi
///  Rezultat: prvi 3 puta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{
    char str[100],novi[100];
    novi[0] = 0;
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;

    char* token = strtok(str," "); // token pokazuje na mesto pocetka podstringa u VELIKOM STRINGU i to koristi majmune
    while(token){
        if(!strstr(novi,token)){
            strcat(novi,token);
            strcat(novi," ");
        }
        token = strtok(NULL," ");
    }
    fputs(novi,stdout);

    return 0;
}