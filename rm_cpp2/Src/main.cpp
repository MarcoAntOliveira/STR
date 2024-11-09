#include "escalonador.h"

// Simula o tempo global em milissegundos
uint32_t tempo_global_ms = 0;

int main() {
    Escalonador escalonador;

    // Adiciona algumas tarefas com diferentes períodos
    escalonador.adicionarTarefa(Tarefa(1, 100));  // Maior prioridade
    escalonador.adicionarTarefa(Tarefa(2, 200));
    escalonador.adicionarTarefa(Tarefa(3, 300));  // Menor prioridade

    // Inicia o loop de execução
    escalonador.executar();

    return 0;
}
