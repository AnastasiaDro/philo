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

int	check_data(t_data *p_s)
{
	if (p_s->phil_n == -1 || p_s->die_time == -1 || p_s->eat_time == -1 || p_s->sleep_time == -1)
	{
		printf("Invalid argument!\n");
		return (1);
	}
	return (0);
}

int	init_mutes(t_data *p_s)
{
	int	res1;
	int res2;

	res1 = pthread_mutex_init(&p_s->death_m, NULL);
	res2 = pthread_mutex_init(&p_s->print_m, NULL);
	if (res1 || res2)
	{
		exit (1); //очистить все массивы!!!
	}
	return (0);
}

void	init(t_data *p_s, char *argv[])
{
	p_s->phil_n = ft_atoi(argv[1]);
	p_s->die_time = ft_atoi(argv[2]);
	p_s->eat_time = ft_atoi(argv[3]);
	p_s->sleep_time = ft_atoi(argv[4]);
	init_mutes(p_s);
	p_s->philos	= malloc(p_s->phil_n * sizeof (t_philo));
	if (check_data(p_s))
		exit(1);
	if(!p_s->philos)
		exit(2);
	p_s->death = 0;
	if (argv[5])
		p_s->meals_num = ft_atoi(argv[5]);
	else
		p_s->meals_num = -1;


}

