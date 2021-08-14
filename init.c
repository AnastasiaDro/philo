/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:30:00 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/10 18:30:35 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

int	check_data(t_data *p_s)
{
	if (p_s->phil_n == -1 || p_s->die_time == -1 || p_s->eat_time == -1 || p_s->sleep_time == -1)
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

int	init_mutes(t_data *data)
{
	int	res1;
	int res2;
	int i;

	i = 0;
	res1 = pthread_mutex_init(&data->death_m, NULL);
	res2 = pthread_mutex_init(&data->print_m, NULL);
	if (res1 || res2)
		exit (1); //очистить все массивы!!!
	while (i < data->phil_n)
	{
		res1 = pthread_mutex_init(&data->forks[i], NULL);
		if (res1)
			exit (1);
		i++;
	}
	return (0);
}

pthread_mutex_t *get_second(int i, t_data *data)
{
	pthread_mutex_t *second_fork;

	if (i == 0)
	{
		second_fork = &(data->forks[data->phil_n - 1]);
		printf("1  fork two = %d\n", data->phil_n - 1);
	}
	else
	{
		second_fork = &(data->forks[i - 1]);
		printf("1  fork two = %d\n", i - 1);
	}


	return (second_fork);
}


size_t getTime()
{
	size_t milisec;
	struct timeval t;

	gettimeofday(&t, NULL);
	milisec = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (milisec);
}


t_philo *init_philos(t_data *data)
{
	int				i;
	t_philo 		*philos;

	i = 0;
	philos = malloc(data->phil_n * sizeof (t_philo));
	if (!philos)
		return (NULL);
	while (i < (data->phil_n))
	{
		philos[i].index = i;
		philos[i].data = data;
		philos[i].last_meal = getTime();
		if ((i + 1) % 2)
		{
			philos[i].fork_one = &(data->forks[i]);
			philos[i].fork_two = get_second(i , data);
		}
		else
		{
			philos[i].fork_one = &(data->forks[i - 1]);
			philos[i].fork_two = &(data->forks[i]);
		}
		i++;
	}
	return (philos);
}

void	init_data(t_data *data, char *argv[])
{
	data->phil_n = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);

	if (check_data(data))
		exit(1);
	data->death = -1;
	if (argv[5])
		data->meals_num = ft_atoi(argv[5]);
	else
		data->meals_num = -1;
	data->pthreads = (pthread_t *)create_arr(data, sizeof (pthread_t));
	data->forks = (pthread_mutex_t *)create_arr(data, sizeof(pthread_mutex_t));
	init_mutes(data);
}
