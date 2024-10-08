#ifndef JANTAR_H
#define JANTAR_H

#include <vector>
#include "filosofos.h"
#include <memory>
#include <random>
#include <mutex>
#include <iostream>
#include <thread>

class Jantar {
private:

    std::vector<std::unique_ptr<Filosofo>> mesa; // Vetor de filósofos
    std::vector<std::unique_ptr<std::mutex>> hashis;// Vetor de mutexes para os hashis

public:
    /* 
    construtor para  o jantar que contém um vetor com os filosfos 
    definindo o numero de filosofos
    */
    Jantar(int Num_filosofos);

   /*
   o construtor de jantar chamando o método rotina de filosofos 
   */ 
    void iniciar_jantar(); // Função para iniciar o jantar com threads
};

#endif
