/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:34:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/20 22:12:56 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table table;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Invalid number of parameters", 2);
		exit(EXIT_FAILURE);
	}
	init_table(argc, argv, &table);
	init_philos(&table);
	ft_launch_dining(&table);
	ft_clean_exit(&table, SUCCESS);
	return (0);
}