
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <printf.h>

void *roll_dice()
{
	int val = (rand() % 6) + 1;
	//получим утечку памяти
	int* result = malloc(sizeof(int));
	*result = val;
	//printf("value = %d\n", val);
	printf("%p\n", result);
	return ((void *) result);
}

int main()
{
	int *res;
	srand(time(NULL));
	pthread_t th;
	res = malloc(sizeof(int));
	if(pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return 1;
	if(pthread_join(th, (void **)&res) !=0)
		return 2;
	printf("Main res = %p\n", res);
	printf("result = %d\n", *res);
	free(res);
	return(0);
}