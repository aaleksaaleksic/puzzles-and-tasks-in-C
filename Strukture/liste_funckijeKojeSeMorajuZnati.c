//
// Created by Korisnik on 12/22/2022.
//
#include <stdio.h>
#include <s
#include <malloc.h>

///// Node je element jednostruko ulancane liste i sadrzi podatak i pokazic
typedef struct Node{
    int data;
    struct Node* next;
}Node;




int main(){
    //// ovako pravimo praznu listu
    Node* head = NULL;
    //// da bismo dodali novi element u listu prvo moramo da ga napravimo
    //// pravimo ga tako sto u memoriji funckijom malloc zauzimamo memoriju za Node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 14;
    newNode->next = NULL;

    //// kad smo modifikovali novi cvor, dodamo ga u listu tako sto kazemo da je on glava, sada je na pocetku
    head = newNode;


    return 0;
}