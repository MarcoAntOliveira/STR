
#include <stdint.h>
#include "miros.h"
#include "qassert.h"
#include "sem_mutex.h"


void mutex_enter_critical(sem_mutex_t *m){
	Q_ASSERT(!(m->value == 0));
	m ->value = 1;
}


void mutex_exit_critical(sem_mutex_t *m){
	Q_ASSERT(!(m->value == 1));
	 m ->value = 0;
}



