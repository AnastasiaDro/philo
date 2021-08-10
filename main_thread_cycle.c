#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int mails = 0;

pthread_mutex_t mutex;
void *routine()
{
	int i = 0;
	while(i < 100)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);

		i++;
	}
	printf("thread has finished execution\n");
}

int main()
{
	pthread_t th[4];
	int i = 0;

	pthread_mutex_init(&mutex, NULL);
	while(i < 4)
	{
		if (pthread_create(th + i, NULL, &routine, NULL)!=0)
		{
			perror("Failed to create thread\n");
			return 1;
		}
		printf("thread %d is started\n", i);
		i++;
	}
	i = 0;
	while(i < 4)
	{
		if (pthread_join(th[i], NULL)!=0)
			return 2;

		i++;
	}

	pthread_mutex_destroy(&mutex);
	printf("mails %d\n", mails);
	return 0;
}
