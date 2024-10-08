#include "jantar.h"
#include <iostream>

Jantar::Jantar(int Num_filosofos, int Num_hashis) {
    std::random_device rd;  // Para gerar números aleatórios
    std::mt19937 gen(rd()); // Inicializa o gerador
    std::uniform_int_distribution<> distrib(0, 2); // Distribuição de 0 a 2

    // Cria os filósofos com estados aleatórios
    for (int i = 0; i < Num_filosofos; ++i) {
        int estado_inicial = distrib(gen);
        auto filosofo = std::make_unique<Filosofo>(estado_inicial);

        if (estado_inicial == 0) {
            filosofo->pensar();
        } else if (estado_inicial == 1) {
            filosofo->esperar();
        } else if (estado_inicial == 2 && Num_hashis >= 2) {
            filosofo->comer();
            Num_hashis -= 2;
        }

        mesa.emplace_back(std::move(filosofo));
    }
}

int Jantar::checar_estado() {
    for (const auto& filosofo : mesa) {
        if (filosofo->getHashi() == 0) {
            
            return 0;
        } else if (filosofo->getHashi() == 1) {
            
            return 1;
        } else if (filosofo->getHashi() == 2) {
            
            return 2;
        }
    }
    return -1;
}

void Jantar::passa_hashi() {
    for (int i = 0; i < mesa.size(); ++i) {
        auto& filosofo = mesa[i];

        // Se o filósofo não está comendo, ele pode passar o hashi
        if (checar_estado() == 0 || checar_estado() == 1) {
            int next = (i + 1) % mesa.size(); // Próximo filósofo
            filosofo->decrementaHashi();      // Filósofo atual solta um hashi
            mesa[next]->incrementaHashi();    // Próximo filósofo recebe o hashi
        }
    }
}
