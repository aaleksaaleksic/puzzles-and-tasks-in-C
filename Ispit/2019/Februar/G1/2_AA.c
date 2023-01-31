#include <stdio.h>
#include <string.h>
#include <math.h>
/**
prvi: Jaja pojavljivanja boja jabuka
drugi: ja
ispis: boja jabuka
*/

void ukloni(int start,int end,char* s){
    int len = end - start + 1;
    for(int i = start; i < strlen(s) - len; i++){
        s[i] = s[i + len];
    }
    s[strlen(s) - len] = 0;
}
int daLiSadrzi(char* p,char* s, int start,int end){
    int flag = 0;
    int check;
    for(int i = start; i <= end; i++){
        if(s[i] == p[0] || abs(s[i] - p[0]) == 32){
            check = 1;
            for(int j = i+1; j < strlen(p);j++){
                if(s[i+j] + 32 != p[j] && s[i+j] - 32 != p[j])
                    continue;
                if(s[i+j] != p[j])
                    check = 0;
            }
            if(check)
                flag++;

        }
    }
    if(flag > 1)
        return 1;
    return 0;
}
int main(){
    char s[100],p[100];
    fgets(s,100,stdin);
    fgets(p,100,stdin);
    s[strlen(s) - 1] = 0;
    p[strlen(p) - 1] = 0;
    int start,end;

    for(int i = 0; s[i] != 0; i++){
        if(i == 0 || s[i - 1] == ' '){
            start = i;
            continue;
        }
        if(s[i + 1] == 0 || s[i+1] == ' '){
            end = i;
//            printf("start %d end %d  daLiSadrzi: %d\n",start,end, daLiSadrzi(p,s,start,end));
            if(daLiSadrzi(p,s,start,end)){
                ukloni(start,end,s);
            }
        }
    }
    fputs(s,stdout);

    return 0;
}