/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:33:36 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 03:22:23 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int argc, char **argv)
// {
// 	t_table			table;
// 	t_philo			philos[PHILO_MAX_COUNT];
// 	pthread_mutex_t	forks[PHILO_MAX_COUNT];

// 	table.philos = philos;
// 	table.forks = forks;
// 	ft_validate(argc, argv);
// 	ft_parse(&table, argv);
// 	init_table(&table);
// 	init_forks(&table);
// 	init_philos(&table);
// 	table.start_time = ft_time_ms();
// 	ft_start_dining(&table);
// 	philo_cleanup(&table,table.n_philos);

// }
void	ft_test(t_table *table)
{
	table->is_ready = 0;
	table->is_alive = 1;
	table->eaten_philos = 0;
	table->n_philos = 4;
	table->t_die = 410;
	table->t_eat = 200;
	table->t_sleep = 200;
	table->max_meals =2;
}


// for the testing
int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[PHILO_MAX_COUNT];
	pthread_mutex_t	forks[PHILO_MAX_COUNT];

	(void)argc;
	(void)argv;
	table.philos = philos;
	table.forks = forks;
	// ft_validate(argc, argv);
	// ft_parse(&table, argv);
	ft_test(&table);
	init_table(&table);
	init_forks(&table);
	init_philos(&table);
	table.start_time = ft_time_ms();
	ft_start_dining(&table);
	printf("Before cleanup\n");
	philo_cleanup(&table,table.n_philos);

}
