#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
3. (25p) Napisati program koji učitava podatke o teretanama iz tekstualnog fajla u kom se u jednom redu nalaze
ime opštine, ime teretane, broj sprava, broj sprava za kardio razdvojeni crticom. Primer: Cukarica-Ahilej-92-21.
Napisati meni za interakciju preko konzole i implementirati sledeće opcije:
a) (6p) Učitavanje podataka. Podaci o teretanama učitavaju se u binarno pretraživačko stablo.
 Stablo je alfabetski opadajuće sortirano po opštini.
b) (2p) Ispis svih teretana. Ispisati podatke o svim teretanama sortirane alfabetski rastuće.
c) (8p) Ispis teretana sa spravama. Korisnik unosi broj, ispisati sve teretane čiji je broj sprava
 koje nisu kardio sprave veći od unetog broja.
d) (8p) Ispisati sve teretane u određenoj opštini. Korisnik unosi deo naziva opštine, ukoliko se opština
završava sa unetim slovima onda ispisati sve teretane u njoj.
e) (1p) Izlaz iz programa i brisanje stabla.
*/

char buffer[255];

typedef struct Elem {
    char opstina[20];
    char naziv[30];
    int sveSprave;
    int kardioSprave;
    struct Elem *levi, *desni;
} Elem;

Elem *noviElement() {
    return calloc(1, sizeof (Elem));
}

// ubacuje sortirano opadajuce po opstini
Elem *ubaciUStablo(Elem *koren, Elem *novi) {
    if (koren == NULL) {
        return novi;
    }
    if (strcmp(novi->opstina, koren->opstina) <= 0) {
        // obrnuto sortiranje
        koren->desni = ubaciUStablo(koren->desni, novi);
    } else {
        koren->levi = ubaciUStablo(koren->levi, novi);
    }
    return koren;
}

// ispis opadajuce po opstini *normalno*
void ispisLkd(Elem *koren, int sprave) {
    if (koren != NULL) {
        ispisLkd(koren->levi, sprave);
        if (koren->sveSprave - koren->kardioSprave > sprave) {
            printf("%s (%s) - %d [%d]\n", koren->naziv, koren->opstina, koren->sveSprave, koren->kardioSprave);
//            printf("%20s%31s%4d%4d\n", koren->opstina, koren->naziv, koren->sveSprave, koren->kardioSprave);
        }
        ispisLkd(koren->desni, sprave);
    }
}

// 1 ako se rec zavrsava datim sufiksom, inace 0
int zavrsavaSe(char *rec, char *sufiks) {
    int n2 = strlen(sufiks);
    int n1 = strlen(rec);
    int i;
    if (n1 >= n2) {
        // idemo unazad po recima slovo po slovo
        for (i = 1; i <= n2; i++) {
            // prvi put kad se ne poklapaju, vracamo 0
            if (sufiks[n2-i] != rec[n1-i]) {
                return 0;
            }
        }
        // ako smo stigli do kraja petlje, vracamo 1 (rec se zavrsava sufiksom)
        return 1;
    }
    // ako je broj slova u sufiksu veci nego broj slova u reci, onda vracamo 0
    return 0;
}

// ispis onih ciji se naziv opstine zavrsava unetim slovima
void ispisPoOpstini(Elem *koren, char *krajNazivaOpstine) {
    if (koren != NULL) {
        ispisPoOpstini(koren->levi, krajNazivaOpstine);
        if (zavrsavaSe(koren->opstina, krajNazivaOpstine)) {
            printf("%s (%s) - %d [%d]\n", koren->naziv, koren->opstina, koren->sveSprave, koren->kardioSprave);
        }
        ispisPoOpstini(koren->desni, krajNazivaOpstine);
    }
}

// ispis rastuce po opstini - desno-koren-levo
void ispis(Elem *koren, int sprave) {
    if (koren != NULL) {
        ispis(koren->desni, sprave);
        if (koren->sveSprave - koren->kardioSprave > sprave) {
            printf("%s (%s) - %d [%d]\n", koren->naziv, koren->opstina, koren->sveSprave, koren->kardioSprave);
//            printf("%20s%31s%4d%4d\n", koren->opstina, koren->naziv, koren->sveSprave, koren->kardioSprave);
        }
        ispis(koren->levi, sprave);
    }
}

Elem *ucitajFajl() {
    FILE *f = fopen("ulaz3.txt", "r");
    if (!f) {
        printf("Fajl nije ispravan ili ne postoji.\n");
        return NULL;
    }
    Elem *koren = NULL;
    // Cukarica-Ahilej-92-21
    // feof(f)
    while (fgets(buffer, sizeof (buffer), f)) {
        Elem *novi = noviElement();
        char *token = strtok(buffer, "-");
        strcpy(novi->opstina, token);
        token = strtok(NULL, "-");
        strcpy(novi->naziv, token);
        token = strtok(NULL, "-");
        novi->sveSprave = atoi(token);
        token = strtok(NULL, "\n");
        novi->kardioSprave = atoi(token);
        koren = ubaciUStablo(koren, novi);
    }
    fclose(f);
    return koren;
}

void ispis3(Elem *koren) {
    printf("Unesite broj sprava od koga broj sprava koje nisu kardio treba da bude veci: ");
    fgets(buffer, sizeof (buffer), stdin);
    int br = atoi(buffer);
    ispisLkd(koren, br);
}

void ispis4(Elem *koren) {
    printf("Unesite slova kojima se zavrsava naziv opstine: ");
    fgets(buffer, sizeof (buffer), stdin);
    strtok(buffer, "\n");
    ispisPoOpstini(koren, buffer);
}

int meni() {
    printf("MENI:\n1. Ucitavanje fajla\n2. Ispis svih teretana\n3. Ispis teretana sa spravama\n");
    printf("4. Ispis teretana u opstini...\n5. Izlaz i brisanje stabla\n");
    int op = 0;
    while (1) {
        printf("Unesite opciju: ");
        fgets(buffer, sizeof (buffer), stdin);
        op = atoi(buffer);
        if (op >= 1 && op <= 5) {
            return op;
        }
        printf("Nevalidan unos.\n");
    }
}

Elem *obrisiStablo(Elem *koren) {
    if (koren) {
        obrisiStablo(koren->levi);
        obrisiStablo(koren->desni);
        free(koren);
    }
    return NULL;
}

int main() {
    int op;
    Elem *koren = NULL;
    while (1) {
        op = meni();
        switch (op) {
            case 1:
                koren = obrisiStablo(koren);
                koren = ucitajFajl();
                ispisLkd(koren, -1);
                break;
            case 2:
                ispis(koren, -1);
                break;
            case 3:
                ispis3(koren);
                break;
            case 4:
                ispis4(koren);
                break;
            case 5:
                koren = obrisiStablo(koren);
                return 0;
        }
    }

    return 0;
}
