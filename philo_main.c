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
	t_data		philo;
	check_args(argc);
	init(&philo, argv);
	philo.pthreads = create_arr(&philo, sizeof (pthread_t));
	philo.forks = create_arr(&philo, sizeof(pthread_mutex_t));
	check_arr_creation(philo.pthreads, philo.forks);
	exec(&philo);
}
