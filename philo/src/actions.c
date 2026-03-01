/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:45:00 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 05:35:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_forks(t_philo *philo)
{	if(philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork");
		ft_set_alive(philo->table, 0);
		pthread_mutex_unlock(philo->left_fork);
		exit(EXIT_SUCCESS);
	}
	else if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has take a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has take a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has take a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has take a fork");
	}
}

void	ft_eat(t_philo *philo)
{
	lock_forks(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = ft_time_ms();
	ft_print_action(philo, "is eating");
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_sleep_ms(philo->table->t_eat);
	if (philo->table->max_meals != -1
		&& philo->meals_eaten == philo->table->max_meals)
		ft_add_eaten_philos(philo->table);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_action(philo, "is sleeping");
	ft_sleep_ms(philo->table->t_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print_action(philo, "is thinking");
}

void	ft_print_action(t_philo *philo, char *str)
{
	size_t	passed_time;

	pthread_mutex_lock(&philo->table->write_mutex);
	passed_time = ft_time_ms() - philo->table->start_time;
	if (!ft_get_alive(philo->table))
	{
		pthread_mutex_unlock(&philo->table->write_mutex);
		return ;
	}
	printf("%ld %d %s\n", passed_time, philo->id, str);
	pthread_mutex_unlock(&philo->table->write_mutex);
}
void	ft_print_die(t_philo *philo)
{
	size_t time_ms;
	time_ms = ft_time_ms() - (philo->table->start_time);
	pthread_mutex_lock(&philo->table->write_mutex);
	printf("%ld %d died\n",time_ms, philo->id);
	pthread_mutex_unlock(&philo->table->write_mutex);
}