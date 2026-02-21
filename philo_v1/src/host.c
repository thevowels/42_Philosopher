/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:06:40 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/20 22:16:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_finished_philos(t_table *table)
{
	int finished_philosophers;
	pthread_mutex_lock(&table->finish_mutex);
	finished_philosophers = table->f_philos;
	pthread_mutex_unlock(&table->finish_mutex);
	return finished_philosophers;
}

void ft_print_die(t_philo *philo)
{
	long time;
	pthread_mutex_lock(&(philo->table->print_mutex));
	ft_set_stop(philo->table);
	time = ft_time_ms() - (philo->table->start_ms);
	printf("%ld %d died \n", time, philo->idx + 1);
	pthread_mutex_unlock(&(philo->table->print_mutex));

}

int ft_is_alive(t_philo *philo)
{
	long last_meal;
	long now;
	
	now = ft_time_ms();
	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mutex);
	if(now - last_meal >= philo->table->t_die)
		return (0);
	return (1);
}

void ft_stop_table(t_table *table)
{
	pthread_mutex_lock(&table->stop_mutex);
	table->stop = 1;
	pthread_mutex_unlock(&table->stop_mutex);
}

int  ft_is_stop(t_table *table)
{
	int stop;

	pthread_mutex_lock(&table->stop_mutex);
	stop = table->stop;
	pthread_mutex_unlock(&table->stop_mutex);
	return (stop);
}