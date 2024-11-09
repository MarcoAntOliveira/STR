

#define BUFFER_SIZE 5

typedef struct {
    int id;
    int prioridade;
    int periodo;
    int restante_exec;
} Tarefa;

typedef struct {
    Tarefa* tarefas[BUFFER_SIZE];
    int size;
} FilaPrioridade;

// Contadores atômicos para o buffer
atomic_int buffer_empty = BUFFER_SIZE;
atomic_int buffer_full = 0;

// Inicializar fila de prioridade
void initFila(FilaPrioridade* fila) {
    fila->size = 0;
}

// Inserir uma tarefa na fila com base na prioridade
void inserirTarefa(FilaPrioridade* fila, Tarefa* tarefa) {
    // Aguarda espaço no buffer
    while (atomic_load(&buffer_empty) <= 0);

    // Decrementa buffer_empty de forma atômica
    atomic_fetch_sub(&buffer_empty, 1);

    int i = fila->size++;
    fila->tarefas[i] = tarefa;

    // Realoca o item na posição correta baseado na prioridade
    while (i > 0 && fila->tarefas[i]->prioridade > fila->tarefas[(i - 1) / 2]->prioridade) {
        Tarefa* temp = fila->tarefas[i];
        fila->tarefas[i] = fila->tarefas[(i - 1) / 2];
        fila->tarefas[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    // Incrementa buffer_full de forma atômica
    atomic_fetch_add(&buffer_full, 1);
}

Tarefa* removerTarefa(FilaPrioridade* fila) {
    // Aguarda até que haja um item no buffer
    while (atomic_load(&buffer_full) <= 0);

    // Decrementa buffer_full de forma atômica
    atomic_fetch_sub(&buffer_full, 1);

    Tarefa* max = fila->tarefas[0];
    fila->tarefas[0] = fila->tarefas[--fila->size];

    // Realoca o item na posição correta baseado na prioridade
    int i = 0;
    while (2 * i + 1 < fila->size) {
        int maxChild = 2 * i + 1;
        if (2 * i + 2 < fila->size && fila->tarefas[2 * i + 2]->prioridade > fila->tarefas[2 * i + 1]->prioridade) {
            maxChild = 2 * i + 2;
        }
        if (fila->tarefas[i]->prioridade >= fila->tarefas[maxChild]->prioridade) break;

        Tarefa* temp = fila->tarefas[i];
        fila->tarefas[i] = fila->tarefas[maxChild];
        fila->tarefas[maxChild] = temp;
        i = maxChild;
    }

    // Incrementa buffer_empty de forma atômica
    atomic_fetch_add(&buffer_empty, 1);
    return max;
}


// Verifica se a tarefa está pronta com base no tempo atual e no período da tarefa
bool tarefa_pronta(Tarefa* tarefa, int tempo_atual) {
    // Se o tempo atual é um múltiplo do período, a tarefa está pronta
    return (tempo_atual % tarefa->periodo) == 0;
}

// Simula a execução da tarefa
void executar_tarefa(Tarefa* tarefa) {
    if (tarefa->restante_exec > 0) {
        // Simula o consumo de um ciclo de execução
        tarefa->restante_exec--;
        printf("Executando tarefa %d, tempo restante: %d\n", tarefa->id, tarefa->restante_exec);

        // Verifica se a tarefa foi concluída
        if (tarefa->restante_exec == 0) {
            printf("Tarefa %d concluída.\n", tarefa->id);
            // Opcional: Reinicializar o tempo de execução restante para simular periodicidade
            tarefa->restante_exec = tarefa->periodo;
        }
    }
}


