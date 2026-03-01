/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:33:36 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/02 06:22:24 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[PHILO_MAX_COUNT];
	pthread_mutex_t	forks[PHILO_MAX_COUNT];

	table.philos = philos;
	table.forks = forks;
	ft_validate(argc, argv);
	ft_parse(&table, argv);
	init_table(&table);
	init_forks(&table);
	init_philos(&table);
	ft_start_dining(&table);
	clean_exit(&table);
}
