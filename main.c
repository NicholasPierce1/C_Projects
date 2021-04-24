#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static int x = 3;

void* helper(void* args){
	int result = pthread_mutex_lock((pthread_mutex_t*)args);
	int forkResult = fork();
	if(forkResult == 0)
		printf("child\n");
	else
		printf("parent\n");
	printf("id: %d\n", forkResult == 0 ? getpid() : getpid());
	pthread_mutex_unlock((pthread_mutex_t*)args);
	pthread_exit(NULL);
}

void main(void){

	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

	pthread_t thread;
	pthread_create(&thread, NULL, helper,(void*)&mutex);

	void* returnVal = NULL;
	pthread_join(thread, (void**)&returnVal);
	pthread_mutex_destroy(&mutex);

}


