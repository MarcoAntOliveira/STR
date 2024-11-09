# Tarefa Periódica e Escalonador

## Descrição Geral

Este projeto visa implementar um escalonador de tarefas periódicas para sistemas embarcados utilizando o algoritmo Rate Monotonic (RM), onde tarefas com menor período possuem maior prioridade. A implementação é desenvolvida para sistemas embarcados, e o código foi estruturado de maneira modular para ser escalável e adaptável a diferentes tipos de tarefas e sistemas de tempo real.

Atualmente, o código não está funcional devido a dificuldades encontradas na adequação das funções, mas este README documenta a estrutura, o funcionamento esperado e as limitações atuais.

---

## Estrutura do Código

O projeto está organizado nos seguintes componentes principais:

1. **Tarefa (`rm.h` / `rm.cpp`)**: Define a estrutura das tarefas periódicas, incluindo informações como ID, período e próximo tempo de execução. Cada tarefa possui métodos para atualização de seu tempo de execução e um operador de comparação para permitir a organização em uma fila de prioridade.

2. **Fila de Prioridade (`FilaPrioridade.h` / `FilaPrioridade.cpp`)**: Implementa uma fila de prioridade para gerenciar as tarefas conforme a política de escalonamento RM. Em vez de utilizar bibliotecas de fila de prioridade prontas ou `<vector>`, a fila foi implementada manualmente para atender às restrições do sistema embarcado. A fila organiza as tarefas de modo que aquelas com maior prioridade (menor período) estejam sempre no topo.

3. **Escalonador (`Escalonador.h` / `Escalonador.cpp`)**: Responsável por gerenciar e executar as tarefas periódicas na ordem de prioridade. O escalonador retira as tarefas da fila de prioridade, verifica se é o momento de executá-las e, se necessário, reinsere as tarefas com seu próximo tempo de execução atualizado. Essa classe simula um loop de execução, onde as tarefas são verificadas e executadas.

4. **Semáforos (`sem_mutex.h`)**: Embora a implementação do semáforo não esteja totalmente integrada, o objetivo deste componente é gerenciar a sincronização entre tarefas, garantindo que os recursos compartilhados sejam acessados de maneira controlada.

---

## Estrutura dos Arquivos

- `rm.h` e `rm.cpp`: Contêm a definição e implementação da classe `Tarefa`, com métodos para atualizar o próximo tempo de execução e o operador de comparação para o algoritmo RM.
- `FilaPrioridade.h` e `FilaPrioridade.cpp`: Implementam uma fila de prioridade customizada.
- `Escalonador.h` e `Escalonador.cpp`: Contêm a lógica do escalonador, incluindo o loop de execução das tarefas e métodos de controle.
- `sem_mutex.h`: Planejado para conter semáforos e mutexes, mas ainda não totalmente integrado ao escalonador.

---

## Status Atual e Limitações

### Status Atual

Neste estágio, o código foi estruturado de acordo com a lógica planejada para o escalonamento de tarefas, mas a implementação enfrenta algumas dificuldades:

- **Integração das Funções**: Algumas funções não estão operando conforme o esperado, devido a dificuldades em ajustar corretamente as chamadas e interações entre classes.
- **Simulação do Tempo**: Para atender aos requisitos de sistemas embarcados, o controle de tempo foi inicialmente planejado para utilizar uma variável global simulando o tempo em milissegundos (`tempo_global_ms`). Contudo, a ausência de `<chrono>` exigiu a simulação manual do tempo, e esta abordagem ainda não foi testada em um sistema embarcado real.
- **Semáforos e Mutexes**: A implementação do controle de sincronização entre tarefas ainda está incompleta. O código inclui o esqueleto para integração de semáforos, mas faltam as chamadas adequadas e a lógica para gerenciar acessos simultâneos a recursos compartilhados.

### Limitações Atuais

1. **Dependência de Simulação de Tempo Manual**: O código utiliza uma variável de contagem de tempo manual (`tempo_global_ms`), o que não representa o comportamento exato de um sistema embarcado com temporizadores de hardware.
2. **Dificuldades na Interação entre Componentes**: Ajustes adicionais são necessários para que as funções de `Tarefa`, `FilaPrioridade` e `Escalonador` se integrem corretamente.
3. **Execução de Tarefas**: A execução real das tarefas e a atualização de prioridades ainda não foram verificadas em um ambiente embarcado.

---

## Próximos Passos

Para tornar o código funcional, aqui estão algumas etapas recomendadas:

1. **Ajustar a Interação entre Funções**: Revisar as implementações de `FilaPrioridade` e `Escalonador` para garantir que as funções estejam acessando e manipulando os objetos corretamente.
2. **Integração de Semáforos**: Completar a implementação de `sem_mutex.h` e integrar os semáforos no escalonador para suportar a sincronização entre tarefas.
3. **Testar com um Temporizador de Hardware**: Em um ambiente de sistema embarcado real, substituir a variável `tempo_global_ms` por um timer de hardware ou outro método de contagem de tempo.

---

## Conclusão

Este projeto é uma tentativa de implementar um escalonador RM customizado para sistemas embarcados com funcionalidades básicas de gerenciamento de tarefas. Embora ainda haja limitações e o código não esteja funcional, a estrutura e o design modular servem como base para desenvolvimento futuro.
