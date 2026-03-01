/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 06:25:52 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/02 06:30:31 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// from table_utils
void	ft_wait_until_ready(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->ready_mutex);
		pthread_mutex_lock(&table->alive_mutex);
		if (table->is_ready)
		{
			pthread_mutex_unlock(&table->ready_mutex);
			pthread_mutex_unlock(&table->alive_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->ready_mutex);
		pthread_mutex_unlock(&table->alive_mutex);
		usleep(100);
	}
}

// from utils
void	ft_error_exit(char *str)
{
	if (write(2, str, ft_strlen(str)) == -1)
		ft_error_exit("Error while printing error\n");
	exit(EXIT_FAILURE);
}

// from actions.c
void	lock_forks(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
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
