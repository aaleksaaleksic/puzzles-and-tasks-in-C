#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[50];
    int goalR;
    int goalG;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char* name, int goalR, int goalG){
    Node* new = (Node*)malloc(sizeof(Node));
    strcpy(new->name,name);
    new->goalR = goalR;
    new->goalG = goalG;
    new->right = NULL;
    new->left = NULL;
    return new;
}

Node* putInTreeNewNode(Node* root, Node* new){
    if(root == NULL){
        return new;
    }
    if(strcmp(root->name,new->name) > 0){
        root->left = putInTreeNewNode(root->left,new);
    }else if(strcmp(root->name,new->name) == 0){
        root->goalG += new->goalG;
        root->goalR += new->goalR;
        return root;
    }else{
        root->right = putInTreeNewNode(root->right,new);
    }
    return root;
}
//Sampdoria,0:0,Juventus
Node* openFile(){
    FILE* fp = fopen("file.txt","r");
    if(fp == NULL){
        printf("FILE NOT OPENED!\n");
        return NULL;
    }else{
        printf("FILE OPENED!\n");
    }
    Node* root = NULL;
    char line[255];
    while(fgets(line,255,fp)){
        if(line[strlen(line)-1] == '\n'){
            line[strlen(line)-1] = 0;
        }
        char *team1 = strtok(line,",");
        int goal1 = atoi(strtok(NULL,":"));
        int goal2 = atoi(strtok(NULL,","));
        char *team2 = strtok(NULL,",");
        Node* nodeTeam1 = createNode(team1,goal1,0);
        Node* nodeTeam2 = createNode(team2,0,goal2);
        root = putInTreeNewNode(root,nodeTeam1);
        root = putInTreeNewNode(root,nodeTeam2);
    }
    fclose(fp);
    return root;
}
void printNode(Node* root){
    printf("%s %d %d\n",root->name,root->goalR,root->goalG);
}
void printTree(Node* root){
    if(root == NULL){
        return;
    }
    printTree(root->right);
    printNode(root);
    printTree(root->left);
}
void deleteTree(Node* root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}
void menu(){
    printf("------------------------\n");
    printf("1.Load file\n");
    printf("2.Print BST\n");
    printf("3.Do stuff\n");
    printf("4.Do stuff\n");
    printf("5.Delete tree\n");
    printf("------------------------\n");
}

