/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:20:49 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/22 23:31:02 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_table(t_table *table)
{
	pthread_mutex_destroy(&table->meal_mutex);
	pthread_mutex_destroy(&table->write_mutex);
}

void	ft_destroy_forks(t_table *table, int last_fork)
{
	int i = 0;
	while(i < last_fork)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}