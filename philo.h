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
	int				phil_n;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				death;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}				t_philo;

void	check_args(int argc);

void	init(t_philo *p_s, char *argv[]);

void 	*create_arr(t_philo *philo, int size);

void 	check_arr_creation(void *arr1, void *arr2);

int 	create_philos(t_philo *philo);

int		create_forks(t_philo *philo);

#endif
