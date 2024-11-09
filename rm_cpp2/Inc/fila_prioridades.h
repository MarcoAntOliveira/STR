#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "tasks.h"  // Supondo que rm.h contém a definição da classe Tarefa

class FilaPrioridade {
public:
    FilaPrioridade();

    // Adiciona uma nova tarefa à fila de prioridade
    void adicionar(const Tarefa& tarefa);

    // Remove e retorna a tarefa de maior prioridade (menor período)
    Tarefa remover();

    // Verifica se a fila de prioridade está vazia
    bool vazia() const;

private:
    static const int CAPACIDADE_MAXIMA = 10;  // Capacidade fixa do heap
    Tarefa heap[CAPACIDADE_MAXIMA];           // Array para armazenar o heap
    int tamanho;

    // Funções auxiliares para gerenciar o heap
    void subir(int indice);
    void descer(int indice);
    int pai(int indice) const;
    int filhoEsquerdo(int indice) const;
    int filhoDireito(int indice) const;
};

#endif  // FILA_PRIORIDADE_H
