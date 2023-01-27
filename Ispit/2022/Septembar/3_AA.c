//
// Created by Korisnik on 1/26/2023.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct Node{
    char prodavnica[50];
    char proizvod[50];
    int cena;
    int kolicina;
    struct Node* next;
}Node;


typedef struct Prodavnica{
    char naziv[15];
    int lager;
    struct Prodavnica* next;
}Prodavnica;

Prodavnica* makeProdavnica(char* naziv, int lager){
    Prodavnica* nova = (Prodavnica*) malloc(sizeof(Prodavnica));
    strcpy(nova->naziv,naziv);
    nova->lager = lager;
    nova->next = NULL;
    return nova;
}

Prodavnica* dodajProdavnicu(Prodavnica* prodavnica_head,Prodavnica* nova){
    if(prodavnica_head == NULL){
        return nova;
    }
    Prodavnica* copy = prodavnica_head;
    while(copy!=NULL){
        if(strcmp(copy->naziv,nova->naziv) == 0){
            copy->lager += nova->lager;
            return prodavnica_head;
        }
        copy = copy->next;
    }
    nova -> next = prodavnica_head;
    return nova;
}

Node* createNode(char* prodavnica, char* proizvod, int cena, int kolicina){
    Node* newNode =(Node*)malloc(sizeof(Node));
    strcpy(newNode->prodavnica,prodavnica);
    strcpy(newNode->proizvod,proizvod);
    newNode->cena = cena;
    newNode->kolicina = kolicina;
    newNode->next = NULL;
    return newNode;
}

Node* addSorted(Node* head, Node* newNode){
    if(head == NULL){
        return newNode;
    }
    if(strcmp(head->proizvod,newNode->proizvod) > 0 || (strcmp(head->proizvod,newNode->proizvod) == 0 && head->kolicina > newNode->kolicina)){
        newNode->next = head;
        return newNode;
    }
    Node* copy = head;
    while(copy->next != NULL && strcmp(copy->next->proizvod,newNode->proizvod) < 0){
        copy = copy->next;
    }
    while(copy->next != NULL && strcmp(copy->next->proizvod,newNode->proizvod) == 0 && (copy->kolicina < newNode->kolicina)){
        copy = copy->next;
    }
    newNode->next = copy->next;
    copy->next = newNode;
    return head;
}

Node* loadFile(){
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Septembar\\prodavnice.txt","r");
    if(fp == NULL){
        printf("Fajl nije uspesno otvoren");
        return NULL;
    }
    Node* head = NULL;
    char line[255];
    //Roda,surutka,68,7
    while(fgets(line,sizeof(line),fp)){
        char* prodavnica = strtok(line,",");
        char* proizvod = strtok(NULL,",");
        int cena = atoi(strtok(NULL,","));
        int kolicina = atoi(strtok(NULL,","));
        Node* newNode = createNode(prodavnica,proizvod,cena,kolicina);
        head = addSorted(head,newNode);
    }
    fclose(fp);
    return head;

}
void outputList(Node* head){
    if(head == NULL)
        return;
    printf("%s %s %d %d\n",head->prodavnica,head->proizvod,head->cena,head->kolicina);
    outputList(head->next);
}

int cenaSvudaVeca(Node* head, char* proizvod, int limit){

    while(head){
        if(strcmp(head->proizvod,proizvod) == 0){
            if(head->cena < limit)
                return 0;
        }
        head = head->next;
    }
    return 1;
}

Node* deleteByCriteria(Node* head, int limit){

    while(cenaSvudaVeca(head,head->proizvod,limit)){
        Node* zaBrisanje = head;
        head = head->next;
        free(zaBrisanje);
    }

    Node* copy = head;

    while(copy->next != NULL){
        if(cenaSvudaVeca(head,copy->next->proizvod,limit)){
            Node* zaBrisanje = copy->next;
            copy -> next = copy-> next-> next;
            free(zaBrisanje);
            continue;
        }
        copy = copy->next;
    }
    return head;
}
Node* deleteList(Node* head){

    while(head){
        Node* zaBrisanje = head;
        head = head -> next;
        free(zaBrisanje);
    }
    return head;
}
void outputWithCriteria(Node* head){
    Prodavnica* head_prodavnica = NULL;
    Node* copy = head;
    while(copy){
        Prodavnica* p = makeProdavnica(copy->prodavnica,(copy->cena * copy -> kolicina));
        head_prodavnica = dodajProdavnicu(head_prodavnica,p);
        copy = copy->next;
    }
    Prodavnica* copy1 = head_prodavnica;
    while(copy1){
        if(copy1->lager < 10000)
            printf("%s --> %d\n",copy1->naziv,copy1->lager);
        copy1 = copy1 -> next;
    }
    while(head_prodavnica){
        Prodavnica* zaBrisanje = head_prodavnica;
        head_prodavnica = head_prodavnica ->next;
        free(head_prodavnica);
    }
}

int main(){

    int n;
    Node* head = NULL;
    do{
        printf("[1] Ucitavanje podataka u listu\n");
        printf("[2] Ispis svih unosa iz liste\n");
        printf("[3] Brisanje svih unosa robe cija je cena svuda veca od unetog broja\n");
        printf("[4] Ispis svih prodavnica koje na lageru imaju ukupno robe za manje od 10000 dinara sortirano po nazivu prodavnice.\n");
        printf("[5] Izlaz iz programa i brisanje liste\n\n");
        printf("Unesite komandu:");
        scanf("%d", &n);
        if(n == 1)
            head = loadFile();
        if(n == 2){
            if(head == NULL)
                printf("Lista je prazna\n");
            else
                outputList(head);
        }
        if(n == 3){
            int limit;
            printf("Unesite granicu za brisanje:");
            scanf("%d",&limit);
            head = deleteByCriteria(head,limit);
        }
        if(n == 4){
            outputWithCriteria(head);
        }
        if(n == 5){

           head = deleteList(head);
        }








    }while(n != 0);

    return 0;
}