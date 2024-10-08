#include <iostream>
#include <thread>
#include <vector>


// Modifique a função para aceitar um elemento do vetor por referência
void thread_function(int& sum) {
    sum++;
}

int main() {
    int sum = 0; 
    int num_threads = 4;  // Número de threads

    // Criação de um vetor de threads
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        // Cria uma thread e passa o elemento do vetor sums por referência
        threads.push_back(std::thread(thread_function, std::ref(sum)));
    }

    // Espera todas as threads terminarem
    for (auto& t : threads) {
        t.join();
    }

    // Mostra os resultados
    std::cout << "main thread\n";
    std::cout <<"o valor de sum é "<<sum<<std::endl;

    return 0;
}
