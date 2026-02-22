/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:03:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/23 06:09:49 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_table *table)
{
	table->ready = 0;
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
		ft_error_exit("Error whiel creating write mutex\n");
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write_mutex);
		ft_error_exit("Erorr while creating meal mutex\n");
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
			ft_destroy_table(table);
			ft_error_exit("Error while fork mutexex.\n");
		}
		i++;
	}
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].born_time = get_current_time();
		table->philos[i].last_meal = table->philos[i].born_time;
		table->philos[i].meals_eaten = 0;
		table->philos[i].mutexes.right_fork = &table->forks[i];
		if (i == 0)
			table->philos[i].mutexes.left_fork = &table->forks[table->n_philos
				- 1];
		else
			table->philos[i].mutexes.left_fork = &table->forks[i - 1];
		table->philos[i].mutexes.write_mutex = &table->write_mutex;
		table->philos[i].mutexes.meal_mutex = &table->meal_mutex;
		table->philos[i].table = table;
		i++;
	}
}
void	init_threads(t_table *table)
{
	pthread_t	observer_id;
	int			i;

	i = 0;
	if(pthread_create(&observer_id, NULL, NULL,  ))

}
