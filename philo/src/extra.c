/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 06:25:52 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/04/06 18:59:06 by aphyo-ht         ###   ########.fr       */
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
int	lock_forks(t_philo *philo)
{
	if (philo->left_fork <= philo->right_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken a fork");
		if (philo->left_fork == philo->right_fork)
		{
			ft_sleep_ms(philo->table->t_die + 42);
			pthread_mutex_unlock(philo->right_fork);
			return (-1);
		}
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken a fork");
		return (0);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_action(philo, "has taken an fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_action(philo, "has taken an fork");
		return (0);
	}
}
