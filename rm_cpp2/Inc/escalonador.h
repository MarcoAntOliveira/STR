#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include "fila_prioridades.h"

class Escalonador {
public:
    Escalonador();

    // Adiciona uma nova tarefa ao escalonador
    void adicionarTarefa(const Tarefa& tarefa);

    // Executa o loop principal de escalonamento
    void executar();

private:
    FilaPrioridade fila_prioridade;  // Fila de prioridade para armazenar as tarefas

    // Executa uma tarefa específica
    void executarTarefa(Tarefa& tarefa);
};

#endif  // ESCALONADOR_H
