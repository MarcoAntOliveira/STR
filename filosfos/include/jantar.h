#ifndef JANTAR_H
#define JANTAR_H

#include "filosofos.h"
#include <vector>
#include <memory>
#include <random>

class Jantar {
private:
    std::vector<std::unique_ptr<Filosofo>> mesa; // Vetor de smart pointers para Filosofo

public:
    Jantar(int Num_filosofos, int Num_hashis); // Construtor
    int checar_estado();
    void passa_hashi();
};

#endif // JANTAR_H
