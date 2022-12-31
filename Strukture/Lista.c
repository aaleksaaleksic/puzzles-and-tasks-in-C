#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//Vrlo bitno, CLION da bi citao file on mora biti stavljen u debug folder

//lista uvek ima pocetak koji se zove glava odnosno head
//head pokazuje na pocetak liste ondosno na prvi element liste
typedef struct Node{
    char ime[50]; //pro tip u konstruktoru za
    char banka[50];
    char grad[50];
    int novac;
    //koristimo pokazivac ka iducem elementu
    struct Node* next;
}Node;

typedef struct Grad{
    char ime[50];
    int novac;
    struct Grad* next;
}Grad;

Grad* kreiraj_grad(char* ime, int novac){
    Grad* grad = (Grad*)malloc(sizeof (Grad));
    grad->novac = novac;
    strcpy(grad->ime,ime);
    grad->next = NULL;
    return grad;
}

//konstruktor za jedan node/ element u listi
Node* kreiraj_node(char* ime, char* banka, char* grad, int novac){
    Node* node = malloc(sizeof(Node));
    node->novac = novac;
    strcpy(node->banka,banka);
    strcpy(node->grad,grad);
    strcpy(node->ime,ime);
    node->next = NULL; //pravimo pokazivac next ka nicemu
    return node;
}

Node* dodaj_na_kraj(Node* glava,Node* dodatak){
    //koristimo kopiju glave
    Node* kopija = glava;
    if(glava == NULL){
        return dodatak;
    }
    while(kopija->next != NULL){
        kopija = kopija->next;
    }
    kopija->next = dodatak;
    return glava;
}

Node* dodaj_na_pocetak(Node* glava, Node* dodatak){
    if(glava == NULL){
        return dodatak;
    }
    dodatak->next = glava;
    return dodatak;
}

Node* dodaj_sortirano(Node* glava, Node* dodatak){
    if(glava == NULL){
        return dodatak;
    }
    if(strcmp(dodatak->banka,glava->banka) < 0){
        dodatak->next = glava;
        return dodatak;
    }

    Node* kopija = glava;
    while(kopija->next != NULL && strcmp(kopija->next->banka,dodatak->banka) < 0){
        kopija = kopija->next;
    }
    dodatak->next = kopija->next;
    kopija->next = dodatak;
    return glava;
}

void ispis(Node* glava){
    while(glava != NULL){
        printf("%s %s %s %d\n",glava->banka,glava->ime,glava->grad,glava->novac);
        glava = glava->next;
    }
}

Node* obrisi_element(Node* glava, int novac){
    while(glava->novac <= novac){
        Node* za_brisanje = glava;
        glava = glava->next;
        free(za_brisanje);
    }
    Node* kopija = glava;
    while(kopija->next != NULL){
        if(kopija->next->novac <= novac){
            Node* za_brisanje = kopija->next;
            kopija->next = kopija->next->next;
            free(za_brisanje);
        }else{
            kopija = kopija->next;
        }
    }
    return glava;
}

Node* ucitaj_fajl(){
    //kreiramo instancu fajla i fiksiramoe ime fajla koje ce da se cita
    FILE* file = fopen("racuni.txt","r");
    if(file == NULL){
        printf("Fajl nije otvoren!\n");
    }
    Node* glava = NULL;
    //spremamo se za parsiranje sadrzaja fajla, koristeci string
    //Raiffeisen,Pera Peric,7000,Kraljevo
    char linija[255];
    while(fgets(linija,255,file)){
        char* banka = strtok(linija,",");
        char* ime = strtok(NULL,",");
        int novac = atoi(strtok(NULL,","));
        char* grad = strtok(NULL,",");
        int grad_len = strlen(grad);
        grad[grad_len-1] = 0;
        Node* novi = kreiraj_node(ime,banka,grad,novac);
        glava = dodaj_sortirano(glava,novi);
        //glava = dodaj_na_pocetak(glava,novi);
    }
    fclose(file);
    return glava;
}

Grad* dodaj_u_grad_listu(Grad* glava, Node* dodatak){
    if(glava == NULL){
        Grad* g = kreiraj_grad(dodatak->grad,dodatak->novac);
        return g;
    }
    Grad* cpy = glava;
    while(cpy){
        if(strcmp(cpy->ime,dodatak->grad) == 0){
            cpy->novac += dodatak->novac;
            return glava;
        }
        cpy = cpy->next;
    }
    //grad ne postoji
    Grad* g = kreiraj_grad(dodatak->grad,dodatak->novac);
    g->next = glava;
    return g;
}

void ispis_gradova_preko(int novac,Node* glava){
    Grad * grad_glava = NULL;
    Node* glava_copy = glava;

    while(glava_copy){
        grad_glava = dodaj_u_grad_listu(grad_glava,glava_copy);
        glava_copy = glava_copy->next;
    }
    while(grad_glava){
        if(grad_glava->novac > novac){
            printf("%s-%d\n",grad_glava->ime,grad_glava->novac);
        }
        grad_glava = grad_glava->next;
    }
}

void obrisi_listu(Node* glava){
    while(glava){
        Node* za_brisanje = glava;
        glava = glava->next;
        free(za_brisanje);
    }
}
void obrisi_listu_rekurzivno(Node* glava){
    if(glava == NULL)
        return;
    obrisi_listu_rekurzivno(glava->next);
    free(glava);
}


int main() {
    //rucno moramo prostor da obezbedimo za listu
    //Node* node2 = (Node*)malloc(sizeof (Node));//vraca pokazivac na mesto u memoriji koje je rezervisao
    Node* glava;
    while(1) {
        printf("-----------------------\n");
        printf("Izaberi jednu od opcija:\n");
        printf("1)Ucitaj fajl\n");
        printf("2)Ispisi listu\n");
        printf("3)Ispisi gradove preko \n");
        printf("4)Obrisi elemente liste\n");
        printf("5)Izadji iz programa\n");
        printf("-----------------------\n");
        int opcija;
        scanf("%d", &opcija);
        if (opcija == 1) {
            glava = ucitaj_fajl();
        } else if (opcija == 2) {
            ispis(glava);
        } else if (opcija == 3) {
            printf("Unesi svotu novca\n");
            int nov;
            scanf("%d",&nov);
            ispis_gradova_preko(nov,glava);
        } else if (opcija == 4) {
            printf("Uneti svotu novca za brisanje:\n");
            int novac;
            scanf("%d", &novac);
            glava = obrisi_element(glava, novac);
        } else {
            obrisi_listu(glava);
            return 0;
        }
    }
    //listu su zapravo skupovi cvorova/node-a koje su zapravo neki kontejneri
    //fina stvar kod listi jeste lakse brisanje
    return 0;
}
