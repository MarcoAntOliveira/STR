
#include <stdint.h>
#include "miros.h"
#include "qassert.h"
#include "sem.h"
#include "sem_mutex.h"

// Função de espera (down/P) - decrementa o semáforo e bloqueia se o valor for zero
void sem_signal(sem_t *s, sem_mutex_t *m) {
	mutex_enter_critical(m); // Garante exclusão mútua

    // Bloqueia se não houver recursos disponíveis (empty == 0)
    while (s->empty == 0){
        mutex_exit_critical(m);   // Sai da região crítica antes de bloquear
        OS_delay(TICKS_PER_SEC / 10);  // Evita busy-waiting
        mutex_enter_critical(m);  // Reentra na região crítica
    }

    s->count++;
	s->full++;  // Incrementa o número de itens no buffer (buffer cheio)
	s->empty--; // Decrementa o número de espaços vazios no buffer


    mutex_exit_critical(m);  // Fim da região crítica
}

// Função de sinalização (up/V) - incrementa o semáforo e desbloqueia threads aguardando
void sem_wait(sem_t *s, sem_mutex_t *m) {
    mutex_enter_critical(m);  // Garante exclusão mútua
    while ( s -> full == 0) {
           mutex_exit_critical(m);   // Sai da região crítica antes de bloquear
           OS_delay(TICKS_PER_SEC / 10);  // Evita busy-waiting
           mutex_enter_critical(m);  // Reentra na região crítica
       }
	s->count--;// Se count < BUFFER_SIZE, há espaço no buffer
	s->full--;  // Decrementa o número de itens no buffer
	s->empty++; // Incrementa o número de espaços vazios no buffer

    mutex_exit_critical(m);  // Fim da região crítica
}

