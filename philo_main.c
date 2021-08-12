/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:13:55 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/10 18:30:49 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data		data;
	t_philo 	*philos;

	check_args(argc);
	init_data(&data, argv);
	data.pthreads = create_arr(&data, sizeof (pthread_t));
	data.forks = create_arr(&data, sizeof(pthread_mutex_t));
	philos = init_philos(&data);
	check_arr_creation(data.pthreads, data.forks);
	exec(philos, &data);
}
