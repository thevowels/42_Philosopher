/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 02:29:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_cleanup(t_table *table, int i)
{
	ft_destroy_philo_mutexes(table, i);
	ft_destroy_forks(table, table->n_philos);
	ft_destroy_table_mutexes(table);
	ft_error_exit("Error while creating philo alive mutex.\n");
}

void ft_destroy_philo_mutexes(t_table *table, int count)
{
	int i; 

	i = 0;
	while(i < count)
	{
		pthread_mutex_destroy(&table->philos[i].philo_alive_mutex);
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
	}
}

void	ft_destroy_table_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->ready_mutex);
	pthread_mutex_destroy(&table->alive_mutex);
	pthread_mutex_destroy(&table->eaten_philos_mutex);
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