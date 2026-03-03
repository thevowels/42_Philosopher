/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:17:36 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/03 23:25:47 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>

void	ft_sem_close_unlink(sem_t *sem, const char *sem_name)
{
	sem_close(sem);
	sem_unlink(sem_name);
}

void	ft_validate_semaphores(t_table *table)
{
	int	flag;

	flag = 0;
	if (table->sem_forks == SEM_FAILED || table->sem_write == SEM_FAILED
		|| table->sem_is_ready == SEM_FAILED)
		flag = 1;
	if (flag)
	{
		if (table->sem_forks != SEM_FAILED)
			ft_sem_close_unlink(table->sem_forks, SEM_FORKS);
		if (table->sem_write != SEM_FAILED)
			ft_sem_close_unlink(table->sem_write, SEM_WRITE);
		if (table->sem_is_ready != SEM_FAILED)
			ft_sem_close_unlink(table->sem_is_ready, SEM_IS_READY);
		ft_error_exit("Error while opening semaphore.\n");
	}
}
/*

#define SEM_FORKS "/vowels_philo_forks"
#define SEM_WRITE "/vowels_philo_write"
#define SEM_IS_ALIVE "/vowels_philo_is_alive"
#define SEM_IS_READY "/vowels_philo_is_ready"

*/
void	ft_init_semaphores(t_table *table)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_IS_READY);
	table->sem_forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0600,
			table->n_philos);
	// if(table->sem_forks == SEM_FAILED)
	// 	ft_error_exit("Error while opening semaphores.\n");
	table->sem_write = sem_open(SEM_WRITE, O_CREAT | O_EXCL, 0600, 1);
	table->sem_is_ready = sem_open(SEM_IS_READY, O_CREAT | O_EXCL, 0600, 0);

	ft_validate_semaphores(table);
}

void	ft_init_philos(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].meals_eaten = 0;
	}
}