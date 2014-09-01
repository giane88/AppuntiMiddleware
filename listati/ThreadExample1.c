#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* Esempio di programma che utilizza la libreria pthread */
void *PrintHello(void * threadid) {
	int *temp;
	temp = (int *) threadid;
	printf("\n%d: Hello World!\n",  *temp);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS];
	int rc,t;
	
	for (t = 0; t < NUM_THREADS; t++) {
		printf("Creazione del thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &t);
		if(rc) {
			printf("ERROR; return code from pthread_create() %d\n",rc);
			exit(-1);
		}
	}
	
	for (t = 0; t < NUM_THREADS; t++) {
		pthread_join(threads[t],NULL);
	}
	pthread_exit(NULL);
}
