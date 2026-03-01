/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:45:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/02 06:27:58 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

size_t	ft_time_ms(void)
{
	struct timeval	time;
	size_t			result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	ft_sleep_ms(size_t ms)
{
	size_t	start_time;

	start_time = ft_time_ms();
	while (ft_time_ms() < start_time + ms)
		usleep(100);
}

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	long	value;

	value = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strlen(str) > 10)
		ft_error_exit("Parameter larger than MAX INT\n");
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	if (value > INT_MAX)
		ft_error_exit("Parameter larger than MAX INT\n");
	return (value);
}
