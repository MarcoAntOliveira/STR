#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

int sum = 0;  // Variável global para armazenar o resultado
std::mutex mtx;  // Mutex para proteger a variável sum
std::condition_variable cv;  // Variável de condição para sincronização
bool ready = false;  // Sinal para iniciar as threads

void thread_function(int& sum) {
    // Aguarda até receber o sinal para iniciar
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, []{return ready;});

    // Inicia a execução da função principal da thread
    sum++;
}

int main() {
    int num_threads = 4;  // Número de threads

    // Criação de um vetor de threads
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        // Cria uma thread e passa a variável sum por referência usando std::ref
        threads.push_back(std::thread(thread_function, std::ref(sum)));
    }

    // Sinaliza para as threads começarem
    {
        std::lock_guard<std::mutex> lck(mtx);
        ready = true;
    }
    cv.notify_all();  // Notifica todas as threads

    // Espera todas as threads terminarem
    for (auto& t : threads) {
        t.join();
    }

    // Mostra os resultados
    std::cout << "main thread\n";
    std::cout << "o valor de sum é " << sum << std::endl;

    return 0;
}
