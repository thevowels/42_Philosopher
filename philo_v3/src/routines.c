/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:49:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 03:02:07 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_wait_until_ready(philo->table);
	if (philo->id % 2 == 0)
		ft_sleep_ms(2);
	// pthread_mutex_lock(&philo->meal_mutex);
	// philo->last_meal = ft_time_ms();
	// pthread_mutex_unlock(&philo->meal_mutex);
	while (ft_get_alive(philo->table))
	{
		ft_eat(philo);
		if (philo->meals_eaten == philo->table->max_meals)
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_is_philo_alive(t_philo *philo)
{
	size_t	last_meal;
	size_t	current_time;

	current_time = ft_time_ms();
	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mutex);
	if ((current_time - last_meal) >= philo->table->t_die)
		return (0);
	return (1);
}

void	*monitor_routine(void *ptr)
{
	t_table	*table;
	int		i;

	table = (t_table *)ptr;
	while (ft_get_alive(table))
	{
		i = 0;
		while (i < table->n_philos)
		{
			if (ft_is_philo_alive(&table->philos[i]))
			{
				ft_set_alive(table, 0);
				ft_print_die(&table->philos[i]);
				return (NULL);
			}
			i++;
		}
		if (ft_get_eaten_philos(table) == table->n_philos)
		{
			ft_set_alive(table, 0);
		}
		usleep(300);
	}
	return (NULL);
}

int	start_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i].tid, NULL, &philo_routine,
				&table->philos[i]) != 0)
		{
			ft_set_alive(table,0);
			break;
		}
		i++;
	}
	return (i);
}


void	ft_start_dining(t_table *table)
{
	pthread_t monitor;
	int		threads;
	int		i;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitor_routine, (void *)table) != 0)
		philo_cleanup(table, table->n_philos);
	threads = 	start_philo_threads(table);
	while(i < threads)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}