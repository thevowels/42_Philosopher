/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:12 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/02 06:21:12 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_table *table)
{
	if (pthread_mutex_init(&table->ready_mutex, NULL) != 0)
		ft_error_exit("Error while initializing ready mutex.\n");
	if (pthread_mutex_init(&table->alive_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->ready_mutex);
		ft_error_exit("Error while initializing alive mutex.\n");
	}
	if (pthread_mutex_init(&table->eaten_philos_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->ready_mutex);
		pthread_mutex_destroy(&table->alive_mutex);
		ft_error_exit("Error while initializing eaten_philos mutex.\n");
	}
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->ready_mutex);
		pthread_mutex_destroy(&table->alive_mutex);
		pthread_mutex_destroy(&table->eaten_philos_mutex);
		ft_error_exit("Error while initializing write mutex.\n");
	}
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			ft_destroy_forks(table, i);
			ft_destroy_table_mutexes(table);
			ft_error_exit("Error while fork mutexex.\n");
		}
		i++;
	}
}

// check mutex_init later if enough time.

static void	set_fork(t_philo *philo, int i)
{
	philo->left_fork = &philo->table->forks[i];
	if (i == 0)
		philo->right_fork = &philo->table->forks[philo->table->n_philos - 1];
	else
		philo->right_fork = &philo->table->forks[i - 1];
}

void	init_philos(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->n_philos)
	{
		philo = &table->philos[i];
		philo->table = table;
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->philo_alive = 1;
		set_fork(philo, i);
		if (pthread_mutex_init(&philo->philo_alive_mutex, NULL) != 0)
			philo_cleanup(table, i);
		if (pthread_mutex_init(&philo->meal_mutex, NULL) != 0)
		{
			pthread_mutex_destroy(&philo->philo_alive_mutex);
			philo_cleanup(table, i);
		}
		philo->last_meal = ft_time_ms();
		i++;
	}
}
