#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Predmet{
    char prodavnica[50];
    char naziv[50];
    int cena;
    struct Predmet* next;
}Predmet;

void stampajCvor(Predmet* cvor){
    printf("%s %s %d\n",cvor->prodavnica,cvor->naziv,cvor->cena);
}

Predmet* napraviPredmet(char* prodavnica,char* naziv, int cena){
    Predmet* noviPredmet = (Predmet*) malloc(sizeof(Predmet));
    noviPredmet->cena = cena;
    strcpy(noviPredmet->naziv,naziv);
    strcpy(noviPredmet->prodavnica,prodavnica);
    noviPredmet->next = NULL;
    return noviPredmet;
}
Predmet* ubaciUListu(Predmet* glava, Predmet* novi){
    if(glava == NULL){
        return novi;
    }
    Predmet* curr = glava;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = novi;
    return glava;
}

Predmet* ucitajFajl(Predmet* glava, char* filename){
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Greska\n");
    }else{
        printf("File ucitan\n");
    }
    char linija[255];
    while(fgets(linija,255,fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[strlen(linija) - 1] = 0;
        char* prodavnica = strtok(linija,",");
        char* naziv = strtok(NULL,",");
        int cena = atoi(strtok(NULL," "));
        Predmet* novi = napraviPredmet(prodavnica,naziv,cena);
        glava = ubaciUListu(glava,novi);
    }
    fclose(fp);
    return glava;
}

void ispisiListuNormalno(Predmet* glava){
    Predmet* curr = glava;
    while(curr){
        stampajCvor(curr);
        curr = curr->next;
    }
}

void obrisiListu(Predmet* glava){
    Predmet* deletion = glava;
    while(glava->next){
        deletion = glava;
        glava = glava->next;
        free(deletion);
    }
}



void meni(){
    printf("-----------------------------------------\n");
    printf("1.Ucitaj fajl\n");
    printf("2.Ispisi listu\n");
    printf("3.Nesto trece\n");
    printf("4.Obrisi listu i izadji iz programa\n");
    printf("-----------------------------------------");
}

int main(){
    int opcija;
    Predmet* glava = NULL;
    while(1){
        meni();
        printf("\nUnesi opciju:");
        scanf("%d",&opcija);
        switch (opcija) {
            case 1:
                glava = ucitajFajl(glava,"ocene.txt");
                break;
            case 2:
                ispisiListuNormalno(glava);
                break;
            case 3:
            case 4:
                obrisiListu(glava);
                return 0;
        }
    }
    return 0;
}


/*
 idea,brokoli,200
idea,karfiol,180
maxi,jaja,120
maxi,mleko,100
idea,jogurt,50
idea,jabuka,20
idea,mandarina,90
idea,brasno,44
idea,mandarina,90
maxi,banana,80
idea,secer,45
maxi,paprika,58
idea,krompir,47
idea,sargarepa,38
maxi,tiganj,2000
maxi,noz,2000
idea,jaja,130
idea,mleko,88
maxi,jogurt,52
maxi,jabuka,21
idea,banana,85
maxi,mandarina,92
maxi,brasno,45
maxi,secer,43
idea,paprika,60
maxi,krompir,46
maxi,sargarepa,35
 */