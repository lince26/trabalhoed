#include <stdio.h>
#include <stdlib.h>
#include "remove.h"
#include "lista_cadastro.h"
#include "abb.h"

typedef struct prod{
    VERTICE;

}PROD;

typedef struct No_fila{
    VERTICE;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add_fila(int VERTICE){
    
        NO * novo = malloc(sizeof(NO));
        novo->VERTICE = VERTICE;
        novo->prox = NULL;
    
        if(inicio == NULL){ //fila vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else{ //adiciona no antigo "fim" da lista
            fim->prox = novo;
            fim = novo;
            tam++;
        }
}


void imprimir_fila(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cod prod: %d\n", aux->VERTICE);
            aux = aux->prox;
    }
}

PROD remover(){
    PROD produto;
        //remover!
        if(inicio != NULL){ //remover do antigo inicio da lista!
            
            NO *lixo = inicio;
            inicio = inicio->prox;
            produto.VERTICE = lixo->VERTICE;
            
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
        }
    return produto;
}

