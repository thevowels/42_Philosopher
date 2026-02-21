/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:35:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:31:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(int argc, char **argv, t_table *table)
{
	ft_check_args(argv);
	table->n_philo = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->f_philos = 0;
	table->stop = 0;
	table->ready = 0;
	if (argc == 5)
		table->max_meals = -1;
	else
		table->max_meals = ft_atoi(argv[5]);
	ft_check_durations(table);
	pthread_mutex_init(&(table->stop_mutex), NULL);
	pthread_mutex_init(&(table->print_mutex), NULL);
}


void	init_philos(t_table *table)
{
	ft_create_forks(table);
	ft_create_philos(table);
}