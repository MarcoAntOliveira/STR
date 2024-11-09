#include "sem.h"
#include "sem_mutex.h"
#include "rm.h"


int main() {
    pthread_mutex_init(&lock, NULL);

    Tarefa tarefas[NUM_TAREFAS] = {
        {1, 3, 1, 1},
        {2, 5, 2, 2},
        {3, 8, 3, 3}
    };

    // Criar threads para cada tarefa
    for (int i = 0; i < NUM_TAREFAS; i++) {
        pthread_create(&tarefas[i].thread_id, NULL, executar_tarefa, &tarefas[i]);
    }

    int tempo_total = 20; // Simulação de tempo
    int tempo_atual;

    for (tempo_atual = 0; tempo_atual < tempo_total; tempo_atual++) {
        printf("\nTempo: %d\n", tempo_atual);

        // Iterar sobre as tarefas e verificar se estão prontas
        pthread_mutex_lock(&lock);
        for (int i = 0; i < NUM_TAREFAS; i++) {
            if (tarefa_pronta(&tarefas[i], tempo_atual)) {
                tarefas[i].restante_exec = tarefas[i].tempo_exec;
            }
        }
        pthread_mutex_unlock(&lock);

        sleep(1); // Simula 1 unidade de tempo
    }

    // Finalizar threads (nunca alcançado aqui, mas em uma aplicação real seria necessário)
    for (int i = 0; i < NUM_TAREFAS; i++) {
        pthread_join(tarefas[i].thread_id, NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
