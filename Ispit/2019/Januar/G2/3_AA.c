#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int mesec;
    int godina;
    int decaci;
    int devojcice;
    struct Node* next;
}Node;
typedef struct Godina{
    int godina;
    int decaci;
    int devojcice;
    struct Godina* next;
}Godina;

Godina* makeGodina(Node* node){
    Godina* godina = (Godina*) malloc(sizeof(Godina));
    godina->godina = node->godina;
    godina->decaci = node->decaci;
    godina->devojcice = node->devojcice;
    godina->next = NULL;
    return godina;
}

Godina* addGodina(Godina* head, Godina* g){
    if(head == NULL)
        return g;
    if(head ->godina == g->godina){
        head->devojcice += g->devojcice;
        head->decaci += g->decaci;
        return head;
    }
    Godina* copy = head;
    while(copy != NULL){
        if(copy->godina == g->godina){
            copy->devojcice += g->devojcice;
            copy->decaci += g->decaci;
            return head;
        }
        copy = copy->next;
    }
    g->next = head;
    return g;
}

void swap(Node* node1,Node* node2){
    int tmp = node1->mesec;
    node1->mesec = node2->mesec;
    node2->mesec = tmp;

    tmp = node1->godina;
    node1->godina = node2->godina;
    node2->godina = tmp;

    tmp = node1->decaci;
    node1->decaci = node2->decaci;
    node2->decaci = tmp;

    tmp = node1->devojcice;
    node1->devojcice = node2->devojcice;
    node2->devojcice = tmp;

}
void swapG(Godina* g1, Godina* g2){

    int tmp = g1->godina;
    g1->godina = g2->godina;
    g2->godina = tmp;

    tmp = g1->decaci;
    g1->decaci = g2->decaci;
    g2->decaci = tmp;

    tmp = g1->devojcice;
    g1->devojcice = g2->devojcice;
    g2->devojcice = tmp;

}

Node* sortirajPocetnu(Node* head){
    Node* copy = head;
    Node* nodeI = head;
    while(nodeI -> next != NULL){
        Node* nodeJ = nodeI->next;
        while(nodeJ != NULL){
            if(nodeI->godina > nodeJ->godina){
                swap(nodeI,nodeJ);
            }
            else if(nodeI->godina == nodeJ->godina && nodeI->mesec > nodeJ->mesec)
                swap(nodeI,nodeJ);
            nodeJ = nodeJ->next;
        }
        nodeI = nodeI->next;
    }
    return copy;
}

Node* makeNode(int mesec,int godina,int decaci,int devojcice){

    Node* newNode =(Node*)malloc(sizeof(Node));

    newNode ->mesec = mesec;
    newNode->godina = godina;
    newNode->decaci = decaci;
    newNode->devojcice = devojcice;
    newNode->next = NULL;

    return newNode;

}

Node* addNode(Node* head, Node* newNode){
    if(head == NULL){
        return newNode;
    }
    Node* copy = head;

    while(copy -> next != NULL){
        copy = copy->next;
    }
    newNode->next = copy->next;
    copy->next = newNode;
    return head;
}
//5 2013 180 122
Node* loadFile(){
    Node* head = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2019\\Januar\\G2\\grupa2.txt","r");
    if(fp != NULL){
        printf("Fajl je uspesno otvoren\n");
    }
    else{
        printf("Doslo je do greske prilikom otvaranja fajla\n");
        return NULL;
    }
    char linija[255];
    while(fgets(linija,sizeof(linija),fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[(strlen(linija)) - 1] = 0;
        int mesec = atoi(strtok(linija," "));
        int godina = atoi(strtok(NULL," "));
        int decaci = atoi(strtok(NULL," "));
        int devojcice = atoi(strtok(NULL," "));

        Node* newNode = makeNode(mesec,godina,decaci,devojcice);
        head = addNode(head,newNode);
    }
    head = sortirajPocetnu(head);
    fclose(fp);
    return head;
}

int brojMeseci1(Node* head,int limit){
    int i = 0;
    while(head != NULL){
        if(head->devojcice + head->decaci > limit){
            i++;
        }
        head = head->next;
    }
    return i;
}
int brojMeseci2(Node* head, int n, int limit){
    if(head == NULL){
        return n;
    }
    if(head->decaci + head->devojcice > limit)
        return brojMeseci2(head->next,n+1,limit);
    return brojMeseci2(head->next,n,limit);
}

void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis broja meseci u kome je rodjeno vise od odredjenog broja dece\n");
    printf("\t[3] Ispis broja rodjenih decaka i rodjenih devojcica po godini sortirano\n\n");

}
void outputList(Node* head){
    if(head == NULL)
        return;
    outputList(head->next);
    printf("%d %d %d %d\n",head->mesec,head->godina,head->decaci,head->devojcice);
}
void stampaj(Godina* head){
    if(head == NULL)
        return;
    stampaj(head->next);
    printf("%d %d %d %d\n",head->godina,head->decaci,head->devojcice,head->decaci+head->devojcice);
}
Godina* sortirajGodine(Godina* glava){
    Godina* copy = glava;
    Godina* nodeI = glava;
    while(nodeI -> next != NULL){
        Godina* nodeJ = nodeI->next;
        while(nodeJ != NULL){
            if(nodeJ->devojcice + nodeJ->decaci > nodeI->devojcice + nodeI->decaci)
                swapG(nodeJ,nodeI);
            nodeJ = nodeJ->next;
        }
        nodeI = nodeI->next;
    }
    return copy;
}


void outputGodine(Node* head){
    Godina* glava = NULL;
    Node* copy = head;
    while(copy != NULL){
        Godina* g = makeGodina(copy);
        glava = addGodina(glava,g);
        copy = copy->next;
    }
    glava = sortirajGodine(glava);
    stampaj(glava);
    while(glava != NULL){
        Godina* zaBrisanje = glava;
        glava = glava->next;
        free(zaBrisanje);
    }
}




int main(){

    int n;
    Node* head = NULL;

    do{
        meni();
        printf("Unesite komandu:");
        scanf("%d",&n);
        switch (n) {
            case 1:{
                head = loadFile();
                break;
            }
            case 2:{
//                outputList(head); radi testiranje
                int limit;
                printf("Unesite granicu za bebe:");
                scanf("%d", &limit);
//                printf("Broj meseci kada je rodjeno vise od %d beba je %d\n",limit,brojMeseci1(head,limit));
                printf("Broj meseci kada je rodjeno vise od %d beba je %d\n",limit,brojMeseci2(head,0,limit));
                break;
            }
            case 3:{
                outputGodine(head);
                break;
            }

        }
    }while(n != 5);

    return 0;
}
