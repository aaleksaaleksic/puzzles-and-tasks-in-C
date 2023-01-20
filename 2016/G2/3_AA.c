
#include <stdio.h>
#include <string.h>
/**
Primer: Recenica koja ima nekoliko reci
Rezultat: Recenica nekoliko
 */

void pomeriString(char* str, int start,int len){
    for(int i = start; i < strlen(str) - len; i++){
        str[i] = str[i + len];
    }
    str[strlen(str) - len] = 0;
}

int main(){

    char str[100];
    int n;
    scanf("%d", &n);
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = 0;
    printf("Unesite broj:\n");
    scanf("%d", &n);


    int start, end;
    for(int i = 0; i < strlen(str); i++){
        if(i == 0 || str[i - 1] == ' '){
            start = i;
            continue;
        }

        if(i == strlen(str) - 1 || str[i + 1] == ' '){
            end = i;

            printf("start %d  end %d  len %d\n",start,end,end - start + 1);
            if((end - start + 1) < n)
                pomeriString(str,start,end - start + 1);

        }

    }


    fputs(str,stdout);

    return 0;
}