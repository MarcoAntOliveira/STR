#include <stdint.h>
#include <stdatomic.h>

#include "rm.h"



// Variável atômica para contar tarefas executadas
atomic_int tarefas_executadas;

int main() {
    FilaPrioridade fila;
    initFila(&fila);

    atomic_init(&tarefas_executadas, 0); // Inicializa contador atômico

    // Exemplo de tarefas
    Tarefa t1 = { .id = 1, .prioridade = 3, .periodo = 4, .restante_exec = 10 };
    Tarefa t2 = { .id = 2, .prioridade = 1, .periodo = 6, .restante_exec = 5 };
    Tarefa t3 = { .id = 3, .prioridade = 2, .periodo = 3, .restante_exec = 7 };

    // Inserir tarefas na fila de prioridade
    inserirTarefa(&fila, &t1);
    inserirTarefa(&fila, &t2);
    inserirTarefa(&fila, &t3);

    // Simulação de execução com MiROS
    int tempo_atual = 0;
    while (tempo_atual < 20) { // Executar por um tempo fixo
        Tarefa* tarefa = removerTarefa(&fila);
        if (tarefa != NULL && tarefa_pronta(tarefa, tempo_atual)) {
            executar_tarefa(tarefa);

            // Incrementa contador atômico para acompanhar tarefas executadas
            atomic_fetch_add(&tarefas_executadas, 1);
        }

        // Reinserir a tarefa na fila após execução
        inserirTarefa(&fila, tarefa);

        OS_delay(TICKS_PER_SEC); // Intervalo de tempo entre as execuções
        tempo_atual++;
    }

    // Exibir número total de tarefas executadas após a simulação
    int total_executadas = atomic_load(&tarefas_executadas);
    printf("Total de tarefas executadas: %d\n", total_executadas);

    return 0;
}

