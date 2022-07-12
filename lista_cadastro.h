#include <stdio.h>
#include <stdlib.h>


typedef struct cad_secretario{
    int cpf;
    char *senha;
}cad_secretario;

typedef struct No{
   
    int cpf;
    char *senha;
    
    //mecanismo p/ unir nos!
    struct No * prox;
    struct No * ant;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add(int cpf, char *senha, int pos){
    
    if(pos >= 0 && pos <= tam){
    
        NO * novo = malloc(sizeof(NO));
        novo->cpf = cpf;
        novo->senha = senha;
        novo->prox = NULL;
        novo->ant = NULL; //NOVIDADE!
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){//inicio
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            novo->ant = fim; //NOVIDADE!
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
            
            NO * aux = inicio;
            for(int i = 0; i < pos; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
            tam++;
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}


void imprimir_cad(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Cpf: %d\n", aux->cpf);
            aux = aux->prox;
    }
}

cad_secretario remover(int pos){
    
    cad_secretario produto;
    if(pos >= 0 && pos < tam){
        //remover!
        if(pos == 0){ //inicio!
            
            NO *lixo = inicio;
            
            inicio = inicio->prox;
            inicio->ant = NULL;
            
            produto.cpf = lixo->cpf;
            produto.senha = lixo->senha;
            
            free(lixo);
            tam--;
            if(tam == 1){
                inicio = NULL;
                fim = NULL;
            }
            
        }else if(pos == tam-1){// fim
            
            NO *lixo = fim;
            fim->ant->prox = NULL;
            fim = fim->ant;
            produto.cpf = lixo->cpf;
            produto.senha = lixo->senha;
            free(lixo);
            tam--;
            
            
        }else { //meio
            
            NO * aux = inicio;
            for(int i = 0; i < pos; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            
            }
            
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            
            produto.cpf = aux->cpf;
            produto.senha = aux->senha;
            
            free(aux);
            tam--;
        }
        
    }else{
        printf("Posicao invalida! :/ \n");
    }
   
    return produto;
}


/*int main(){

    add(29383, "lala", 0);
    add(29848, "umbd", 0);
    add(29646, "2fars", 2);

    printf("Impressao antes da remocao:\n");
    imprimir_cad();
    cad_secretario teste = remover(2);
    printf("Cod prod removido eh:%d\n", teste.cpf);
    printf("depois\n");
    imprimir_cad();
    return 0;
}*/




