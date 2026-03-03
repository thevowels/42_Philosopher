/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:14:28 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/04 02:28:51 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char **argv)
{
	t_table		table;
	t_philo		philos[PHILO_MAX_COUNT];
	pid_t		pids[PHILO_MAX_COUNT];
	char		*philo_meal_sem[10];
	int			i;

	i = 0;
	table.philos = philos;
	table.pids = pids;
	ft_validate(argc, argv);
	ft_parse(&table, argv);
	ft_init_semaphores(&table);
	while(i < table.n_philos)
	{
		table.pids[i] = fork();
		if(table.pids[i] == -1)
			// error
		else if(table.pids[i] == 0)
		{
			break;
		}
	}	
}