#ifndef RM_H
#define RM_H

#include <stdint.h>  // Para tipos como uint8_t

class Tarefa {
public:
    uint8_t id;
    uint8_t prioridade;
    uint8_t periodo_ms;  // Adiciona periodo_ms como um membro de Tarefa
    uint32_t proxima_execucao;
    bool ativa;

    Tarefa(uint8_t i, uint8_t p, uint32_t prio, uint8_t periodo);
    
    void atualizar_proxima_execucao();
};

// Escalonador que gerencia as tarefas
class Escalonador {
public:
    Tarefa* obterProximaTarefa(uint8_t prioridade);
private:
    Tarefa tarefas[10];  // Exemplo de array de tarefas
};

#endif // RM_H
