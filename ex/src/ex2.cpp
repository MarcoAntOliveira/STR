#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// Mutex para proteger a variável sum
std::mutex mtx;  

void thread_function(int& sum) {
    std::lock_guard<std::mutex> lock(mtx);  // Garante acesso exclusivo à variável sum
    sum++;
}

int main() {
    int num_threads = 4;  // Número de threads
    int sum = 0;  // Variável local para armazenar o resultado

    // Criação de um vetor de threads
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        // Cria uma thread e passa a variável sum por referência usando std::ref
        threads.push_back(std::thread(thread_function, std::ref(sum)));
    }

    // Espera todas as threads terminarem
    for (auto& t : threads) {
        t.join();
    }

    // Mostra os resultados
    std::cout << "main thread\n";
    std::cout << "o valor de sum é " << sum << std::endl;

    return 0;
}
