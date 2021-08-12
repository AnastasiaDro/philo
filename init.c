/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:30:00 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/10 18:30:35 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo_s, char *argv[])
{
	philo_s->phil_n = ft_atoi(argv[1]);
	philo_s->die_time = ft_atoi(argv[2]);
	philo_s->eat_time = ft_atoi(argv[3]);
	philo_s->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		philo_s->must_eat = ft_atoi(argv[5]);
	else
		philo_s->must_eat = -1;
}