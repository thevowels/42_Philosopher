/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:37:34 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 02:57:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_check_args(char **argv)
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
		ft_error_exit("Non numerical characters in arguments.\n");
}

void	ft_validate(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_error_exit("Invalid number of arguments\n");
	ft_check_args(argv);
	if (ft_atoi(argv[1]) > PHILO_MAX_COUNT)
		ft_error_exit("Philosophers number must be less than 200\n");
	if (ft_atoi(argv[2]) * ft_atoi(argv[3]) * ft_atoi(argv[4]) == 0)
		ft_error_exit("Durations cannot be zero\n");
}
// initialize the values and parse the requirements from argument.
void	ft_parse(t_table *table, char **argv)
{
	table->is_ready = 0;
	table->is_alive = 1;
	table->eaten_philos = 0;
	table->n_philos = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	table->max_meals = -1;
	if (argv[5])
		table->max_meals = ft_atoi(argv[5]);
}
