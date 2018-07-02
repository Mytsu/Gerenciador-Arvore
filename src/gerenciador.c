#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

void lerArquivo(FILE * arq);
Node * parseCmd(Node * arv, char *cmd, char *value, int *key);

int main(int args, char ** argc) {
    if (args < 1) {
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
        char *cmd, *value;
        printf("WAIT FOR IT\n");
        fscanf(arq, "%s %s\n", cmd, value);        
        printf("WAIT FOR IT\n");
        printf("%s, %s\n", cmd, value);
        arv = parseCmd(arv, cmd, value, key);
    }
}

Node * parseCmd(Node * arv, char *cmd, char *value, int * key) {
    int vl = 0;
    if (cmd == "INCLUI") {
        vl = (int)strtol(value, NULL, 10);
        return insert(arv, vl);
    }
    else if (cmd == "EXCLUI") {
        vl = (int)strtol(value, NULL, 10);
        return deleteNode(arv, vl);
    }
    else if (cmd == "IMPRIME" && value == "PREORDEM") {
        pre_order(arv);
    }
    else if (cmd == "IMPRIME" && value == "INORDEM") {
        in_order(arv);
    }
    else if (cmd == "IMPRIME" && value == "POSORDEM") {
        pos_order(arv);
    }
    else if (cmd == "BUSCA") {
        
        int sc;
        vl = (int)strtol(value, NULL, 10);
        sc = search(arv, vl);
        if (sc == 0) 
            printf("elemento %d nao encontrado", vl);        
        else printf("%d", sc);
    }
    else if (cmd == "FIM") {
        *key = 0;
        return NULL;
    }
    else {
        printf("comando nao reconhecido\n");
        return NULL;
    }
    return arv;
}