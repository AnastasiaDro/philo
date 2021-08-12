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

int	check_data(t_philo *p_s)
{
	if (p_s->phil_n == -1 || p_s->die_time == -1 || p_s->eat_time == -1 || p_s->sleep_time == -1)
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}


void	init(t_philo *p_s, char *argv[])
{
	p_s->phil_n = ft_atoi(argv[1]);
	p_s->die_time = ft_atoi(argv[2]);
	p_s->eat_time = ft_atoi(argv[3]);
	p_s->sleep_time = ft_atoi(argv[4]);
	if (check_data(p_s))
		exit(1);
	p_s->death = 0;
	if (argv[5])
		p_s->must_eat = ft_atoi(argv[5]);
	else
		p_s->must_eat = -1;
}

