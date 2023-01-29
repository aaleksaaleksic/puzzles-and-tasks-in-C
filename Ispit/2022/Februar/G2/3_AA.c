#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Stari grad-Ahilej-120-25

typedef struct Node{
    char opstina[50];
    char ime[50];
    int sprave;
    int kardio_sprave;
    struct Node* left;
    struct Node* right;

}Node;

Node* makeNode(char* opstina, char* ime, int sprave, int kardio){
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->opstina,opstina);
    strcpy(newNode->ime,ime);
    newNode->sprave = sprave;
    newNode->kardio_sprave = kardio;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis svih teretana\n");
    printf("\t[3] Ispis teretana sa brojem sprava vecim od unetog broja\n");
    printf("\t[4] Ispisati sve teretane u odredjenoj opstini\n");
    printf("\t[5] Brisanje liste i izlazak iz programa\n");
}

Node* addNode(Node* root, Node* newNode){
    if(root == NULL)
        return newNode;
    if(strcmp(newNode->opstina,root->opstina) > 0)
        root->left = addNode(root->left,newNode);
    else
        root -> right = addNode(root->right,newNode);
    return root;
}

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->right);
    printf("\t%s  %s  %d  %d\n",root->opstina,root->ime,root->sprave,root->kardio_sprave);
    printTree(root->left);
}

Node* loadFile(){
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Februar\\G2\\UUP-21-22-FEB-G1-ulaz3.txt","r");
    Node* root = NULL;
    if(fp == NULL){
        printf("Fajl nije uspesno otvoren\n");
        return NULL;
    }
    else
        printf("Fajl je uspesno otvoren\n");

    char linija[255];
    while(fgets(linija,sizeof(linija),fp)){
        if(linija[strlen((linija) - 1)] == '\n')
            linija[strlen((linija) - 1)] == 0;

        char* opstina = strtok(linija,"-");
        char* naziv = strtok(NULL,"-");
        int sprave = atoi(strtok(NULL,"-"));
        int kardio = atoi(strtok(NULL,"-"));

        Node* novi = makeNode(opstina,naziv,sprave,kardio);
        root = addNode(root,novi);
    }
    fclose(fp);
    return root;
}
void criteriaOutput(Node* root, int limit){
    if(root == NULL)
        return;
    criteriaOutput(root->left,limit);
    if(((root->sprave) - (root->kardio_sprave)) > limit){
        printf("\t%s  %s  %d  %d\n",root->opstina,root->ime,root->sprave,root->kardio_sprave);
    }
    criteriaOutput(root->right,limit);
}
void poOpstinama(Node* root, char* deo){
    if(root == NULL)
        return;
    poOpstinama(root->left,deo);
    int offset = strlen(deo);
    int duzina = strlen(root ->opstina);
    if(strcmp(root->opstina + duzina - offset,deo) == 0)
        printf("\t%s  %s  %d  %d\n",root->opstina,root->ime,root->sprave,root->kardio_sprave);
    poOpstinama(root->right,deo);
}

void deleteTree(Node* root){
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main(){

    Node* root = NULL;
    int n;
    do{
        meni();
        printf("\n\nUnesite komandu:");
        scanf("%d",&n);
        switch (n) {
            case 1 :{
                root = loadFile();
                break;
            }
            case 2 : {
                if(root == NULL)
                    printf("Stablo je prazno\n");
                printTree(root);
                break;
            }
            case 3: {
                int limit;
                printf("Unesite limit za sprave:");
                scanf("%d",&limit);
                criteriaOutput(root,limit);
                break;
            }
            case 4:{
                char deo[50];
                printf("Unesite deo naziva opstine:");
                scanf("%s",deo);
                poOpstinama(root,deo);
                break;
            }
            case 5:{
                deleteTree(root);
                return 2;
                }

        }
    } while(n != 5);


    return 0;
}
