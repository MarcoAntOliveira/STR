#ifndef TASKS_H
#define TASKS_H

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



#endif // TASKS_H
