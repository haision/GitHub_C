#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct person {
	int left;
	int right;
	bool left_bool = false;
	bool right_bool = false;
}

struct perlson A,B,C,D,E;
A.left=5;
A.right=1;

B.left=1;
B.right=2;

C.left=2;
C.right=3;

D.left=3;
D.right=4;

E.left=4;
E.right=5;


pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_fetch = PTHREAD_COND_INITIALIZER;


void releases(void *p)
{
        pthread_mutex_lock(&counter_mutex);

        person.left_bool = false;
        person.right_bool = false;

        pthread_mutex_unlock(&lock);
	pthread_cond_signal(&has_realse);
        printf("Philosopher perlson releases chopsticks %d,%d",person.left,perlson.right);
}

void fetch(struct *p)
{
	
	pthread_mutex_lock(&counter_mutex);
	person.left=1;

        bool eatable = person.left_bool && person.right_bool;
        while(!eatable)
        {
                pthread_cond_wait(&has_release, &lock);
        }

        A.left_bool = true;
        A.right_bool = true;
        B.left_bool = true;
        B.right_bool = true;
        C.left_bool = true;
        C.right_bool = true;
        D.left_bool = true;
        D.right_bool = true;
        E.left_bool = true;
        E.right_bool = true;

	printf("Philosopher %s fetches chopstick",person);
	
	pthread_mutex_unlock(&counter_mutex);
}


int main(int argc,char **argv)
{
	pthread_t tidA,tidB,tidC,tidD,tidE;
	pthread_create(&tidA, NULL, &fetch, NULL);
	pthread_create(&tidB, NULL, &fetch, NULL);
	pthread_create(&tidC, NULL, &fetch, NULL);
	pthread_create(&tidD, NULL, &fetch, NULL);
	pthread_create(&tidE, NULL, &fetch, NULL);

	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	pthread_join(tidC, NULL);
	pthread_join(tidD, NULL);
	pthread_join(tidE, NULL);

	return 0;

}

