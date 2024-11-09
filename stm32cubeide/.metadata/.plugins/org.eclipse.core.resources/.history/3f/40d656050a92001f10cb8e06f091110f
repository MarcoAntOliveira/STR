/*
 * rm.h
 *
 *  Created on: Oct 22, 2024
 *      Author: marcos
 */

#ifndef RM_H_
#define RM_H_

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "sem_mutex.h"

#define NUM_TAREFAS 3


typedef struct {
    int id;
    int periodo;  // Tempo de período da tarefa
    int tempo_exec; // Tempo de execução da tarefa
    int restante_exec; // Tempo restante de execução da tarefa
    pthread_t thread_id;
} Tarefa;



void* executar_tarefa(void* arg) ;
int tarefa_pronta(Tarefa *tarefa, int tempo_atual);

#endif /* RM_H_ */

