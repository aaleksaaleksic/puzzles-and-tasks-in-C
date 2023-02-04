
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value){
    Node* new = (Node*) malloc(sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Node* addNode(Node* root,Node* node){
    if(root == NULL){
        return node;
    }
    if(node->value < root->value)
        root->left = addNode(root->left,node);
    else
        root->right = addNode(root->right,node);

    return root;
}

void outputTree(Node* root){
    if(root == NULL)
        return;

    outputTree(root->left);
    printf("%d ",root->value);
    outputTree(root->right);

}

int numberOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    return numberOfNodes(root->right) + numberOfNodes(root->left) + 1;
}
void nodesOnDepth(Node* root,int depth){
    if(root == NULL)
        return;
    if(depth == 0)
        printf("%d ",root->value);

    nodesOnDepth(root->left,depth - 1);
    nodesOnDepth(root->right,depth - 1);

}
void minimumElement(Node* root){
    if(root == NULL)
        return;
    if(root -> left == NULL)
        printf("Minimum : %d\n",root->value);
    minimumElement(root ->left);
}
void maximumElement(Node* root){
    if(root == NULL)
        return;
    if(root -> right == NULL)
        printf("Maximum : %d\n",root->value);
    maximumElement(root ->right);
}

int max(int a, int b){
    return (a > b) ? a : b;
}
int treeDepth(Node* root){
    if(root == NULL)
        return 0;
    return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}

int leafNumber(Node* root){
    if(root == NULL)
        return 0;
    if(root -> left == NULL && root -> right == NULL){
        printf("%d ",root->value);
        return 1;
    }

    return leafNumber(root->left) + leafNumber(root->right);
}


int main(){

    Node* root = NULL;

    Node* n1 = createNode(8);
    Node* n2 = createNode(3);
    Node* n3 = createNode(10);
    Node* n4 = createNode(1);
    Node* n5 = createNode(6);
    Node* n6 = createNode(14);
    Node* n7 = createNode(4);
    Node* n8 = createNode(7);
    Node* n9 = createNode(13);

    root = addNode(root,n1);
    root = addNode(root,n2);
    root = addNode(root,n3);
    root = addNode(root,n4);
    root = addNode(root,n5);
    root = addNode(root,n6);
    root = addNode(root,n7);
    root = addNode(root,n8);
    root = addNode(root,n9);

    outputTree(root);
    printf("\nBroj cvorova je: %d", numberOfNodes(root));
    printf("\n\n");
    int dubina;
    scanf("%d",&dubina);
    nodesOnDepth(root,dubina);
    printf("\n\n");
    minimumElement(root);
    printf("\n\n");
    maximumElement(root);
    printf("\n\n");
    printf("Dubina stabla je: %d", treeDepth(root));
    printf("\n\n");
    printf("Broj Listova je: %d", leafNumber(root));
    printf("\n\n");


    return 0;
}