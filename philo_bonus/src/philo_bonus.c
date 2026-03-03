/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:14:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/03 22:55:26 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	t_table		table;
	t_philo		philos[PHILO_MAX_COUNT];
	pid_t		pids[PHILO_MAX_COUNT];
	
	table.philos = philos;
	table.pids = pids;
	ft_validate(argc, argv);
	ft_parse(&table, argv);
	ft_init_semaphores(&table);
}