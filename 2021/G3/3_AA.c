
#include <stdio.h>
#include <string.h>
/**

Primer: 4385 53913 335

Rezultat: 5506 65234 456


 */

void modifikujBroj(int start,int end, char* str){
    int inkrement = 1;
    int len = end - start + 1;
    for(int  i = start; i < start + len/2; i++){
        int broj = ((str[i] - '0') + inkrement) % 10;
        str[i] = broj + '0';
        broj = ((str[end - inkrement + 1] - '0') + inkrement) % 10;
        str[end - inkrement + 1] = broj + '0';
        inkrement++;
    }
    if(len % 2){
       int broj = ((str[start + len/2] -'0') + inkrement) % 10;
       str[start + len/2] = broj +'0';
    }
}

int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;
    int start, end;
    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' '){
            start = i;
            continue;
        }
        if(i == strlen(str) - 1 || str[i + 1] == ' '){
            end = i;
            modifikujBroj(start,end,str);
        }
    }
    fputs(str,stdout);
    return 0;
}
