/*
	Instituto Federal de Minas Gerais
	Estrutura de Dados I
	Jonathan Arantes Pinto - 0021625
	
	Arquivo arvore.h
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
} Node;

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int height(Node *N);
Node* newNode(int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node* insert(Node* node, int key);
Node * minValueNode(Node* node);
Node* deleteNode(Node* root, int key);
void in_order(Node * arv);
void pre_order(Node * arv);
void pos_order(Node * arv);
int search(Node * arv, int valor);