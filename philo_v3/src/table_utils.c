/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:33:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 02:49:04 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_until_ready(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->ready_mutex);
		pthread_mutex_lock(&table->alive_mutex);
		if (table->is_ready || !table->is_alive)
		{
			pthread_mutex_unlock(&table->ready_mutex);
			pthread_mutex_unlock(&table->alive_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->ready_mutex);
		pthread_mutex_unlock(&table->alive_mutex);
		usleep(100);
	}
}

void	ft_set_alive(t_table *table, int i)
{
	pthread_mutex_lock(&table->alive_mutex);
	table->is_alive = i;
	pthread_mutex_unlock(&table->alive_mutex);
}

int	ft_get_alive(t_table *table)
{
	int	is_alive;

	pthread_mutex_lock(&table->alive_mutex);
	is_alive = table->is_alive;
	pthread_mutex_unlock(&table->alive_mutex);
	return (is_alive);
}

void	ft_add_eaten_philos(t_table *table)
{
	pthread_mutex_lock(&table->eaten_philos_mutex);
	table->eaten_philos += 1;
	pthread_mutex_unlock(&table->eaten_philos_mutex);
}

int	ft_get_eaten_philos(t_table *table)
{
	int eaten_philos;
	pthread_mutex_lock(&table->eaten_philos_mutex);
	eaten_philos = table->eaten_philos;
	pthread_mutex_unlock(&table->eaten_philos_mutex);
	return (eaten_philos);
}