#ifndef FILOSOFOS_H
#define FILOSOFOS_H

#include <mutex>

class Filosofo {
private:
    int hashi; // Número de hashis que o filósofo possui (0, 1 ou 2)
    bool comendo = false;
    bool esperando = false;
    bool pensando = false;
    std::mutex mtx; // Para sincronização

public:
    Filosofo(int h) : hashi(h) {} // Construtor que recebe o número de hashis
    void comer();
    void esperar();
    void pensar();
    int getHashi() const { return hashi;   }
    int decrementaHashi(){return ++hashi;  }
    int incrementaHashi(){ return --hashi; }
    int checa_hashi();

};

#endif // FILOSOFOS_H
