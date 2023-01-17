#include <stdio.h>
#include <string.h>
/**
Unos: P: (dfhhj)fg(adbjbdnc)agh(haj)gh(akjh) S: dhj
Ispis: dfhhj haj
**/
int isOk(char* p,char* s,int index){
    int count = 0;
    int idx;
    int i;
    for(i = index; p[i] != ')'; i++){
        if(strchr(s,p[i])){
            count++;
            idx = strchr(s,p[i]) - s;
            break;
        }
    }
    for(; p[i] != ')';i++){
        if(strchr(s,p[i]) - s == idx + 1){
            idx++;
            count++;
        }
    }
    return (count >= 2) ? 1 : 0;
}
int main(){
    char p[100],s[100],novi[100];
    fgets(p,sizeof(p),stdin);
    fgets(s,sizeof(s),stdin);
    p[strlen(p) - 1] = 0;
    s[strlen(p) - 1] = 0;
    novi[0] = 0;

    int novi_idx = 0,zagrada_idx;


    for(int i = 0; i < strlen(p); i++){
        if(p[i] == '('){
            zagrada_idx = i + 1;
            int c = 0;
            if(isOk(p,s,zagrada_idx)){
                for(int q = zagrada_idx; p[q] != ')';q++){
                    novi[novi_idx++] = p[q];
                    c++;
                }
                novi[novi_idx++] = ' ';
                i += c;

            }
            continue;
        }
        if(p[i] == ')'){
            zagrada_idx = 0;
            continue;
        }



    }
    novi[novi_idx] = 0;
    fputs(novi,stdout);


    return 0;
}
