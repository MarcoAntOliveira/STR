#include "Escalonador.h"
#include <chrono>
#include <thread>
#include <iostream>

// Construtor do escalonador
Escalonador::Escalonador() {}

// Adiciona uma tarefa ao escalonador
void Escalonador::adicionarTarefa(const Tarefa& tarefa) {
    fila_prioridade.adicionar(tarefa);
}

// Executa o loop principal do escalonador
void Escalonador::executar() {
    while (true) {
        if (!fila_prioridade.vazia()) {
            // Remove a tarefa de maior prioridade (menor período)
            Tarefa tarefa = fila_prioridade.remover();

            // Obtém o tempo atual
            auto agora = std::chrono::steady_clock::now();

            // Verifica se a tarefa está pronta para ser executada
            if (tarefa.proxima_execucao <= agora) {
                executarTarefa(tarefa);
                tarefa.atualizar_proxima_execucao();

                // Reinsere a tarefa na fila com a próxima execução atualizada
                fila_prioridade.adicionar(tarefa);
            } else {
                // Caso a tarefa não esteja pronta, re-adiciona à fila
                fila_prioridade.adicionar(tarefa);
            }
        }

        // Intervalo de espera no escalonador
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// Lógica de execução da tarefa
void Escalonador::executarTarefa(Tarefa& tarefa) {
    std::cout << "Executando tarefa com ID: " << tarefa.id << std::endl;
    // Aqui você colocaria a lógica específica de execução da tarefa
}
