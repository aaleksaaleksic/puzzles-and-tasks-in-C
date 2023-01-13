#include <stdio.h>
#include <string.h>

/**
Unos: acdj(knaan)nhn(prcf)ak(sdfffs)j
Ispis: acdj(kna)nhn(prcf)ak(sdf)j
**/
int main(){

    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = '\0';


    int index = 0;
    int z_index;
    int flag = 0;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '('){
            z_index = i + 1;
            flag = 1;
            str[index++] = str[i];
            continue;
        }
       if(str[i] == ')'){
            flag = 0;
            str[index++] = str[i];
            continue;
        }
       if(flag == 1){
           if(strchr(str + z_index,str[i]) - str == i){

               str[index++] = str[i];
               continue;

           }
           else
               continue;
       }
    str[index++] = str[i];
    }
    str[index] = 0;
    fputs(str,stdout);
    return 0;
}
