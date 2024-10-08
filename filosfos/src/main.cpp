#include "jantar.h"

int main() {
    int Num_filosofos = 5;
    int Num_hashis = Num_filosofos - 1 ; // Digamos que temos 5 hashis disponíveis

    Jantar jantar(Num_filosofos, Num_hashis);
    jantar.checar_estado();

    return 0;
}
