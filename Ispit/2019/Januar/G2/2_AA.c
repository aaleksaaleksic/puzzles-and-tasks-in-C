
#include <string.h>
#include <stdio.h>

/**
Primer:
Unos: {a,b,c} {34,up,df} {1,2,1} {a,a}
Ispis:{1,2,1}
      {a,a}
 */

int isUnique(char* zagrada){
    char str1[50];
    char str2[50];
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i <= strlen(zagrada); i++){
        if(i == strlen(zagrada) || zagrada[i] == ','){
            str1[index1] = 0;
            index1 = 0;
            for(int j = i + 1; j <= strlen(zagrada); j++){
                if(j == strlen(zagrada) || zagrada[j] == ','){ ///VODI RACUNA O USLOVIMA POCETKA I KRAJA
                    str2[index2] = 0;
                    index2 = 0;
                    if(strcmp(str1,str2) == 0){
                        return 1;
                    }

                    str2[0] = 0;
                }
                else
                    str2[index2++] = zagrada[j];
            }
            str1[0] = 0;
        }
        else
            str1[index1++] = zagrada[i];
    }
    return 0;
}

int main(){
    char str[255];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    int len = strlen(str);
    char zagrada[50];
    int index = 0;



    for(int i = 0; i < len; i++){
        if(i == 0 || str[i] == '{' || str[i] == ' ')
            continue;
        if(i == len - 1 || str[i] == '}'){
            zagrada[index] = 0;
            index = 0;
            if(isUnique(zagrada)){
                fputs(zagrada,stdout);
                putchar(' ');
            }
            zagrada[0] = 0;
            continue;
        }

        zagrada[index++] = str[i];

    }
    return 0;
}
