/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:40:04 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:40:14 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_philo *philo)
{
	if(philo->left_fork_mutex < philo->right_fork_mutex)
	{
		pthread_mutex_lock(philo->right_fork_mutex);
		pthread_mutex_lock(philo->left_fork_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork_mutex);
		pthread_mutex_lock(philo->right_fork_mutex);

	}
	ft_print_action(philo, " has taken a fork");
	ft_print_action(philo, " has taken a fork");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = ft_time_ms();
	philo->n_meals +=1 ;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_sleep_ms(philo->table->t_eat);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);


}

void enjoy_meal(t_philo *philo)
{
	ft_print_action(philo, " is sleeping");
	ft_sleep_ms(philo->table->t_sleep);
	ft_print_action(philo, " is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_wait_until_ready(philo);
	if((philo->idx + 1) % 2 == 0)
		ft_sleep_ms(philo->table->t_sleep * 0.5);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
	while(!ft_is_stop(philo->table))
	{
		enjoy_meal(philo);
	}
	return (NULL);
}

void	*ft_host_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (!ft_is_stop(table))
	{
		i = 0;
		while (i < table->n_philo)
		{
			if (!ft_is_alive(&table->philos[i]))
				return (ft_print_die(&(table->philos[i])), NULL);
		}
		if (table->max_meals > 0 && ft_finished_philos(table) == table->n_philo)
			return (ft_set_stop(table), NULL);
		usleep(300);
	}
	return (NULL);
}

void	ft_launch_dining(t_table *table)
{
	pthread_t *philo_threads;
	pthread_t host;

	philo_threads = NULL;
	pthread_mutex_init(&table->ready_mutex, NULL);
	ft_create_philo_threads(table, &philo_threads);
	if (pthread_create(&host, NULL, ft_host_routine, (void *)table))
	{
		free(philo_threads);
		pthread_mutex_destroy(&table->ready_mutex);
		ft_clean_exit(table, FORKS_PHILOS);
	}
	pthread_mutex_lock(&table->ready_mutex);
	table->ready = 1;
	pthread_mutex_unlock(&table->ready_mutex);
	// printf("Philo threads : %p\n" , philo_threads);
	ft_thread_join(&host, philo_threads, table->n_philo);
	pthread_mutex_destroy(&table->ready_mutex);
	free(philo_threads);
}