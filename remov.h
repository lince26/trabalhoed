#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "lista_cadastro.h"

VERTICE* menorDosMaiores(VERTICE* aux){
    while (aux->esq!=NULL)
        aux=aux->esq;
    return (aux);
}


void remove_abb(int id, VERTICE* raiz){
    if (raiz == NULL){
        printf("\n Remocao invalida!\n");
		return NULL;
    } else if (id < raiz -> id){
        raiz -> esq = remove_abb(id, raiz -> esq);
    } else if (x > raiz -> id){
        raiz -> dir = remove_abb(id, raiz-> dir);
    } else{
        if(raiz->esq == NULL && raiz -> dir == NULL){
            free(raiz);
            return NULL;
        }else if (raiz -> esq != NULL && raiz -> dir != NULL){
            NO * subst = menorDosMaiores(raiz-> dir);

            int aux = subst -> id;
            remove_abb(aux, raiz);
            raiz -> id = aux;
            return aux;
        }else if(raiz -> esq == NULL){
            NO * aux = raiz -> dir;
            free(raiz);
            return aux;
        }else if(raiz -> dir == NULL){
            NO * aux = raiz -> esq;
            free(raiz);
            return aux;
        }
    }
};

