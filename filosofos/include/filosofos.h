#ifndef FILOSOFOS_H
#define FILOSOFOS_H

#include <mutex>
#include <iostream>
#include <thread>
#include <chrono>


class Filosofo {
private:
    int id;                   // ID do filósofo
    int ciclos_completos;      // Número de ciclos completados (pensar, esperar, comer)
   
public:
    // Construtor
    Filosofo(int id);

    // Função rotina que o filósofo segue (pensar -> esperar -> comer)
    void rotina(std::mutex* hashi_esquerdo, std::mutex* hashi_direito);

    // Ações do filósofo
    void pensar();
    void esperar(std::mutex* hashi_esquerdo, std::mutex* hashi_direito);
    void comer();
    void soltar_hashis(std::mutex* hashi_esquerdo, std::mutex* hashi_direito);
};

#endif // FILOSOFOS_H
