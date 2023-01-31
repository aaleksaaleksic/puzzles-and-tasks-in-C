

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//Kursumlija -8 14
typedef struct Node{
    char grad[20];
    int jutarnja;
    int dnevna;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char* grad, int jutarnja, int dnevna){
    Node* node =(Node*) malloc(sizeof(Node));
    strcpy(node->grad,grad);
    node->jutarnja = jutarnja;
    node->dnevna = dnevna;
    node->left = NULL;
    node->right = NULL;
}

Node* addNode(Node* root, Node* node){
    if(root == NULL){
        return node;
    }
    if(strcmp(root->grad,node->grad) < 0)
        root->right = addNode(root->right,node);
    else
        root->left = addNode(root->left,node);
    return root;
}

void outputTree(Node* root){
    if(root == NULL)
        return;
    outputTree(root->left);
    printf("%s  %d   %d\n",root->grad,root->jutarnja,root->dnevna);
    outputTree(root->right);
}


void meni(){
    printf("MENI:\n");
    printf("\t[1] Ucitavanje podataka\n");
    printf("\t[2] Ispis podataka\n");
    printf("\t[3] Najveca razlika\n");
    printf("\t[4] Ispis prosecne temerature za jutarnju\n");
    printf("\t[5] Brisanje i izlazak\n\n");
}

Node* loadFile(){
    Node* root = NULL;
    FILE* fp = fopen("C:\\Users\\Korisnik\\CLionProjects\\UUP-2\\Ispit\\2019\\Februar\\G2\\grupa2.txt","r");
    if(fp != NULL)
        printf("Fajl je uspesno otvoren\n");
    else{
        printf("Doslo je do greske prilikom otvaranja fajla\n");
        return NULL;
    }
    char linija[255];
    while(fgets(linija,sizeof(linija),fp)){
        if(linija[strlen(linija) - 1] == '\n')
            linija[strlen(linija) - 1] = 0;
        char* grad = strtok(linija," ");
        int jutarnja = atoi(strtok(NULL," "));
        int dnevna = atoi(strtok(NULL," "));
        Node* novi = createNode(grad,jutarnja,dnevna);
        root = addNode(root,novi);
    }
    fclose(fp);
    return root;
}
void najvecaRazlika(Node* root, char* grad, int* razlika){
    if(root == NULL)
        return;
    najvecaRazlika(root->left,grad,razlika);
    if(*razlika < root -> dnevna - root -> jutarnja){
        strcpy(grad,root->grad);
        *razlika = root -> dnevna - root -> jutarnja;
    }
    najvecaRazlika(root->right,grad,razlika);
}
void prosecnaDnevna(Node* root, int* x, double * zbir_dnevnih,int unos){
    if(root == NULL)
        return;
    prosecnaDnevna(root->left,x,zbir_dnevnih,unos);
    if(root->jutarnja <= unos){
        *zbir_dnevnih = *zbir_dnevnih + root->dnevna;
        *x = *x + 1;
    }
    prosecnaDnevna(root->right,x,zbir_dnevnih,unos);
}
void deleteTree(Node* root){
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int main(){

    int n;
    Node* root = NULL;

    do {
        meni();
        printf("Unesite komandu:");
        scanf("%d", &n);

        switch (n) {
            case 1:{
                root = loadFile();
                break;
            }
            case 2: {
                outputTree(root);
                break;
            }
            case 3:{
                int razlika = INT_MIN;
                char grad[20];
                najvecaRazlika(root,grad,&razlika);
                printf("Grad sa najvecom razlikom %d je %s\n",razlika,grad);
                break;
            }
            case 4:{
                int x = 0;
                int unos;
                printf("Unesite temperaturu:");
                scanf("%d",&unos);
                double zbir_dnevnih = 0;
                prosecnaDnevna(root,&x,&zbir_dnevnih,unos);
                printf("Prosecna dnevna je %.2f\n",zbir_dnevnih/x);
                break;
            }
            case 5:{
                deleteTree(root);
                printf("Lista je uspesno obrisana\n");
                return 2;
                break;
            }

        }
    } while(n != 6);
    return 0;
}
