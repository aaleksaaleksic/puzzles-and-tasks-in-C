#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    char ime[20];
    int visina;
    int tezina;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char* ime,int visina,int tezina){
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->ime,ime);
    newNode->visina = visina;
    newNode->tezina = tezina;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* addNode(Node* root, Node* newNode){
    if(root == NULL)
        return newNode;
    if(strcmp(newNode->ime,root->ime) > 0)
        root->right = addNode(root->right,newNode);
    else
        root->left = addNode(root->left,newNode);
    return root;
}
typedef struct List{
    char ime[15];
    int tezina;
    struct List* next;
}List;
List* makeList(char* ime,int tezina){
    List* nov = (List*) malloc(sizeof(List));
    strcpy(nov->ime,ime);
    nov->tezina = tezina;
    nov->next = NULL;
    return nov;
}
List* addList(List* head, List* nov){
    if(head == NULL)
        return nov;
    List* copy = head;
    while(copy->next != NULL){
        copy = copy->next;
    }
    copy->next = nov;
    return head;
}
void swapList(List* l1, List* l2){
    char tmp[20];
    strcpy(tmp,l1->ime);
    strcpy(l1->ime,l2->ime);
    strcpy(l2->ime,tmp);

    int temp = l1->tezina;
    l1->tezina = l2->tezina;
    l2->tezina = temp;
}
List* sortList(List* head){
    List* copy = head;
    List* listI = head;
    while(listI->next != NULL){
        List* listJ = listI->next;
        while(listJ != NULL){
            if(listI->tezina > listJ->tezina)
                swapList(listI,listJ);
            listJ = listJ->next;
        }
        listI = listI->next;
    }
    return head;
}
Node* loadFile(List** head){
    Node* root = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Januar\\G2\\UUP-21-22-JAN-G2-Z3 fajl.txt","r");
    if(fp != NULL)
        printf("Fajl je uspesno otvoren\n");
    else{
        printf("Greska\n");
        return NULL;
    }
    char linija[255];
    while(fgets(linija,255,fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[strlen(linija) - 1] = 0;
        char* ime = strtok(linija,",");
        int visina = atoi(strtok(NULL,","));
        int tezina = atoi(strtok(NULL,","));
        Node* newNode = createNode(ime,visina,tezina);
        List* list = makeList(ime,tezina);
        *head = addList(*head,list);
        root = addNode(root,newNode);
    }
    *head = sortList(*head);
    fclose(fp);
    return root;
}
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    printf("%s %d %d\n",root->ime,root->visina,root->tezina);
    printTree(root->right);
}
void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis\n");
    printf("\t[3] Najvisa i najniza osoba\n");
    printf("\t[4] Osobe lakse od\n");
    printf("\t[5] Brisanje\n");

}
void najvisaOsoba(char* ime,int* tezina, Node* root,int* max){
    if(root == NULL)
        return;
    najvisaOsoba(ime,tezina,root->left,max);
    if(root->visina > *max){
        strcpy(ime,root->ime);
        *tezina = root->tezina;
        *max = root->visina;
    }
    najvisaOsoba(ime,tezina,root->right,max);
}
void najnizaOsoba(char* ime,int* tezina, Node* root,int* min){
    if(root == NULL)
        return;
    najnizaOsoba(ime,tezina,root->left,min);
    if(root->visina < *min){
        strcpy(ime,root->ime);
        *tezina = root->tezina;
        *min= root->visina;
    }
    najnizaOsoba(ime,tezina,root->right,min);
}
void ispisiLakse(List* head, int unos){
    if(head == NULL)
        return;
    ispisiLakse(head->next,unos);
    if(head->tezina < unos)
        printf("%s  %d\n",head->ime,head->tezina);
}
void deleteTree(Node* root){
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
void deleteList(List* head){
    if(head == NULL)
        return;
    deleteList(head->next);
    free(head);
}

int main(){
    int n;
    Node* root = NULL;
    List* head = NULL;

    do{
        meni();
        printf("\n\nUnesite komandu:");
        scanf("%d",&n);
        switch (n) {
            case 1:{
                root = loadFile(&head);
                break;
            }
            case 2:{
                printTree(root);
                break;
            }
            case 3:{
                int max = INT_MIN;
                int tezina = 0;
                char ime[20];
                najvisaOsoba(ime,&tezina,root,&max);
                printf("Najvisa osoba je: %s %d %d\n",ime,max,tezina);
                int min = INT_MAX;
                najnizaOsoba(ime,&tezina,root,&min);
                printf("Najniza osoba je: %s %d %d\n",ime,min,tezina);
                break;
            }
            case 4:{
                int unos;
                printf("Unesite tezinu:");
                scanf("%d", &unos);
                ispisiLakse(head,unos);
                break;

            }
            case 5:{
                deleteTree(root);
                deleteList(head);
                printf("Uspesno obrisano");
                return 14;
            }

        }
    } while (n!=6);
    return 0;
}
