
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Petar,paleo,2
typedef struct Node{
    char ime[20];
    char dijeta[20];
    int kilogrami;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Dijeta{
    int broj;
    double zbir;
    char naziv[20];
    struct Dijeta* next;

}Dijeta;
Dijeta* makeDijeta(Node* node){
    Dijeta* nova = (Dijeta*) malloc(sizeof(Dijeta));
    nova->broj = 1;
    nova->zbir = node->kilogrami;
    strcpy(nova->naziv,node->dijeta);
    nova -> next = NULL;
    return nova;

}
Dijeta* addDijeta(Dijeta* head, Dijeta* nova){
    if(head == NULL){
        return nova;
    }
    Dijeta* copy = head;
    while(copy != NULL){
        if(strcmp(copy->naziv,nova->naziv) == 0){
            copy->zbir += nova->zbir;
            copy->broj = copy->broj + 1;
            return head;
        }
        copy = copy->next;
    }
    nova->next = head;
    return nova;
}
void ispisiDijete(Dijeta* head){
    if(head == NULL)
        return;
    ispisiDijete(head->next);
    printf("%s %d %f\n",head->naziv,head->broj,head->zbir);
}

Node* makeNode(char* ime, char* dijeta, int kilogrami){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->ime,ime);
    strcpy(newNode->dijeta,dijeta);
    newNode->kilogrami = kilogrami;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* addNode(Node* root, Node* newNode){
    if(root == NULL){
        return newNode;
    }
    if(strcmp(newNode->ime,root->ime) > 0)
        root->right = addNode(root->right,newNode);
    else
         root->left = addNode(root->left,newNode);
    return root;
}
void outputTree(Node* root){
    if(root == NULL)
        return;
    outputTree(root->left);
    printf("%s %s %d\n",root->ime,root->dijeta,root->kilogrami);
    outputTree(root->right);
}
void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis podataka\n");
    printf("\t[3] Ispis najefikasnije dijete\n");
    printf("\t[4] Pronalazenje podataka o osobi\n");
    printf("\t[5] Izlaz iz programa i brisanje stabla\n\n");
    printf("Unesite komandu:");
}

Node* loadFile(Dijeta** head){
    Node* root = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Januar\\G1\\UUP-21-22-JAN-G1-Z3 fajl.txt","r");
    if(fp != NULL)
        printf("Fajl je uspesno otvoren\n");
    else{
        printf("Fajl nije uspesno otvoren\n");
        return NULL;
    }
    char linija[255];
    while(fgets(linija,255,fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[strlen(linija) - 1] = 0;
        char* ime = strtok(linija,",");
        char* dijeta = strtok(NULL,",");
        int kilogrami = atoi(strtok(NULL,","));
        Node* novi = makeNode(ime,dijeta,kilogrami);
        Dijeta* nova = makeDijeta(novi);
        *head = addDijeta(*head,nova);
        root = addNode(root,novi);
    }
    fclose(fp);
    return root;
}
void maxDijeta(Dijeta* head, double* max, char* dijeta){
    if(head == NULL)
        return;
    maxDijeta(head->next,max,dijeta);
    if(head->zbir / head->broj > *max){
        *max = head->zbir / head->broj;
        strcpy(dijeta,head->naziv);
    }
}
void deleteTree(Node* root){
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
void deleteList(Dijeta* head){
    if(head == NULL)
        return;
    deleteList(head->next);
    free(head);
}
char toLower(char ch){

    if(ch >= 'A' && ch <= 'Z')
        ch += 32;
    return ch;

}
int daLiSadrzi(char* unos, char* string){
    for(int i = 0; i < strlen(string); i++){
        if(toLower(string[i]) == toLower(unos[0])){
            int flag = 1;
            for(int j = 0; j < strlen(unos); j++){
                if(toLower(string[i + j]) != toLower(unos[j]))
                    flag = 0;
            }
            if(flag)
                return 1;
        }

    }
    return 0;
}
void ispisiSveInformacije(Node* root,char* unos){
    if(root == NULL)
        return;
    ispisiSveInformacije(root->left,unos);
    if(daLiSadrzi(unos,root->ime)){
        printf("%s  %s   %d \n",root->ime,root->dijeta,root->kilogrami);
    }
    ispisiSveInformacije(root->right,unos);
}

int main(){

    int n;
    Node* root = NULL;
    Dijeta* head = NULL;
    do {
        meni();
        scanf("%d", &n);
        switch (n) {
            case 1: {
                root = loadFile(&head);
                break;
            }
            case 2: {
                outputTree(root);
                printf("\n\nDIJETE\n\n");
                ispisiDijete(head);
                break;
            }
            case 3: {
                double max = 0;
                char dijeta[20];
                dijeta[0] = 0;
                maxDijeta(head,&max,dijeta);
                printf("DIJETA %s   broj : %.2f\n",dijeta,max);
                break;

            }
            case 4:{
                char unos[15];
                printf("Unesite deo imena:");
                scanf("%s",unos);
                ispisiSveInformacije(root,unos);
                break;
            }
            case 5:{
                deleteList(head);
                deleteTree(root);
                printf("Sve je uspesno obrisano");
                return 14;
            }
        }
    }
        while (n != 6);

    return 0;

}