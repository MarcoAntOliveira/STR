#ifndef SEM_H_
#define SEM_H_
#include "miros.h"
#include "sem_mutex.h"



typedef struct {
	uint8_t empty  ;
	uint8_t full  ;
	uint8_t count ;
} sem_t;
void sem_signal(sem_t *s, sem_mutex_t *m);
void sem_wait(sem_t *s, sem_mutex_t *m);




#endif