
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    char ime[50];
    int index;
    int godina_upisa;
}Student;

int main(){

    /// proba struktura

//    Student aleksa;
//    strcpy(aleksa.ime,"Aleksa");
//    strcpy(aleksa.prezime,"Aleksic");
//    strcpy(aleksa.s_program,"RN");
//    aleksa.index = 97;
//    aleksa.godina_upisa = 22;
//
//    printf("%s %s %d/%d %s\n\n ",aleksa.ime,aleksa.prezime,aleksa.index,aleksa.godina_upisa,aleksa.s_program);

/// rad sa fajlovima

    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Strukture\\studenti.txt","r");

    if(fp == NULL)
        printf("Niste otvorili fajl\n");
    else
        printf("Uspesno ste otvorili fajl\n");

    char linija[255];
    Student niz[10];
    int k = 0;

    while(fgets(linija,sizeof(linija),fp)){
//        linija[strlen(linija) - 1] = 0;
        char name[50];
        strcpy(name, strtok(linija," "));
        int idx = atoi(strtok(NULL," "));
        int gUpisa = atoi(strtok(NULL," "));

        Student s;

        strcpy(s.ime,name);
        s.godina_upisa = gUpisa;
        s.index = idx;
        niz[k++] = s;
    }

    for(int i = 0; i < k; i++){
        printf("[student %d] %s %d/%d\n",i + 1, niz[i].ime,niz[i].index, niz[i].godina_upisa);
    }

    return 0;
}