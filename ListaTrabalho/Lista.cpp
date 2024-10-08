// Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef int TipoDado; // Definição do tipo de dado a ser armazenado

struct TipoCelula {
    TipoDado Item; // O valor do elemento
    TipoCelula* Prox; // Aponta para a próxima célula
};

TipoCelula* Frente, * Tras;
int Contador;

void Lista_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}

void Lista_Destrutor() {
    TipoCelula* Temp;

    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;
        free(Temp);
    }

    Tras = NULL;
    Contador = 0;
}

bool Lista_Vazia() {
    return Frente == NULL; // Verifica se a lista está vazia
}

int Lista_Tamanho() {
    return Contador;
}

bool Lista_Inserir_Inicio(int Elemento) {
    TipoCelula* Novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if (Novo == NULL) return false;

    Novo->Item = Elemento;
    Novo->Prox = Frente;

    if (Lista_Vazia())
        Tras = Novo;

    Frente = Novo;
    Contador++;
    return true;
}

bool Lista_Inserir_Fim(int Elemento) {
    TipoCelula* Novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if (Novo == NULL) return false;

    Novo->Item = Elemento;
    Novo->Prox = NULL;

    if (Lista_Vazia())
        Frente = Novo;
    else
        Tras->Prox = Novo;

    Tras = Novo;
    Contador++;
    return true;
}

bool Lista_Inserir(int Elemento, int Posicao) {
    if (Posicao < 0 || Posicao > Contador) return false; // Permite inserção no fim

    TipoCelula* Novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if (Novo == NULL) return false;

    Novo->Item = Elemento;

    if (Posicao == 0) {
        Novo->Prox = Frente;
        Frente = Novo;
        if (Tras == NULL) Tras = Novo;
    } else {
        TipoCelula* Temp = Frente;
        for (int i = 0; i < Posicao - 1; i++) {
            Temp = Temp->Prox;
        }
        Novo->Prox = Temp->Prox;
        Temp->Prox = Novo;
        if (Temp == Tras) Tras = Novo;
    }

    Contador++;
    return true;
}

bool Lista_Inserir_Ordenado(int Elemento) {
    TipoCelula* Novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if (Novo == NULL) return false;

    Novo->Item = Elemento;

    // Insere na lista vazia
    if (Lista_Vazia()) {
        Frente = Novo;
        Tras = Novo;
        Novo->Prox = NULL;
    } else {
        TipoCelula* Temp = Frente;
        TipoCelula* Anterior = NULL;

        while (Temp != NULL && Temp->Item < Elemento) {
            Anterior = Temp;
            Temp = Temp->Prox;
        }

        if (Anterior == NULL) { // Insere no início
            Novo->Prox = Frente;
            Frente = Novo;
        } else {
            Novo->Prox = Temp;
            Anterior->Prox = Novo;
            if (Temp == NULL) { // Atualiza o final da lista
                Tras = Novo;
            }
        }
    }

    Contador++;
    return true;
}

bool Lista_Remover_Inicio(int &Elemento) {
    if (Lista_Vazia()) return false;

    TipoCelula* Temp = Frente;
    Elemento = Frente->Item;
    Frente = Frente->Prox;
    free(Temp);

    if (Frente == NULL) Tras = NULL;

    Contador--;
    return true;
}

bool Lista_Remover_Fim(int &Elemento) {
    if (Lista_Vazia()) return false;

    TipoCelula* Temp = Frente;

    if (Frente == Tras) { // Lista só tem um elemento
        Elemento = Tras->Item;
        free(Tras);
        Frente = Tras = NULL;
    } else {
        while (Temp->Prox != Tras) {
            Temp = Temp->Prox;
        }

        Elemento = Tras->Item;
        free(Tras);
        Tras = Temp;
        Tras->Prox = NULL;
    }

    Contador--;
    return true;
}

bool Lista_Remover(int &Elemento, int Posicao) {
    if (Lista_Vazia() || Posicao < 0 || Posicao >= Contador) return false;

    TipoCelula* Temp = Frente;
    TipoCelula* Temp2 = NULL;

    if (Posicao == 0) {
        Elemento = Frente->Item;
        Frente = Frente->Prox;
        if (Frente == NULL) Tras = NULL;
        free(Temp);
    } else {
        for (int i = 0; i < Posicao; i++) {
            Temp2 = Temp;
            Temp = Temp->Prox;
        }

        Elemento = Temp->Item;
        Temp2->Prox = Temp->Prox;
        if (Temp == Tras) Tras = Temp2;
        free(Temp);
    }

    Contador--;
    return true;
}

bool Lista_Inicio(int &Elemento) {
    if (Lista_Vazia()) return false;
    Elemento = Frente->Item;
    return true;
}

bool Lista_Fim(int &Elemento) {
    if (Lista_Vazia()) return false;
    Elemento = Tras->Item;
    return true;
}

bool Lista_BuscarPeloElemento(int Elemento, int &Posicao) {
    TipoCelula* Temp = Frente;
    int i = 0;

    while (Temp != NULL) {
        if (Temp->Item == Elemento) {
            Posicao = i;
            return true;
        }
        Temp = Temp->Prox;
        i++;
    }

    return false;
}

bool Lista_BuscarPelaPosicao(int &Elemento, int Posicao) {
    if (Lista_Vazia() || Posicao < 0 || Posicao >= Contador) return false;

    TipoCelula* Temp = Frente;
    for (int i = 0; i < Posicao; i++) {
        Temp = Temp->Prox;
    }

    Elemento = Temp->Item;
    return true;
}
