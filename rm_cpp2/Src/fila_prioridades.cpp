#include "fila_prioridades.h"
#include <stdexcept>
#include <algorithm> // Para std::swap

// Construtor da fila de prioridade
FilaPrioridade::FilaPrioridade() : tamanho(0) {}

// Adiciona uma nova tarefa ao heap e reorganiza para manter a propriedade do min-heap
void FilaPrioridade::adicionar(const Tarefa& tarefa) {
    if (tamanho >= CAPACIDADE_MAXIMA) {
        throw std::runtime_error("Capacidade máxima da fila de prioridade atingida");
    }

    heap[tamanho] = tarefa;  // Adiciona no final do array
    subir(tamanho);          // Reorganiza o heap a partir do novo elemento
    tamanho++;
}

// Remove a tarefa de maior prioridade (no topo do min-heap)
Tarefa FilaPrioridade::remover() {
    if (vazia()) {
        throw std::runtime_error("A fila de prioridade está vazia");
    }

    Tarefa tarefa_prioritaria = heap[0];
    heap[0] = heap[tamanho - 1];  // Substitui o topo com o último elemento
    tamanho--;                    // Reduz o tamanho
    descer(0);                    // Reorganiza o heap a partir do topo

    return tarefa_prioritaria;
}

// Verifica se a fila de prioridade está vazia
bool FilaPrioridade::vazia() const {
    return tamanho == 0;
}

// Move um elemento para cima no heap até que a propriedade do min-heap seja restaurada
void FilaPrioridade::subir(int indice) {
    while (indice > 0 && heap[indice].periodo_ms < heap[pai(indice)].periodo_ms) {
        std::swap(heap[indice], heap[pai(indice)]);
        indice = pai(indice);
    }
}

// Move um elemento para baixo no heap até que a propriedade do min-heap seja restaurada
void FilaPrioridade::descer(int indice) {
    int menor = indice;
    int esq = filhoEsquerdo(indice);
    int dir = filhoDireito(indice);

    if (esq < tamanho && heap[esq].periodo_ms < heap[menor].periodo_ms) {
        menor = esq;
    }
    if (dir < tamanho && heap[dir].periodo_ms < heap[menor].periodo_ms) {
        menor = dir;
    }

    if (menor != indice) {
        std::swap(heap[indice], heap[menor]);
        descer(menor);
    }
}

// Retorna o índice do pai do nó atual
int FilaPrioridade::pai(int indice) const {
    return (indice - 1) / 2;
}

// Retorna o índice do filho esquerdo do nó atual
int FilaPrioridade::filhoEsquerdo(int indice) const {
    return 2 * indice + 1;
}

// Retorna o índice do filho direito do nó atual
int FilaPrioridade::filhoDireito(int indice) const {
    return 2 * indice + 2;
}
