
#ifndef SEM_MUTEX_H_
#define SEM_MUTEX_H_

#include "miros.h"
static const char Q_this_module_[] = "sem_mutex.h";

typedef struct {

	uint8_t value;

} sem_mutex_t;

void mutex_enter_critical(sem_mutex_t *m);
void mutex_exit_critical(sem_mutex_t *m );





#endif /* SEM_MUTEX_H_ */