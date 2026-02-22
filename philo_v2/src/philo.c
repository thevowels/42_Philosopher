/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:32:14 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/23 06:06:46 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[PHILO_MAX_COUNT];
	pthread_mutex_t	forks[PHILO_MAX_COUNT];

	ft_validate(argc, argv);
	ft_parse_table(&table, argv);
	table.philos = philos;
	table.forks = forks;
	init_table(&table);
	// Nothing to clean until this line
	init_forks(&table);
	// Mem => forks, write_mutex, meal_mutex;
	init_philos(&table);
	// Mem => forks, write_mutex, meal_mutex;
	init_threads(&table);
}
