/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:49:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/22 23:52:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *observer_routine(void *ptr)
{
	t_philo *philos;

	philos = (t_philo *)philos;

	while(1)
	{

	}
}

void *philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	
	if(philo->id %2)
	
}