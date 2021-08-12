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
	t_philo	philo;
//чекнуть сабджект на возвращаемое значение и сообщение для обработки ошибок
	check_args(argc);
	init(&philo, argv);	//заполнили структуру с данными

}
