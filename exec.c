#include <unistd.h>
#include "philo.h"

void	print_status(int index, char *status, t_data *data)
{
	pthread_mutex_lock(&data->print_m);
	printf("%lu %d %s\n", getTime(), index, status);
	pthread_mutex_unlock(&data->print_m);
}

int check_death(t_philo *phil, t_data *data)
{
	int	i;
	size_t t;

	while(data->death == -1)
	{
		i = 0;
		while (i < data->phil_n)
		{
			t = getTime();
//			printf("here\n");
//			printf("t = %lu\nlast.meal = %lu\n", t, phil[i].last_meal);
//			printf("diff = %lu\n", t - phil[i].last_meal);
			if (getTime() - phil[i].last_meal > (size_t) data->die_time)
			{
				data->death = i;
				break;
			}
			i++;
		}
	}
	return i;
}

void *philo_routine(void *philo)
{
	t_philo *phil;
	t_data 	*data;

	phil = (t_philo *) philo;
	phil->last_meal = getTime();
	data = phil->data;
	while(1)
	{
		pthread_mutex_lock(phil->fork_one);
		print_status(phil->index + 1, TAKE_FORK, data);
		pthread_mutex_lock(phil->fork_two);
		print_status(phil->index + 1, TAKE_FORK, data);
		print_status(phil->index + 1, EAT, data);
		phil->last_meal = getTime();
		usleep(data->eat_time * 1000);
		pthread_mutex_unlock(phil->fork_one);
		pthread_mutex_unlock(phil->fork_two);
		print_status(phil->index + 1, SLEEP, data);
		usleep(data->sleep_time * 1000);
		print_status(phil->index + 1, THINK, data);
	}
	return (NULL);
}



int	start_threads(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->phil_n)
	{
		philos[i].last_meal = getTime();
		if (pthread_create(&data->pthreads[i], NULL, &philo_routine, &philos[i]) != 0) {
			perror("Failed to create thread\n");
			return (i);
		}
		usleep(100);
		i++;
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
	check_death(philos, data);
	print_status(data->death + 1, DIED, data);
	while (data->phil_n)
	{
		pthread_detach(data->pthreads[data->phil_n - 1]);
		data->phil_n--;
		pthread_mutex_destroy(&data->forks[data->phil_n - 1]);
	}
	exit(0);
}
