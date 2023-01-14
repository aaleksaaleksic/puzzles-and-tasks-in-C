
#include <stdio.h>
#include <string.h>

/**
Unos: abc nkj amng nrp cbf ak
Ispis: abcmngk nkjrp cbf
**/
int prvoSlovo(char* str,char c){
    if(str[0] == c)
        return 1;

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ' ' && str[i + 1] == c)
            return 1;
    }
    return 0;
}

int main(){
    char str[100],novi[100];
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    int n_idx = 0;

    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' '){
            if(!(prvoSlovo(novi,str[i]))){
                int j = i;
                for(j; str[j] != ' '; j++)
                    novi[n_idx++] = str[j];

                for(j; j < strlen(str); j++){
                    if(str[j - 1] == ' ' && str[j] == str[i]){
                        for(int k = j + 1; str[k] != ' ' && str[k] != 0; k++){
                            novi[n_idx++] = str[k];
                        }
                    }
                }
                novi[n_idx++] = ' ';
            }
        }
    }
    novi[n_idx] = 0;
    fputs(novi,stdout);
    return 0;
}
