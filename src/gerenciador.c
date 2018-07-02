#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lerArquivo(FILE * arq);
Node * parseCmd(Node * arv, char *cmd, char *value, int *key);

int main(int args, char ** argc) {
    if (args < 2) {
        printf("Use %s [FILENAME]\n", argc[0]);
        return 1;
    }

    FILE * arq = fopen(argc[1], "r+");
    	
    if (arq == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }

    lerArquivo(arq);

    fclose(arq);
    
    return 0;
}

void lerArquivo(FILE * arq) {
    Node * arv = NULL;
    int * key = (int*)malloc(sizeof(int));
    *key = 1;
    while (*key) {
        char buffer[20];
        char *cmd, *value;
        fgets(buffer, sizeof buffer, arq);
        cmd = strtok(buffer, " ");
        value = strtok(NULL, " ");
        
        printf("\n%s %s\n", cmd, value);
        arv = parseCmd(arv, cmd, value, key);
        in_order(arv);
        printf("\n\n");
    }
    destroyTree(arv);
}

Node * parseCmd(Node * arv, char *cmd, char *value, int * key) {
    int vl = 0;
    if ((strcmp("INCLUI", cmd)) == 0) {
        vl = (int)strtol(value, NULL, 10);
        arv = insert(arv, vl);
    }
    else if ((strcmp("EXCLUI", cmd)) == 0) {
        vl = (int)strtol(value, NULL, 10);
        arv = deleteNode(arv, vl);
    }
    else if ( ((strcmp("IMPRIME", cmd)) == 0) && ((strcmp("PREORDEM\n", value)) == 0) ) {
        printf("WAIT FOR IT\n");
        pre_order(arv);
    }
    else if ( ((strcmp("IMPRIME", cmd)) == 0) && ((strcmp("INORDEM\n", value)) == 0) ) {
        printf("WAIT FOR IT\n");
        in_order(arv);
    }
    else if ( ((strcmp("IMPRIME", cmd)) == 0) && ((strcmp("POSORDEM\n", value)) == 0) ) {
        printf("WAIT FOR IT\n");
        pos_order(arv);
    }
    else if ((strcmp("BUSCA", cmd)) == 0) {        
        int sc;
        vl = (int)strtol(value, NULL, 10);
        sc = search(arv, vl);
        if (sc == 0) 
            printf("elemento %d nao encontrado", vl);        
        else printf("%d\n", sc);
    }
    else if ((strcmp("FIM", cmd)) == 0) {
        *key = 0;
    }
    else {
        printf("comando nao reconhecido\n");
    }
    return arv;
}