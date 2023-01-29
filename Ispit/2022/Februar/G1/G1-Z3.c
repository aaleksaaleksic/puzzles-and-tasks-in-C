#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Cvor{
    char opstina[50];
    char teretana[50];
    int brojSprava;
    int brojKardio;
    struct Cvor* levi;
    struct Cvor* desni;
}Cvor;

void meni(){
    printf("\nMeni: \n \t1. Ucitavanje stabla\n\t2. Ispis svih teretana");
    printf("\n\t3. Ispis teretana sa spravama\n\t4. Ispis svih teretana u odredjenoj opstini");
    printf("\n\t5. Izlaz iz programa\nUnesite opciju: ");
}

void ispisCvor(Cvor* cvor){
    printf("%s (%s) - %d [%d]\n",cvor->teretana,cvor->opstina,cvor->brojSprava,cvor->brojKardio);
}

//Stari grad-Ahilej-120-25
Cvor* kreirajCvor(char linija[]){
    Cvor* nov = (Cvor*)malloc(sizeof(Cvor));
    char* token = strtok(linija,"-");
    strcpy(nov->opstina,token);

    token = strtok(NULL,"-");
    strcpy(nov->teretana,token);

    token = strtok(NULL,"-");
    int brojSprava = atoi(token);
    nov->brojSprava = brojSprava;

    token = strtok(NULL,"-");
    int brojKardio = atoi(token);
    nov->brojKardio = brojKardio;
    nov->levi = NULL;
    nov->desni = NULL;
    return nov;
}
//Po opstini sortirano, skroz levo treba da bude najveca opstina
Cvor* dodajCvor(Cvor* koren, Cvor* noviCvor){
    if(koren == NULL){
        return noviCvor;
    }
    if(strcmp(koren->opstina,noviCvor->opstina) < 0){
        koren->levi = dodajCvor(koren->levi,noviCvor);
    }else{
        koren->desni = dodajCvor(koren->desni,noviCvor);
    }
    return koren;
}

void ispisStabla(Cvor* koren){
    if(koren == NULL){
        return;
    }
    ispisStabla(koren->levi);
    ispisCvor(koren);
    ispisStabla(koren->desni);
}

void ispisStablaRastuce(Cvor* koren){
    if(koren == NULL)
        return;
    ispisStablaRastuce(koren->desni);
    ispisCvor(koren);
    ispisStablaRastuce(koren->levi);
}



int main(){
    Cvor* koren = NULL;
    while(1){
        meni();
        int opcija;
        scanf("%d",&opcija);
        switch (opcija) {
            case 1:{
                FILE* file = fopen("ocene.txt","r");
                if(file == NULL){
                    printf("Doslo je do greske\n");
                    break;
                }else{
                    printf("Uspesno otvoren file");
                }
                char linija[200];
                do{
                    fgets(linija,200,file);
                    Cvor* noviCvor = kreirajCvor(linija);
                    koren = dodajCvor(koren,noviCvor);

                }while(!feof(file));
                break;
            }
            case 2:
                ispisStablaRastuce(koren);
                break;
            case 3:
            case 4:
            case 5:
            default:
                break;
        }
    }








    return 0;
}

/* ocene.txt
Stari grad-Ahilej-120-25
Vozdovac-Domino Luxx-53-13
Palilula-City fitness-60-12
Vozdovac-NonStop fitnes-150-20
Obrenovac-NonStop fitnes-100-20
Karaburma-Ahilej-150-22
Vozdovac-Ahilej-90-25
Savski venac-F45-120-52
Palilula-Fitness klub Tonus-76-18
Stari grad-Fitkultura-80-13
Obrenovac-Lari-50-10
Vozdovac-Pit Gym-110-35
Karaburma-Nonstop fitnes-130-55
Stari grad-Fun fit-75-22
Lazarevac-ForLess-60-12
Palilula-Fitnes centar Tref-90-12
Savski venac-Team fit-83-12
Lazarevac-Max-60-8
 */


