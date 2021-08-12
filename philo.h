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

typedef struct s_philo
{
	int		index;
	long 	last_meal;
}				t_philo;

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
	t_philo 		*philos;
}				t_data;


void	check_args(int argc);

void	init(t_data *p_s, char *argv[]);

void 	*create_arr(t_data *philo, int size);

void 	check_arr_creation(void *arr1, void *arr2);

int 	create_philos(t_data *philo);

int		create_forks(t_data *philo);

void 	exec(t_data *philo);

#endif
