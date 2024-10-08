#include <iostream>
#include <thread>
#include "func.h"

int main(int argc, char* argv[]) {
    bool buffer = false;
    std::mutex mtx;  // Mutex compartilhado

    Produtor tst1;
    Consumidor ts1;
    Consumidor ts2;
    Produtor tst2;

    std::thread t2(&Produtor::produzir, &tst1, &buffer, &mtx);
    t2.join();
    std::cout << "Buffer após produção: " << buffer << std::endl;

    std::thread t4(&Produtor::produzir, &tst2, &buffer, &mtx);
    t2.join();
    std::cout << "Buffer após produção: " << buffer << std::endl;


    std::thread t1(&Consumidor::consumir, &ts1, &buffer, &mtx);
    t1.join();
    std::cout << "Buffer após consumo: " << buffer << std::endl;

    std::thread t3(&Consumidor::consumir, &ts2, &buffer, &mtx);
    t3.join();
    std::cout << "Buffer após segundo consumo: " << buffer << std::endl;

    return 0;
}
