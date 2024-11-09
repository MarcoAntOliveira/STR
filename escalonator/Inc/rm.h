/*
 * rm.h
 *
 *  Created on: Oct 22, 2024
 *      Author: marcos
 */

#ifndef RM_H_
#define RM_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdatomic.h>
#include "miros.h"
#include "qassert.h"
#include <stdbool.h>
#include <unistd.h>

#define MAX_TAREFAS 3


typedef struct {
    int id;
    int prioridade;
    int periodo;
    int restante_exec;
} Tarefa;

typedef struct {
    Tarefa* tarefas[MAX_TAREFAS];
    int size;
} FilaPrioridade;


// Inicializar a fila de prioridades
void initFila(FilaPrioridade* fila);
// Inserir uma tarefa na fila com base na prioridade
void inserirTarefa(FilaPrioridade* fila, Tarefa* tarefa);

// Remover a tarefa com maior prioridade
Tarefa* removerTarefa(FilaPrioridade* fila);
// Função que cada tarefa executará

void executar_tarefa(Tarefa* tarefa);
bool tarefa_pronta(Tarefa* tarefa, int tempo_atual);
#endif /* RM_H_ */

