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

typedef struct s_philo
{
	int phil_n;
	int die_time;
	int eat_time;
	int sleep_time;
	int must_eat;
}				t_philo;

void	check_args(int argc);

void	init(t_philo *philo_s, char *argv[]);

#endif
