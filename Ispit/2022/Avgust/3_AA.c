#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char banka[50];
    char ime[50];
    int novac;
    char grad[50];
    struct Node* next;
}Node;

typedef struct Grad{
    char ime[50];
    int novac;
    struct Grad* next;
}Grad;

Node* createNode(char* banka, char* ime, int novac, char* grad){
    Node* newNode = (Node*)malloc(sizeof (Node));
    strcpy(newNode->banka,banka);
    strcpy(newNode->ime,ime);
    newNode->novac = novac;
    strcpy(newNode->grad,grad);
    newNode->next = NULL;
    return newNode;
}

Node* addSorted(Node* head,Node* newNode){
    if(head == NULL)
        return newNode;
    if(strcmp(newNode->banka,head->banka) < 0){
        newNode->next = head;
        return newNode;
    }
    Node* copy = head;
    while(copy->next != NULL && strcmp(newNode->banka, copy->next->banka) > 0){ // uvek u uslovu proveravamo za sledeceg od posmatranog
        copy = copy->next;
    }
    newNode->next = copy->next;
    copy->next = newNode;

    return head;
}
void outputList(Node* head){
    if(head == NULL){
        printf("Lista je prazna\n");
        return;
    }
    while(head->next != NULL){
        printf("%s %s %d %s\n", head ->banka, head->ime, head->novac, head->grad);
        head = head->next;
    }
}
Node* loadFile(){
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Avgust\\racuni.txt","r");
    if(fp == NULL){
        printf("Fajl nije uspesno otvoren");
        return NULL;
    }

    Node* head = NULL;

    //Raiffeisen,Pera Peric,7000,Kraljevo
    char line[255];
    while(fgets(line,sizeof(line),fp)){
        char* banka = strtok(line,",");
        char* ime = strtok(NULL,",");
        int novac = atoi(strtok(NULL,","));
        char* grad = strtok(NULL,",");
        if(grad[strlen(grad) - 1] == '\n')
            grad[strlen(grad) - 1] = 0;
        Node* newNode = createNode(banka,ime,novac, grad);
        head = addSorted(head,newNode);
    }
    fclose(fp);
    return head;
}
Grad* createGrad(Node* node){

    Grad* newGrad = (Grad*) malloc(sizeof(Grad));
    strcpy(newGrad->ime, node->grad);
    newGrad->novac = node->novac;
    newGrad->next = NULL;
    return newGrad;
}
Grad* addGrad(Grad* grad_head,Node* node){
    if(grad_head == NULL){
        Grad* g = createGrad(node);
        return g;
    }
    Grad* copy = grad_head;
    while(copy){
        if(strcmp(copy->ime,node->grad) == 0){
            copy->novac += node ->novac;
            return grad_head;
        }
        copy = copy->next;
    }
    Grad* g = createGrad(node);
    g ->next = grad_head;
    return g;
}
void outputWithCriteria(Node* head,int limit){
    Grad* grad_head = NULL; // kreiramo novu listu gradova

    while(head){
        grad_head = addGrad(grad_head,head);
        head = head->next;
    }
    Grad* copy = grad_head;
    while(copy){
        if(copy ->novac >= limit){
            printf("%s ---> %d\n", copy->ime, copy->novac);
        }
        copy = copy->next;
    }
    while(grad_head){
        Grad* zaBrisanje = grad_head;
        grad_head = grad_head->next;
        free(zaBrisanje);
    }
}

Node* obrisi_cvor(Node* glava, int novac){

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
        }
        else{
            kopija = kopija->next;
        }

    }

    return glava;
}


void deleteList(Node* head){
    if(head == NULL)
        return;
    deleteList(head->next);
    free(head);
}


int vratiMaks(Node* head){
    int max = 0;
    while(head){
        if(head->novac>max){
            max = head->novac;
        }
        head = head->next;
    }
    return max;
}

int main(){

    int n;
    Node* head = NULL;

    do{
        printf("[1] Ucitavanje podataka\n");
        printf("[2] Ispis svih bankovnih racuna\n");
        printf("[3] Ispis gradova po kriterijumu uplacenog novca\n");
        printf("[4] Brisanje svih racuna sa manje od navedene svote novca\n");
        printf("[5] Brisanje liste i izlaz iz programa\n\n");
        printf("Unesite komandu:");
        scanf("%d",&n);
        if(n == 1)
            head = loadFile();
        if(n == 2)
            outputList(head);
        if(n == 3){
            int limit;
            printf("Unesite granicu za novac:\n");
            scanf("%d",&limit);
            outputWithCriteria(head,limit);
        }
        if(n == 4){
            int granica = 0;
            int max = vratiMaks(head);
            printf("Unesite granicu za brisanje:");
            scanf("%d", &granica);
            if(granica >= max){
                deleteList(head);
                head = NULL;
            }
            else
                head = obrisi_cvor(head,granica);

        }
        if(n == 5){
            deleteList(head);
            head = NULL;
            break;

        }


    }while(n != 0);

    return 0;


}