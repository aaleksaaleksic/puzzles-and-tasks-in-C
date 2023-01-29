//
// Created by Korisnik on 1/29/2023.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node{
    int dan;
    int mesec;
    int godina;
    int bebe;
    struct Node* next;
}Node;

typedef struct Mesec{

    int mesec;
    int godina;
    int brojBeba;
    struct Mesec* next;

}Mesec;

Mesec* makeMesec(int mesec,int godina,int brojBeba){
    Mesec* newMesec = (Mesec*) malloc(sizeof(Mesec));
    newMesec->mesec = mesec;
    newMesec->godina = godina;
    newMesec->brojBeba = brojBeba;
    newMesec->next = NULL;
    return newMesec;
}

Mesec* dodajMesec(Mesec* glava, Mesec* node){
    if(glava == NULL)
        return node;

    Mesec* copy = glava;
    while(copy -> next != NULL){
        if((node -> godina == copy->godina) && (node->mesec == copy->mesec)){
            copy->brojBeba += node->brojBeba;
            return glava;
        }
        copy = copy -> next;
    }
    node->next = copy->next;
    copy->next = node;

    return glava;
}

Node* makeNode(int dan,int mesec,int godina,int bebe){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->dan = dan;
    newNode->mesec = mesec;
    newNode->godina=godina;
    newNode->bebe = bebe;
    newNode->next = NULL;

    return newNode;
}

Node* addNode(Node* head, Node* newNode){
    if(head == NULL)
        return newNode;

    if(newNode->bebe > head->bebe){
        newNode->next = head;
        return newNode;
    }
    Node* copy = head;

    while(copy->next != NULL && copy->next->bebe > newNode->bebe){
        copy = copy->next;
    }
    newNode->next = copy->next;
    copy->next = newNode;
    return head;
}
void swapNodes(Mesec* node1, Mesec* node2){
    int tmp = node1->godina;
    node1->godina = node2->godina;
    node2->godina = tmp;

    tmp = node1->mesec;
    node1->mesec = node2->mesec;
    node2->mesec = tmp;

    tmp = node1->brojBeba;
    node1->brojBeba = node2->brojBeba;
    node2->brojBeba = tmp;
}
void deleteList(Node* head){
//    if(head == NULL)
//        return;
//    deleteList(head->next);
//    free(head);
    while(head){
        Node* zaBrisanje = head;
        head = head->next;
        free(zaBrisanje);
    }
}
void deleteMesece(Mesec*head){
    if(head == NULL)
        return;
    deleteMesece(head->next);
    free(head);
}

Mesec* sortiraj(Mesec* glava){
    Mesec* copy = glava;
    Mesec* nodeI = glava;
    while(nodeI -> next != NULL){
        Mesec* nodeJ = nodeI->next;
        while(nodeJ != NULL){
            if(nodeI->godina > nodeJ -> godina){
                swapNodes(nodeI,nodeJ);
            }
            else if(nodeI->godina == nodeJ->godina && nodeI->mesec > nodeJ->mesec)
                swapNodes(nodeI,nodeJ);
            nodeJ = nodeJ->next;
        }
        nodeI = nodeI->next;
    }
    return copy;
}

void outputMesece(Node* head){
    Mesec* glava = NULL;
    while(head){
        Mesec* mesec = makeMesec(head->mesec,head->godina,head->bebe);
        glava = dodajMesec(glava,mesec);
        head = head->next;
    }
    Mesec* copy = sortiraj(glava);
    while(copy){
        printf("Godina: %d  Mesec: %d   Bebe: %d\n",copy->godina,copy->mesec,copy->brojBeba);
        copy = copy->next;
    }
    deleteMesece(copy);
}



void outputList(Node* head){
    if(head == NULL){
        printf("Lista je prazna");
    }
    while(head){
        printf("%d %d %d %d\n",head->dan,head->mesec,head->godina,head->bebe);
        head = head->next;
    }
}


void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitaj podatke\n");
    printf("\t[2] Ispis broja rodjenih beba u jednoj godini\n");
    printf("\t[3] Ispis broja rodjenih beba po mesecima sortirano rastuce po godini i mesecu\n");
    printf("\t[4] Brisanje liste i izlazak iz programa\n\n");

}
Node* loadFile(){
    char imeFajla[20];
    printf("Unesite ime fajla:");
    scanf("%s",imeFajla);
    FILE* fp = fopen(imeFajla,"r");
    if(fp != NULL)
        printf("Fajl uspesno otvoren\n");
    else
        printf("Fajl nije uspesno otvoren\n");

    char linija[255];
    Node* head = NULL;
    while(fgets(linija,sizeof(linija),fp)){
        int dan = atoi(strtok(linija," "));
        int mesec = atoi(strtok(NULL," "));
        int godina = atoi(strtok(NULL," "));
        int bebe = atoi(strtok(NULL," "));

        Node* newNode = makeNode(dan,mesec,godina,bebe);
        head = addNode(head,newNode);
    }
    fclose(fp);
    return head;
}

void brojBeba(Node* head, int godina){
    int broj = 0;
    while(head){
        if(head -> godina == godina)
            broj += head ->bebe;
        head = head -> next;
    }
    printf("U %d. godini se rodilo %d beba\n",godina,broj);
}

int brojBeba2(Node* head, int godina, int br){
    if(head == NULL){

        return br;
    }

    if(head ->godina==godina){
        return brojBeba2(head->next,godina,br+head->bebe);
    }

    return brojBeba2(head->next,godina,br);
}




int main(){

    int n;
    Node* head = NULL;
    do{
        meni();
        printf("Unesite komandu:");
        scanf("%d",&n);

        switch (n) {
            case 1 : {
                head = loadFile();
                break;
            }
            case 2 : {
                int godina;
                if(head == NULL)
                    printf("Lista je prazna\n");
                printf("Unesite zeljenu godinu:");
                scanf("%d",&godina);
//                brojBeba(head,godina);
                brojBeba2(head,godina,0);
                int broj = brojBeba2(head,godina,0);
                printf("Broj beba u %d. godini je %d\n",godina,broj);
                break;
            }
            case 3:{
                outputMesece(head);
                break;
            }
            case 4:{
                deleteList(head);
                printf("Lista je uspesno obrisana");
                return 2;

            }
            default:{
                printf("Niste Uneli komandu kako treba\n");
                break;
            }


        }
    }while(n != 5);

    return 0;
}