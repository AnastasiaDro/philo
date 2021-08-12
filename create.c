#include "philo.h"


void 	*create_arr(t_data *philo, int size)
{
	void *arr;

	arr = malloc(philo->phil_n * size);
	return (arr);
}

void 	check_arr_creation(void *arr1, void *arr2)
{
	if (!arr1 || !arr2)
	{
		free(arr1);
		free(arr2);
		exit(1);
	}
}
