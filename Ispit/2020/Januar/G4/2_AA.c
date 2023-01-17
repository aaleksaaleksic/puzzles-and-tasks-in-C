

#include <stdio.h>
#include <string.h>
/**
 Primer
Unos: [adf] {dfg} {fgh} {nm} (jkl) [df]
Ispis: [adf] {dfghnm} (jkl)
 */

int main(){

    char str[100],novi[100];

    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    str[strlen(str)] = ' ';
    int novi_idx = 0;
    int zagrada;
    for(int i = 0; i < strlen(str); i++){
        if((str[i] == '(' || str[i] == '[' || str[i] == '{') && strchr(novi,str[i]) == NULL){
            novi[novi_idx++] = str[i];
            zagrada = novi_idx - 1;
            for(int j = i; j < strlen(str); j++){
                if(str[j] == str[i]){
                    for(int k = j + 1; str[k + 1] != ' '; k++){
                        if(strchr(novi + zagrada,str[k]) == NULL){
                            novi[novi_idx++] = str[k];
                        }
                    }
                }
            }
            if(str[i] == '(')
                novi[novi_idx++] = ')';
            else if(str[i] == '{')
                novi[novi_idx++] = '}';
            else
                novi[novi_idx++] = ']';
            novi[novi_idx++] = ' ';
        }
    }
    novi[novi_idx] = 0;
    fputs(novi,stdout);

    return 0;
}
