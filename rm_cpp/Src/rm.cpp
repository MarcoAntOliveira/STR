#include "rm.h"

sem_mutex_t *m;

Tarefa::Tarefa(uint8_t i, uint8_t p, uint32_t prio, uint8_t periodo)
    : periodo_ms(periodo), proxima_execucao(0) {  // ordem ajustada para coincidir com a declaração
    // Corpo do construtor
}

void Tarefa::atualizar_proxima_execucao() {
    // Lógica para atualizar a próxima execução
}

Tarefa* Escalonador::obterProximaTarefa(uint8_t prioridade) {
    Tarefa* tarefa_selecionada = nullptr;
    for (int i = 0; i < 10; ++i) {
        if (tarefas[i].ativa && (tarefa_selecionada == nullptr || tarefas[i].prioridade > tarefa_selecionada->prioridade)) {
            tarefa_selecionada = &tarefas[i];
        }
    }
    return tarefa_selecionada;
}

// Balanceia a carga de tarefas entre núcleos
void Escalonador::balancearCarga() {
    int carga_nucleo1 = 0, carga_nucleo2 = 0;

    for (int i = 0; i < num_tarefas; ++i) {
        if (tarefas[i].nucleo == 0) {
            carga_nucleo1++;
        } else {
            carga_nucleo2++;
        }
    }

    // Rebalanceamento de carga simples entre os núcleos
    if (carga_nucleo1 > carga_nucleo2) {
        for (int i = 0; i < num_tarefas; ++i) {
            if (tarefas[i].nucleo == 0 && carga_nucleo1 > carga_nucleo2) {
                tarefas[i].nucleo = 1;
                carga_nucleo1--;
                carga_nucleo2++;
            }
        }
    }
}
