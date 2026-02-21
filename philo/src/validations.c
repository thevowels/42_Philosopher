/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:58:35 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:14:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	ft_check_args(char **argv)
{
	char	*str;
	int		digits_only;

	digits_only = 1;
	argv += 1;
	while (*argv)
	{
		str = *argv;
		while (*str)
		{
			if (!ft_isdigit(*str))
				digits_only = 0;
			str++;
		}
		argv++;
	}
	if (!digits_only)
	{
		ft_putstr_fd("Numbers only on arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_durations(t_table *table)
{
	int flag;

	flag = 0;
	if (table->n_philo <= 0 || table->n_philo > PHILO_MAX_COUNT)
		flag = 1;
	if (table->t_die < 60 || table->t_eat < 60 || table->t_sleep < 60)
		flag = 1;
	if(flag)
	{
		ft_putstr_fd("Invalid argument values\n", 2);
		exit(EXIT_FAILURE);
	}
	if(table->max_meals == 0)
		exit(EXIT_SUCCESS);
}
