
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char opstina[50];
    char naziv[50];
    int sprave;
    int kardio;
    struct Node* left;
    struct Node* right;
}Node;

Node* makeNode(char* opstina, char* naziv, int sprave, int kardio){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->opstina,opstina);
    strcpy(newNode->naziv,naziv);
    newNode->sprave = sprave;
    newNode->kardio = kardio;
    newNode->left = NULL;
    newNode->right =NULL;
    return newNode;
}
Node* addNode(Node* root, Node* newNode){
    if(root == NULL)
        return newNode;
    if(strcmp(root->opstina,newNode->opstina) > 0)
        root->right = addNode(root->right,newNode);
    else
        root->left = addNode(root->left,newNode);
    return root;
}
void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje\n");
    printf("\t[2] Ispis\n");
    printf("\t[3] Ispis t sa spravama\n");
    printf("\t[4] Ispis svih teretana u opstini\n");
    printf("\t[5] Brisanje\n\n");
    printf("Unesite komandu:");

}
Node* loadFile(){
    Node* root = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2022\\Februar\\G1\\UUP-21-22-FEB-G1-ulaz3.txt","r");
    if(fp != NULL)
        printf("Uspesno otvoren fajl\n");
    else{
        printf("Greska");
        return NULL;
    }
    char linija[255];
    while (fgets(linija,255,fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[strlen(linija) - 1] = 0;
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
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    printf("%s %s %d %d\n",root->opstina,root->naziv,root->sprave,root->kardio);
    printTree(root->right);
}
void teretaneSaSpravama(Node* root, int unos){
    if(root == NULL)
        return;
    teretaneSaSpravama(root->left,unos);
    if(root->sprave - root->kardio > unos)
        printf("%s %s %d %d\n",root->opstina,root->naziv,root->sprave,root->kardio);
    teretaneSaSpravama(root->right,unos);
}
void teretaneUOpstini(Node* root, char* unos){
    if(root == NULL)
        return;
    teretaneUOpstini(root->left,unos);
    int unosLen = strlen(unos);
    int opstinaLen = strlen(root->opstina);
    if(strstr(root->opstina,unos) - root->opstina == opstinaLen - unosLen)
        printf("%s %s %d %d\n",root->opstina,root->naziv,root->sprave,root->kardio);
    teretaneUOpstini(root->right,unos);
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
    do {
        meni();
        scanf("%d",&n);
        switch (n){
            case 1:{
                root = loadFile();
                break;
            }
            case 2:{
                printTree(root);
                break;
            }
            case 3:{
                int unos;
                printf("Unesite broj sprava:");
                scanf("%d",&unos);
                teretaneSaSpravama(root,unos);
                break;

            }
            case 4:{
                char unos[20];
                printf("Unesite deo opstine:");
                scanf("%s",unos);
                teretaneUOpstini(root,unos);
                break;
            }
            case 5:{
                deleteTree(root);
                printf("Uspesno obrisano\n");
                return 14;
            }
        }
    } while(n != 6);

    return 0;
}
