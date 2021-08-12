#include "philo.h"


void 	*create_arr(t_philo *philo, int size)
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

//int create_philos(t_philo *philo)
//{
//	philo->philos = malloc(philo->phil_n * sizeof (pthread_t));
//	if (!philo->philos)
//		return (0);
//	return (1);
//}
//
//int	create_forks(t_philo *philo)
//{
//	philo->forks = malloc(philo->phil_n * sizeof (pthread_mutex_t));
//	if (!philo->forks)
//		return (0);
//	return (1);
//}
