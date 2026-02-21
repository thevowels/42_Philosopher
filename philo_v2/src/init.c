/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:10:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 18:23:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_table *table, t_philo *philos, pthread_mutex_t *forks,
		char **argv)
{
	int i;

	i = 0;
	while(i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].times.t_die = ft_atoi(argv[2]);
		philos[i].times.t_eat = ft_atoi(argv[3]);
		philos[i].times.t_sleep= ft_atoi(argv[4]);
		philos[i].times.last_meal = 
	}
}

void	init_forks(t_table *table, pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_table(t_table *table, t_philo *philos, pthread_mutex_t *forks)
{
	table->forks = forks;
	table->philos = philos;
	pthread_mutex_init(&table->write_mutex, NULL);
	pthread_mutex_init(&table->meal_mutex, NULL);
}