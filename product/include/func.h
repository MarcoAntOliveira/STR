#ifndef FUNC_H
#define FUNC_H

#include <mutex>

class Produtor {
public:
    void produzir(bool* buffer, std::mutex* mtx);
};

class Consumidor {
public:
    void consumir(bool* buffer, std::mutex* mtx);
};

#endif
