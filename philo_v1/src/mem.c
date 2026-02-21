/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:29:18 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:12:52 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks_mutex = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks_mutex)
	{
		ft_clean_exit(table, NONE);
	}
	while (i < table->n_philo)
		pthread_mutex_init(&(table->forks_mutex[i++]), NULL);
}

void ft_assign_forks(t_table *table, t_philo *philo)
{
	philo->right_fork_mutex = &table->forks_mutex[philo->idx];
	if(philo->idx == 0)
		philo->left_fork_mutex = &table->forks_mutex[table->n_philo -1];
	else
		philo->left_fork_mutex = &table->forks_mutex[philo->idx - 1];
}
void	ft_create_philos(t_table *table)
{
	int	i;
	t_philo *philo;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philos)
	{
		ft_clean_exit(table, FORKS);
	}
	while(i < table->n_philo)
	{
		philo = &table->philos[i];
		philo->idx = i;
		philo->table = table;
		philo->n_meals = 0;
		// Todo init with -1 later. 
		// Edge case of odd number of philosophers.
		philo->last_meal = ft_time_ms();
		pthread_mutex_init(&philo->meal_mutex, NULL);
		ft_assign_forks(table,philo);
		philo->has_forks = 0;
		i++;
	}
}

// void ft_free_table(t_table *table)
// {
	
// }