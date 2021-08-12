#include <unistd.h>
#include "philo.h"

void	print_status(size_t time, int index, char *status, t_data *data)
{
	pthread_mutex_lock(&data->print_m);
	printf("%zul %d %s\n", getTime(), index, TAKE_FORK);
	pthread_mutex_unlock(&data->print_m);
}

int check_death(t_philo *phil, t_data *data)
{
	printf("index = %d\n", phil->index);
	if (getTime() - phil->last_meal > data->die_time)
	{
		pthread_mutex_lock(&data->death_m);
		data->death = phil->index;
		pthread_mutex_unlock(&data->death_m);
		return (1);
	}
	return (0);
}


void *philo_routine(void *philo)
{
	t_philo *phil;
	t_data 	*data;

	phil = (t_philo *) philo;
	data = phil->data;
	while(1)
	{
		if (check_death(phil, data))
			return (philo);
		pthread_mutex_lock(&phil->fork_one);
	//	printf("%zul %d %s\n", getTime(), phil->index, TAKE_FORK);
		print_status(getTime(), phil->index + 1, TAKE_FORK, data);
		pthread_mutex_lock(&phil->fork_two);
		print_status(getTime(), phil->index + 1, TAKE_FORK, data);
		printf("%zul %d %s\n", getTime(), phil->index, EAT);
		usleep(phil->data->eat_time);
		pthread_mutex_unlock(&phil->fork_one);
		pthread_mutex_unlock(&phil->fork_two);
		printf("%zul %d %s\n", getTime(), phil->index, SLEEP);
		usleep(phil->data->sleep_time);
		if (check_death(phil, data))
			return (philo);
		printf("%zul %d %s\n", getTime(), phil->index, THINK);
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
	while (1)
	{
		if (data->death != -1)
		{
			printf("%zul %d %s\n", getTime(), data->death + 1, DIED);
			while (data->phil_n)
			{
				pthread_detach(data->pthreads[data->phil_n - 1]);
				data->phil_n--;
				pthread_mutex_destroy(&data->forks[data->phil_n - 1]);
			}
			exit(0);
		}
	}
}
