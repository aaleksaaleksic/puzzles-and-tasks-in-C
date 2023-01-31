#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char drzava[20];
    char grad[20];
    int temperatura;
    struct Node* left;
    struct Node* right;
}Node;

Node* makeNode(char* drzava,char* grad,int temperatura){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->drzava,drzava);
    strcpy(newNode->grad,grad);
    newNode->temperatura = temperatura;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* addNode(Node* root, Node* node){
    if(root == NULL)
        return node;
    if(strcmp(node->grad,root->grad) > 0)
        root->right = addNode(root->right,node);

    else
        root->left = addNode(root->left,node);

    return root;
}


void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis podataka\n");
    printf("\t[3] Najhladniji grad\n");
    printf("\t[4] Ispis prosecne temperature za drzavu\n");
    printf("\t[5] Brisanje i izlazak\n\n");
}

Node* loadFile(){
    Node* root = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2019\\Februar\\G1\\grupa1.txt","r");
    if(fp != NULL){
        printf("Fajl je uspesno otvoren\n");
    }
    else{
        printf("Fajl nije uspesno otvoren\n");
        return NULL;
    }
    char linija[255];
    //Nepal Katmandu 24
    while(fgets(linija,sizeof(linija),fp)){
        char* drzava = strtok(linija," ");
        char* grad = strtok(NULL," ");
        int temperatura = atoi(strtok(NULL," "));
        Node* newNode = makeNode(drzava,grad,temperatura);
        root = addNode(root,newNode);
    }
    return root;
}
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    printf("Drzava: %s, Grad: %s, T: %d\n",root->drzava,root->grad,root->temperatura);
    printTree(root->right);
}
void najhladnijiGrad(Node* root,char* drzava,char* grad,int* tempMIN){
    if(root == NULL)
        return;
    najhladnijiGrad(root->left,drzava,grad,tempMIN);
    if(root->temperatura < *tempMIN){
        *tempMIN = root->temperatura;
        strcpy(drzava,root->drzava);
        strcpy(grad,root->grad);
    }
    najhladnijiGrad(root->right,drzava,grad,tempMIN);
}
void prosecnaTemperatura(Node* root,int* x, double* temp,char* unos){
    if(root == NULL){
        return;
    }
    prosecnaTemperatura(root->left,x,temp,unos);
    if(strcmp(root->drzava,unos) == 0){
        *temp += root->temperatura;
        *x = *x + 1;
    }
    prosecnaTemperatura(root->right,x,temp,unos);
}
void deleteList(Node* root){
    if(root == NULL)
        return;
    deleteList(root->left);
    deleteList(root->right);
    free(root);
}
int main(){
    int n;
    Node* root = NULL;
    do {
        meni();
        printf("Unesite komandu:");
        scanf("%d",&n);
        switch (n) {
            case 1:{
                root = loadFile();
                break;
            }
            case 2:{
                if(root == NULL){
                    printf("Lista je prazna\n");
                    break;
                }
                printTree(root);
                break;
            }
            case 3:{
                char grad[50],drzava[50];
                int tempMIN = INT_MAX;
                najhladnijiGrad(root,drzava,grad,&tempMIN);
                printf("Najhladniji grad: %s %s %d\n",drzava,grad,tempMIN);
                break;
            }
            case 4:{
                int x = 0;
                double temp = 0;
                char unos[30];
                printf("Unesite ime drzave:");
                scanf("%s",unos);
                prosecnaTemperatura(root,&x,&temp,unos);
                printf("Prosecna temperatura za %s je %.2f\n",unos,temp/x);
                break;
            }
            case 5:{
                deleteList(root);
                printf("Lista uspesno obrisana\n");
                return 14;
            }

        }
    }while(n != 6);
    return 0;
}