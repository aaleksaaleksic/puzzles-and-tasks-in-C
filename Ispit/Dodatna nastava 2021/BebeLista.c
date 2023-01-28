#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Beba{
    int dan;
    int mesec;
    int godina;
    int brBeba;
    struct Beba* next;
}Beba;

Beba* napraviBebu(int dan,  int mesec, int godina, int brBeba){
    Beba* novaBeba = (Beba*)malloc(sizeof(Beba));
    novaBeba->dan = dan;
    novaBeba->mesec = mesec;
    novaBeba->godina = godina;
    novaBeba->brBeba = brBeba;
    novaBeba->next = NULL;
    return novaBeba;
}

Beba* ubaciUListu(Beba* glava, Beba* novaBeba){
    //u slucaju da je prazna lista
    if(glava == NULL){
        return novaBeba;
    }
    //u slucaju da ubacujemo prije pocetka
    if(novaBeba->brBeba >= glava->brBeba){
        novaBeba->next = glava;
        return novaBeba;
    }
    //u slucaju da ubacujemo izmedju dva elementa
    Beba* curr = glava->next;
    Beba* prev = glava;
    while(curr != NULL && (curr->brBeba > novaBeba->brBeba)){
        prev = curr;
        curr = curr->next;
    }
    //kada se while zavrsi znamo da smo na mestu gde trebamo da budemo
    prev->next = novaBeba;
    novaBeba->next = curr;
    return glava;
}

Beba* ucitajIzFajla(char* filename){
    Beba* novaGlava = NULL;
    FILE* fp = fopen(filename,"r");
    int d,m,g,br;
    if(fp != NULL){
        while(fscanf(fp,"%d %d %d %d",&d,&m,&g,&br) == 4){ //dobar life pro tips od Filipa Filipovica
            Beba* novaBeba = napraviBebu(d,m,g,br);
            novaGlava = ubaciUListu(novaGlava,novaBeba);
        }
        fclose(fp);
    }else{
        printf("Fajl ne postoji!\n");
    }
    return novaGlava;
}

void ispisListe(Beba* glava){
    while(glava != NULL){
        printf("dan : %d, mesec : %d, godina : %d, broj beba :  %d\n",glava->dan,glava->mesec,glava->godina,glava->brBeba);
        glava = glava->next;
    }
}

void izbrisiListu(Beba* glava){
    while(glava != NULL){
        Beba* zaBrisanje = glava;
        glava = glava->next;
        free(zaBrisanje);
    }
}

int ispisPoGodiniIte(Beba* glava,int godina){
    Beba* curr = glava;
    int zbir = 0;
    while(curr != NULL){
        if(curr-> godina == godina){
            zbir+=curr->brBeba;
        }
        curr = curr->next;
    }
    return zbir;
}

int ispisPoGodiniRek(Beba* glava, int godina, int zbir){
    if(glava == NULL){
        return zbir;
    }
    if(glava->godina == godina){
        return ispisPoGodiniRek(glava->next,godina,zbir+glava->brBeba);
    }
    return ispisPoGodiniRek(glava->next,godina,zbir);
}

void ispisBebaPoGodini(Beba* glava){
    int godina;
    printf("Unesite godinu : \n");
    scanf("%d",&godina);
    printf("Iterativno %d\n",ispisPoGodiniIte(glava,godina));
    printf("Rekurzivno %d\n",ispisPoGodiniRek(glava,godina,0));
}

Beba* napraviKopijuListe(Beba* glava){
    if(glava == NULL){
        return NULL;
    }
    Beba* novaGlava = napraviBebu(glava->dan,glava->mesec,glava->godina,glava->brBeba);
    glava = glava->next;
    Beba* prev = novaGlava;
    while(glava != NULL){
        Beba* nova = napraviBebu(glava->dan,glava->mesec,glava->godina,glava->brBeba);
        prev->next = nova;
        prev = nova;
        glava = glava->next;
    }
    return novaGlava;
}

void swapBebe(Beba* beba1,Beba* beba2){
    int tmp = beba1->dan;
    beba1->dan = beba2->dan;
    beba2->dan = tmp;

    tmp = beba1->mesec;
    beba1->mesec = beba2->mesec;
    beba2->mesec = tmp;

    tmp = beba1->godina;
    beba1->godina = beba2->godina;
    beba2->godina = tmp;

    tmp = beba1->brBeba;
    beba1->brBeba = beba2->brBeba;
    beba2->brBeba = tmp;
}


void ispisSortirano(Beba* glava){
    //mnogo dobra fora jer napravimo kopiju i u njoj swapujemo vrijednosti, umjesto da
    //swapujemo citave cvorove sto zna da bude zeznuto jer se moraju pokazivaci dobro pomaknuti
    Beba* novaGlava = napraviKopijuListe(glava);
    Beba* currI = novaGlava;
    Beba* currJ;
    while(currI != NULL){
        currJ = currI->next;
        while(currJ != NULL){
            if(currI->godina < currJ->godina){
                swapBebe(currI,currJ);
            }
            currJ = currJ->next;
        }
        currI = currI->next;
    }

    currI = novaGlava;
    while(currI != NULL){
        currJ = currI->next;
        while(currJ != NULL && currJ->godina == currI->godina){
            if(currI->mesec > currJ->mesec){
                swapBebe(currJ,currJ);
            }
            currJ = currJ->next;
        }
        currI = currI->next;
    }
    int res = novaGlava->brBeba;
    Beba* prev = novaGlava;
    Beba* curr = novaGlava->next;
    while(curr !=NULL){
        if(prev->mesec == curr->mesec && prev->godina == curr->godina){
            res+=curr->brBeba;
        }else{
            printf(" %d, %d, %d\n",prev->mesec,prev->godina,res);
        }
        prev = curr;
        curr = curr->next;
    }
    izbrisiListu(novaGlava);
}

int main(){
    char filename[100];
    int opcija;
    Beba* glava = NULL;
    do{
        printf("[0] - Izlaz\n");
        printf("[1] - Ucitaj iz fajla\n");
        printf("[2] - Broj beba po godini\n");
        printf("[3] - Ispis sortirano\n");
        scanf("%d",&opcija);
        switch(opcija){
            case 0:
                ispisListe(glava);
                izbrisiListu(glava);
                break;
            case 1:
                printf("Unesite ime fajla: (ocene.txt wink wink)\n");
                scanf("%s",filename);
                glava = ucitajIzFajla(filename);
                ispisListe(glava);
                break;
            case 2:
                ispisBebaPoGodini(glava);
                break;
            case 3:
                ispisSortirano(glava);
                break;
            default:
                continue;
        }
    }while(opcija != 0);
    return 0;
}
/*
ocene.txt
25 1 2016 16
14 7 2018 19
7 3 2015 4
18 10 2017 0
5 6 2016 11
18 3 2017 9
22 5 2016 2
17 7 2018 7
29 3 2015 3
4 10 2018 5
7 12 2016 5
 */
