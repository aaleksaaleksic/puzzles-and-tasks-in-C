#include <stdio.h>
#include <string.h>
#include <math.h>

/**
prvi: Danas pada sneg u Beogradu
drugi: da
ispis: sneg u Beogradu
**/

char maloSlovo(char ch){
    return (ch >= 'A' && ch <= 'Z')? ch +32: ch;
}
int main(){
    char s[50],p[50];
    fgets(s,50,stdin);
    fgets(p,50,stdin);
    s[strlen(s) - 1] = 0;
    p[strlen(p) - 1] = 0;

    int start = 0;
    int lenS = strlen(s);
    int lenP = strlen(p);
    int index = 0;

    for(int i = 0; i < lenS; i++){
        if(s[i + 1] == ' ' || i == lenS - 1 && i != 2){
            int end = i;
            int flagPre = 1, flagPosle = 1;
            if(maloSlovo(s[start]) == maloSlovo(p[0])){
                for(int k = 0; k < lenP; k++){
                    if(maloSlovo(s[start+k]) != maloSlovo(p[k])){
                        flagPre = 0;
                        break;
                    }
                }
            }
            else
                flagPre = 0;
            if(s[end - lenP + 1] == p[0]){
                for(int k = 0; k < lenP; k++){
                    if(maloSlovo(s[end - lenP + 1 + k]) != maloSlovo(p[k])){
                        flagPosle = 0;
                        break;
                    }
                }
            }
            else
                flagPosle = 0;
            if(!flagPre && !flagPosle){ // zadrzavamo rec
                for(int k = 0; k < end - start + 1; k++){
                    s[index++] = s[start + k];
                }
                s[index++] = ' ';
            }
            start = end + 2;
        }

    }
    s[index] = 0;
    fputs(s,stdout);
    return 0;
}