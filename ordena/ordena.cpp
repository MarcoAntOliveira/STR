#include <iostream>
#include <vector>
#include <random>

// Função para ordenar o vetor usando o algoritmo de ordenação por bolha
void ordena_bolha(int vetor[], int tam) {
    int i, j, aux;
    for (i = 0; i < tam; i++) {
        for (j = tam - 1; j > i; j--) {
            if (vetor[j - 1] > vetor[j]) {
                aux = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    const int tam = 100000; // Definindo o tamanho do vetor
    int vet[tam];

    // Configuração do gerador de números aleatórios
    std::random_device rd;  // Gera uma seed aleatória
    std::mt19937 gen(rd()); // Inicializa o gerador Mersenne Twister com a seed
    std::uniform_int_distribution<> distrib(1, 100000); // Distribuição uniforme no intervalo [1, 100000]

    // Preenchendo o vetor com valores aleatórios
    for (int i = 0; i < tam; ++i) {
        vet[i] = distrib(gen);
    }

    // Ordenando o vetor
    ordena_bolha(vet, tam);

    // Saída dos primeiros 10 valores do vetor ordenado para verificação
    std::cout << "Os primeiros 10 valores do vetor ordenado são:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << "vet[" << i << "] = " << vet[i] << std::endl;
    }

    return 0;
}
