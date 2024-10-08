
// Nome do Aluno: [Marco Ant�nio Lopes Ribeiro]

// Objetivo do Programa: Gerenciar uma lista encadeada de forma ordenada e sem elementos repetidos.

// Como deve ser feita a entrada de dados: O usu�rio deve inserir um inteiro que ser� adicionado � lista.

// O programa permite inser��es, remo��es e consultas de elementos na lista.

// Resultado da execu��o do programa: O programa exibir� mensagens informando o sucesso das opera��es realizadas na lista.


//Bibliotecas necess�rias
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Lista.h"

using namespace std;

//Fun��o principal para demonstrar o uso da Lista
int main() {
    int x; // Vari�vel utilizada para receber o valor digitado do usu�rio e colocar na Lista
    int opcao; // vari�vel utilizada no Menu para testar a Lista

    Lista_Construtor();  // para iniciar a Lista

    do {  // menu com op��es para testar a implementa��o da Lista
        system("cls");
        printf("Programa para uso da Lista Singularmente Encadeada\n\n");
        printf("Escolha uma das opcoes abaixo:");
        printf("\n\n\nMenu: \n");
        printf("1 - Inserir elemento ordenado\n");
        printf("2 - Remover no inicio\n");
        printf("3 - Remover no fim\n");
        printf("4 - Elemento no inicio\n");
        printf("5 - Elemento no fim\n");
        printf("6 - Procurar elemento\n");
        printf("7 - Numero de elementos na lista\n");
        printf("8 - Exibir elemento em uma posicao\n");
        printf("9 - Exibir elementos da Lista\n");
        printf("10 - Remover e exibir todos os elementos\n");
        printf("11 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {
            case 1:
                printf("Digite o dado: ");
                scanf("%d", &x);
                if (Lista_Inserir_Ordenado(x))
                    printf("Elemento inserido\n\n");
                system("pause");
                break;

            case 2:
                if (Lista_Remover_Inicio(x))
                    printf("Dado %d removido\n\n", x);
                else
                    printf("Erro. Lista vazia.\n\n");
                system("pause");
                break;

            case 3:
                if (Lista_Remover_Fim(x))
                    printf("Dado %d removido\n\n", x);
                else
                    printf("Erro. Lista vazia.\n\n");
                system("pause");
                break;

            case 4:
                printf("Elemento no inicio da lista: ");
                if (Lista_Inicio(x))
                    printf("%d\n\n", x);
                else
                    printf("Lista vazia\n\n");
                system("pause");
                break;

            case 5:
                printf("Elemento no fim da lista: ");
                if (Lista_Fim(x))
                    printf("%d\n\n", x);
                else
                    printf("Lista vazia\n\n");
                system("pause");
                break;

            case 6:
                printf("Digite o elemento para pesquisa: ");
                scanf("%d", &x);
                int posicao;
                if (Lista_BuscarPeloElemento(x, posicao))
                    printf("Elemento encontrado na posicao %d.\n\n", posicao);
                else
                    printf("Erro. Elemento nao encontrado.\n\n");
                system("pause");
                break;

            case 7:
                printf("Numero de elementos na lista: %d\n\n", Lista_Tamanho());
                system("pause");
                break;

            case 8:
                printf("Entre com a posicao desejada: ");
                scanf("%d", &posicao);
                if (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("Valor na posicao %d: %d\n", posicao, x);
                } else {
                    printf("Lista vazia ou posicao invalida\n");
                }
                system("pause");
                break;

            case 9:
                printf("Elementos na Lista:\n");
                posicao = 0;
                while (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("Valor na posicao %d: %d\n", posicao, x);
                    posicao++;
                }
                printf("\n");
                system("pause");
                break;

            case 10:
                printf("Todos os elementos: \n");
                while (Lista_Remover_Inicio(x)) {
                    printf("Elemento: %d\n", x);
                }
                printf("\n");
                system("pause");
                break;

            case 11:
                Lista_Destrutor();
                break;

            default:
                printf("Opcao invalida\n\n");
                system("pause");
        }
    } while (opcao != 11);

    return 0;
}
