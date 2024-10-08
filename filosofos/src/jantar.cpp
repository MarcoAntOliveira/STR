#include "jantar.h"


Jantar::Jantar(int Num_filosofos) {
    // Inicializa os mutexes dos hashis
    for (int i = 0; i < Num_filosofos; ++i) {
        hashis.emplace_back(std::make_unique<std::mutex>());
    }

    // Cria os filósofos
    for (int i = 0; i < Num_filosofos; ++i) {
        auto filosofo = std::make_unique<Filosofo>(i);
        mesa.emplace_back(std::move(filosofo));
    }
}

void Jantar::iniciar_jantar() {
    std::vector<std::thread> threads;

    for (int i = 0; i < mesa.size(); ++i) {
        int esquerda = i;
        int direita = (i + 1) % mesa.size();  // Próximo filósofo
        threads.emplace_back([&, esquerda, direita]() {
            mesa[esquerda]->rotina(hashis[esquerda].get(), hashis[direita].get());
        });
    }

    // Espera todas as threads terminarem
    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Todos os filósofos completaram o jantar." << std::endl;
}
