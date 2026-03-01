/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:02:20 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 18:01:40 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <errno.h>
#include <limits.h>
#include <sys/time.h>

void	ft_wait_until_ready(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->ready_mutex);
		if (philo->table->ready)
		{
			pthread_mutex_unlock(&philo->table->ready_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->ready_mutex);
		usleep(100);
	}
}

long	ft_time_ms(void)
{
	struct timeval	tv;
	long			result;

	gettimeofday(&tv, 0);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (result);
}

void	ft_sleep_ms(long ms)
{
	long	start;

	start = ft_time_ms();
	while (ft_time_ms() < start + ms)
		usleep(100);
}

int	ft_atoi(char *str)
{
	long	value;

	value = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strlen(str) > 10)
	{
		ft_putstr_fd("Parameter larger than MAX INT\n", 2);
		exit(EXIT_FAILURE);
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	if (value > INT_MAX)
	{
		ft_putstr_fd("Parameter larger than MAX INT\n", 2);
		exit(EXIT_FAILURE);
	}
	return (value);
}

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
