#include "filosofos.h"
#include <iostream>
#include <mutex>

void Filosofo::comer() {
    if (hashi == 2) {
        std::unique_lock<std::mutex> lck(mtx);
        comendo = true;
        std::cout << "Filósofo está comendo." << std::endl;
    }
}

void Filosofo::pensar() {
    if (hashi == 0) {
        pensando = true;
        std::cout << "Filósofo está pensando." << std::endl;
    }
}


void Filosofo::esperar() {
    if (hashi == 1) {
        esperando = true;
        std::cout << "Filósofo está esperando." << std::endl;
    }
}

int Filosofo::checa_hashi()
{

    if (getHashi() == 0) {
        return 0;
    } else if (getHashi() == 1) {
        return 1;
    } else if (getHashi() == 2) {
        return 2;
    }
    
    return -1;
}
