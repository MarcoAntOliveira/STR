### Jantar dos Filósofos
Este documento descreve brevemente a implementação do problema do Jantar dos Filósofos em C++. A solução é fortemente baseada em programação orientada a objetos (POO) e faz uso de técnicas avançadas para garantir o gerenciamento eficiente e seguro de recursos.

#### Classes
Classe Filosofo
A classe Filosofo é responsável por definir os filósofos, gerenciar seus estados e controlar a quantidade de ciclos que cada filósofo passa entre "pensar", "esperar" e "comer". Cada filósofo realiza essas ações repetidamente por um número determinado de ciclos.

#### Classe Jantar
A classe Jantar é responsável por:

Criar e inicializar os filósofos e os hashis (recursos compartilhados).
Controlar a interação entre os filósofos e os hashis durante o jantar.
Garantir que os recursos sejam alocados e liberados de maneira segura, utilizando ponteiros inteligentes (std::unique_ptr), que asseguram o gerenciamento automático de memória e previnem vazamentos.
#### Funcionamento
A função iniciar_jantar() na classe Jantar executa a lógica principal do programa. Ela:

Inicializa os filósofos e os hashis usando vetores.
Utiliza ponteiros inteligentes para garantir uma alocação de memória eficiente e segura, evitando a necessidade de liberar manualmente a memória.
Controla a sequência de ações dos filósofos, garantindo que cada um possa alternar entre pensar, esperar pelos hashis e comer, de acordo com as regras do problema.
Garante que o gerenciamento de recursos seja realizado de forma eficaz, evitando condições de corrida e deadlocks, possibilitando que múltiplos filósofos comam simultaneamente desde que não sejam vizinhos imediatos.
Esta implementação é uma abordagem orientada a objetos que facilita a expansão e manutenção do código, além de garantir que os conceitos de gerenciamento de recursos e sincronização em C++ sejam aplicados corretamente.

