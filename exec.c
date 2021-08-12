#include <unistd.h>
#include "philo.h"


//int check_death(t_data *data)
//{
//
//}

void *philo_routine(void *philo)
{
	t_philo *aristo;

	aristo = (t_philo *) philo;
	if ()
	return (NULL);
}



int	start_threads(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->phil_n)
	{
		if (pthread_create(&data->pthreads[i], NULL, &philo_routine, &philos[i]) != 0) {
			perror("Failed to create thread\n");
			return (i);
		}
		usleep(50);
		i++;
	}
	i = 0;
	while (i < data->phil_n)
	{
		if (pthread_join(data->pthreads[i], NULL) != 0)
			return 2;
	}
	return (0);
}


int init_fork_mutes(t_data *data)
{
	int	i;
	int	res;

	i = 0;
	while (i < data->phil_n)
	{
		res = pthread_mutex_init(&data->forks[i], NULL);
		if (res)
		{
			printf("mutex error!\n");
			exit (2);
		}
		i++;
	}
	return (i);
}

void	exec(t_philo *philos, t_data *data)
{
	init_fork_mutes(data);
	start_threads(philos, data);
}