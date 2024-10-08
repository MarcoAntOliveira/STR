#include <iostream>
#include <thread>
#include <mutex>
#include "func.h"

void Produtor::produzir(bool* buffer, std::mutex* mtx) {
    std::lock_guard<std::mutex> lock(*mtx); // Garante que o mutex seja liberado automaticamente no final do escopo

    if (*buffer) {
        std::cout << "buffer cheio" << std::endl;
        return;
    }

    *buffer = true;
    std::cout << "produto pronto" << std::endl;
}

void Consumidor::consumir(bool* buffer, std::mutex* mtx) {
    std::lock_guard<std::mutex> lock(*mtx); // Garante que o mutex seja liberado automaticamente no final do escopo

    if (!*buffer) {
        std::cout << "não há produto para consumir" << std::endl;
        return;
    }

    *buffer = false;
    std::cout << "produto consumido" << std::endl;
}
