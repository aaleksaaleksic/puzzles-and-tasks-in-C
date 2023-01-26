#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Unos: abcdeXhz zhj bbbbXac cccXs
Ispis: ahbzchdze zhj babcbab cscsc
*/

void modifikuj(char* str, char* novi, int start, int end, int* novi_index)
{
    int ima_x = 0;
    int lokacija_x;
    for(int i = start; i <= end; i++){
        if(str[i] == 'X'){
            lokacija_x = i;
            ima_x = 1;
            break;
        }
    }

    if(!ima_x){
        for(int i = start; i <= end; i++){
            novi[(*novi_index)++] = str[i];
        }
        novi[(*novi_index)++] = ' ';
        return;
    }

    int duzina_desnog_dela = end - lokacija_x;

    for(int i = start; str[i] != 'X'; i++){
        novi[(*novi_index)++] = str[i];
        novi[(*novi_index)++] = str[lokacija_x + 1 + ((i - start) % duzina_desnog_dela)];

    }
    novi[(*novi_index)++] = ' ';

}


int main()
{
    char str[100],novi[100];
    novi[0] = 0;
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;

    int start,end;
    int novi_index = 0;

    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(str) - 1 || str[i + 1] == ' '){
            end = i;
//          printf("pocetak %d kraj %d\n",start,end);
            modifikuj(str,novi,start,end,&novi_index);

        }
    }

    fputs(novi,stdout);
    return 0;
}