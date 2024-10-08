#include "filosofos.h"


Filosofo::Filosofo(int id) : id(id), ciclos_completos(0) {}

void Filosofo::rotina(std::mutex* hashi_esquerdo, std::mutex* hashi_direito) {
    while (ciclos_completos < 3) {  // cada filosofo pode esperar três ciclos
        pensar();
        esperar(hashi_esquerdo, hashi_direito);
        comer();
        soltar_hashis(hashi_esquerdo, hashi_direito);
        ciclos_completos++;
    }
}

void Filosofo::pensar() {
    std::cout << "Filósofo " << id << " está pensando." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Simula o tempo de pensar
}

void Filosofo::esperar(std::mutex* hashi_esquerdo, std::mutex* hashi_direito) {
    std::cout << "Filósofo " << id << " está esperando pelos hashis." << std::endl;

    if (id % 2 == 0) {
        // Filósofo com ID par: pega primeiro o hashi esquerdo, depois o direito
        hashi_esquerdo->lock();
        hashi_direito->lock();
    } else {
        // Filósofo com ID ímpar: pega primeiro o hashi direito, depois o esquerdo
        hashi_direito->lock();
        hashi_esquerdo->lock();
    }

    std::cout << "Filósofo " << id << " pegou os dois hashis." << std::endl;
}

void Filosofo::comer() {
    std::cout << "Filósofo " << id << " está comendo." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Simula o tempo de comer
}

void Filosofo::soltar_hashis(std::mutex* hashi_esquerdo, std::mutex* hashi_direito) {
    hashi_esquerdo->unlock();
    hashi_direito->unlock();
    std::cout << "Filósofo " << id << " soltou os dois hashis." << std::endl;
}
