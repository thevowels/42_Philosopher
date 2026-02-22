/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:49:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/23 06:17:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *observer_routine(void *ptr)
{
	t_philo *philos;

	philos = (t_philo *)philos;

}

void *philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	ft_wait_to_start(philo->table);
	if(philo->id % 2 == 0)
		ft_sleep(philo->table->t_die * 0.2);
	pthread_mutex_lock()

}