int main(){
    int option;
    Node* root = NULL;
    while(1){
        menu();
        printf("Enter option:");
        scanf("%d",&option);
        switch (option){
            case 1:
                root = openFile();
                break;
            case 2:
                printTree(root);
            case 3:
                break;
            case 4:
                break;
            case 5:
                deleteTree(root);
                return 0;
            default:
                printf("Enter number within the range of options!\n");
                break;
        }
    }
    return 0;
}
/* Sadrzaj text file-a
 Udinese,1:1,Verona
AC Milan,2:5,Sassuolo
Juventus,0:2,Monza
Lazio,1:1,Fiorentina
Napoli,2:1,Roma
Empoli,2:2,Torino
Cremonese,1:2,Inter Milan
Atalanta,2:0,Sampdoria
Bologna,2:0,Spezia
Lecce,1:2,Salernitana
Lazio,4:0,AC Milan
Bologna,1:1,Cremonese
Inter Milan,0:1,Empoli
Sampdoria,0:1,Udinese
Monza,1:1,Sassuolo
Spezia,0:2,Roma
Juventus,3:3,Atalanta
Verona,2:0,Lecce
Salernitana,0:2,Napoli
Fiorentina,0:1,Torino
Empoli,1:0,Sampdoria
Sassuolo,0:2,Lazio
Torino,0:1,Spezia
Udinese,1:2,Bologna
Atalanta,8:2,Salernitana
Roma,2:0,Fiorentina
Cremonese,2:3,Monza
Lecce,2:2,AC Milan
Inter Milan,1:0,Verona
Napoli,5:1,Juventus
Verona,2:0,Cremonese
Bologna,1:2,Atalanta
Salernitana,1:1,Torino
Lazio,2:2,Empoli
Spezia,0:0,Lecce
Sampdoria,0:2,Napoli
AC Milan,2:2,Roma
Fiorentina,2:1,Sassuolo
Juventus,1:0,Udinese
Monza,2:2,Inter Milan
Salernitana,1:2,AC Milan
Sassuolo,1:2,Sampdoria
Spezia,2:2,Atalanta
Torino,1:1,Verona
Lecce,2:1,Lazio
Verona,1:0,Bologna
Cremonese,0:1,Juventus
Fiorentina,1:1,Monza
Inter Milan,1:0,Napoli
Udinese,1:1,Empoli
Atalanta,2:3,Inter Milan
Monza,3:0,Salernitana
Roma,1:1,Torino
Verona,1:2,Spezia
AC Milan,2:1,Fiorentina
Verona,3:0,Lazio
Napoli,3:2,Udinese
Sampdoria,0:2,Lecce
Bologna,3:0,Sassuolo
Empoli,2:0,Cremonese
Verona,0:1,Juventus
Lazio,1:0,Monza
Lecce,2:1,Atalanta
Sassuolo,1:1,Roma
Fiorentina,2:1,Salernitana
Inter Milan,6:1,Bologna
Torino,2:0,Sampdoria
Napoli,2:0,Empoli
Spezia,1:1,Udinese
Cremonese,0:0,AC Milan
Bologna,2:1,Torino
Monza,2:0,Verona
Sampdoria,0:2,Fiorentina
Roma,0:1,Lazio
Juventus,2:0,Inter Milan
Empoli,1:0,Sassuolo
Salernitana,2:2,Cremonese
Atalanta,1:2,Napoli
AC Milan,2:1,Spezia
Udinese,1:1,Lecce
Verona,1:3,Roma
Monza,1:2,Bologna
Empoli,0:2,Atalanta
Cremonese,0:0,Udinese
Spezia,1:2,Fiorentina
Lazio,1:3,Salernitana
Torino,2:1,AC Milan
Napoli,4:0,Sassuolo
Lecce,0:1,Juventus
Inter Milan,3:0,Sampdoria
Cremonese,0:1,Sampdoria
Sassuolo,2:1,Verona
Udinese,1:2,Torino
Bologna,2:0,Lecce
Atalanta,0:2,Lazio
Roma,0:1,Napoli
Salernitana,1:0,Spezia
AC Milan,4:1,Monza
Fiorentina,3:4,Inter Milan
Juventus,4:0,Empoli
Sampdoria,0:1,Roma
Lecce,1:1,Fiorentina
Inter Milan,2:0,Salernitana
Lazio,0:0,Udinese
Spezia,2:2,Cremonese
Napoli,3:2,Bologna
Verona,1:2,AC Milan
Empoli,1:0,Monza
Torino,0:1,Juventus
Atalanta,2:1,Sassuolo
Fiorentina,0:4,Lazio
Torino,1:1,Empoli
Monza,2:0,Spezia
Salernitana,2:1,Verona
Udinese,2:2,Atalanta
Cremonese,1:4,Napoli
Roma,2:1,Lecce
Sassuolo,1:2,Inter Milan
AC Milan,2:0,Juventus
Bologna,1:1,Sampdoria
Verona,1:2,Udinese
Lazio,4:0,Spezia
Lecce,1:1,Cremonese
Sampdoria,0:3,Monza
Sassuolo,5:0,Salernitana
Atalanta,1:0,Fiorentina
Juventus,3:0,Bologna
Napoli,3:1,Torino
Inter Milan,1:2,Roma
Empoli,1:3,AC Milan
Udinese,3:1,Inter Milan
Cremonese,0:4,Lazio
Fiorentina,2:0,Verona
Monza,1:0,Juventus
Roma,0:1,Atalanta
AC Milan,1:2,Napoli
Bologna,0:1,Empoli
Spezia,2:1,Sampdoria
Torino,0:1,Sassuolo
Salernitana,1:2,Lecce
Empoli,1:2,Roma
Atalanta,1:1,Cremonese
Bologna,2:1,Fiorentina
Lecce,1:1,Monza
Sassuolo,1:3,Udinese
Lazio,2:0,Verona
Juventus,2:2,Salernitana
Napoli,1:0,Spezia
Inter Milan,1:0,Torino
Sampdoria,1:2,AC Milan
Monza,0:2,Atalanta
Salernitana,2:2,Empoli
Torino,1:0,Lecce
Cremonese,0:0,Sassuolo
Spezia,2:2,Bologna
Verona,2:1,Sampdoria
Udinese,4:0,Roma
Fiorentina,1:1,Juventus
AC Milan,3:2,Inter Milan
Lazio,1:2,Napoli
Atalanta,3:1,Torino
Bologna,1:1,Salernitana
Empoli,1:1,Verona
Sampdoria,1:1,Lazio
Udinese,1:0,Fiorentina
Juventus,2:0,Spezia
Napoli,1:1,Lecce
Sassuolo,0:0,AC Milan
Inter Milan,3:1,Cremonese
Roma,3:0,Monza
Salernitana,4:0,Sampdoria
Verona,0:1,Atalanta
Fiorentina,0:0,Napoli
Lecce,1:1,Empoli
Cremonese,1:2,Torino
Juventus,1:1,Roma
AC Milan,2:0,Bologna
Spezia,2:2,Sassuolo
Monza,1:2,Udinese
Lazio,3:1,Inter Milan
Roma,1:0,Cremonese
Sampdoria,0:0,Juventus
Empoli,0:0,Fiorentina
Napoli,4:0,Monza
Atalanta,1:1,AC Milan
Bologna,1:1,Verona
Torino,0:0,Lazio
Udinese,0:0,Salernitana
Inter Milan,3:0,Spezia
Sassuolo,1:0,Lecce
Verona,2:5,Napoli
Juventus,3:0,Sassuolo
Fiorentina,3:2,Cremonese
Lazio,2:1,Bologna
Salernitana,0:1,Roma
Spezia,1:0,Empoli
AC Milan,4:2,Udinese
Sampdoria,0:2,Atalanta
Lecce,1:2,Inter Milan
Monza,1:2,Torino
 */




