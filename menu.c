#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "lista_cadastro.h"

void clear(){
    char c;
    while (c = getchar() != '\n' && c != EOF){}

char *nome_dado;
int matricula_dada;
char *descricao_dita;
                    
void main(){
    int opcao;
    do
    {
        printf("1- adicionar livro\n");
        printf("2- cadastrar secretário\n");
        printf("3- exibir livros\n");
        printf("4- remover uma encomenda\n");
        printf("5- mover para fila\n");
        printf("6- exibir fila\n");
        printf("0- sair\n");

        scanf("%d", &opcao);

        switch(opcao){
                case 1:
                    
                    
                    system("clear");
                    printf("Escolha as informações a seguir:\n");
                    printf("nome do aluno:\n");
                    scanf("%c", nome_dado);
                    clear();
                    printf("descrição:\n");
                    scanf("%c", descricao_dita);
                    clear();
                    printf("matricula:\n");
                    scanf("%d", &matricula_dada);
                    clear();
                    
                    add_abb(id , nome_dado, matricula_dada, descricao_dita);
                    in_ordem(raiz);
                    
                    break;
                
                case 2:
                    int cpf;
                    char *senha;

                    system("clear");

                    printf("\ncadastro do secretário: ");
                    printf("cpf:\n");
                    scanf("%d", &cpf);
                    clear();
                    printf("senha:\n");
                    scanf("%c", senha);
                    clear();
                    add(0, cpf, senha);

                    break;

                case 3:
                    system("clear");

                    in_ordem(raiz);
                    break;

                case 4:
                    int id;
                    system("clear");

                    printf("Digite o id do no escolhido: ");
                    remove(id,raiz);
                    break;
                case 5:
                    int id;
                    system("clear");

                    printf("Digite o id do no escolhido, para ser adicionado: ");
                    add_fila (id);
                    break;
                
                case 6:
                    system("clear");

                    imprimir_lista();

                    break;

        }

    } while (opcao != 0);
    
    return 0;
}