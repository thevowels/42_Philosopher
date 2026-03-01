/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:40:24 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/23 23:12:29 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_message("[gettimeofday ERROR]\n", 1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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

void	ft_parse_table(t_table *table, char **argv)
{
	table->n_philos = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->n_meals = -1;
	if (argv[5])
		table->n_meals = ft_atoi(argv[5]);
}

void	ft_error_exit(char *str)
{
	if (write(2, str, ft_strlen(str)) == -1)
		ft_error_exit("Error while printing error\n");
	exit(EXIT_FAILURE);
}