/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:46:10 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:23:01 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread_create(t_table *table, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (pthread_create(&th[i], NULL, &routine, (void *)&(table->philos[i])))
		{
			pthread_mutex_destroy(&table->ready_mutex);
			ft_clean_exit(table, FORKS_PHILOS);
		}
		i++;
	}
	// i = 0;
	// while(i < table->n_philo)
	// {
	// 	pthread_detach(th[i++]);
	// }
}
void	ft_thread_join(pthread_t *host, pthread_t *philos, int philo_count)
{
	int i;
	i = 0;
	while(i < philo_count)
	{
		// printf("%p\n", &philos[i]);
		pthread_join(philos[i++], NULL);
	}
	pthread_join(*host, NULL);
}

void	ft_create_philo_threads(t_table *table, pthread_t **philo_threads)
{
	*philo_threads = malloc(sizeof(pthread_t) * table->n_philo);
	// printf("Create philo threads %p\n", *philo_threads);
	if (!*philo_threads)
		ft_clean_exit(table, FORKS_PHILOS);
	table->start_ms = ft_time_ms();
	ft_thread_create(table, *philo_threads);
}
