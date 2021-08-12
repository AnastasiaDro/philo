/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:20:34 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/10 18:31:06 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include <pthread.h>
#define TAKE_FORK "has taken a fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DIED "died"

typedef struct s_data
{
	int				phil_n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meals_num;
	int 			death;
	pthread_t		*pthreads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_m;
	pthread_mutex_t print_m;
}				t_data;

typedef struct s_philo
{
	int				index;
	size_t			last_meal;
	pthread_mutex_t fork_one;
	pthread_mutex_t fork_two;
	t_data 			*data;
}				t_philo;


size_t  getTime();

void	check_args(int argc);

void	init_data(t_data *p_s, char *argv[]);

void 	*create_arr(t_data *data, int size);

void 	check_arr_creation(void *arr1, void *arr2);

t_philo *init_philos(t_data *data);

int	start_threads(t_philo *philos, t_data *data);

int 	create_philos(t_data *philo);

int		create_forks(t_data *philo);

void	exec(t_philo *philos, t_data *data);

#endif
