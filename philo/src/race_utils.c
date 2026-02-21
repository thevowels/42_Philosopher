/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:24:14 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:15:19 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_stop(t_table *table)
{
	pthread_mutex_lock(&(table->stop_mutex));
	table->stop = 1;
	pthread_mutex_unlock(&(table->stop_mutex));
}

// int	ft_is_stop(t_table *table)
// {
// 	int	i;

// 	pthread_mutex_lock(&(table->stop_mutex));
// 	i = table->stop;
// 	pthread_mutex_unlock(&(table->stop_mutex));
// 	return (i);
// }

int	ft_print_action(t_philo *philo, char *str)
{
	long	t;

	pthread_mutex_lock(&(philo->table->print_mutex));
	if(ft_is_stop(philo->table))
	{
		pthread_mutex_unlock(&(philo->table->print_mutex));
			return (0);
	}
	t = ft_time_ms() - philo->table->start_ms;
	printf("%ld %d %s\n", t, philo->idx + 1, str);
	pthread_mutex_unlock(&(philo->table->print_mutex));
	return (1);
}