/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:09:07 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
		pthread_mutex_destroy(&(table->forks_mutex[i++]));
	free(table->forks_mutex);
	table->forks_mutex = NULL;
}

void	ft_free_philos(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->n_philo)
	{
		philo = &table->philos[i];
		pthread_mutex_destroy(&philo->meal_mutex);
		i++;
	}
	free(table->philos);
	table->philos = NULL;

}
void ft_clean_exit(t_table *table, t_clean_sig sig)
{
	pthread_mutex_destroy(&table->stop_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	if (sig == FORKS)
		ft_free_forks(table);
	if (sig == FORKS_PHILOS)
	{
		ft_free_philos(table);
		ft_free_forks(table);
	}
	if(sig == SUCCESS)
	{
		// pthread_mutex_destroy(&table->ready_mutex);
		ft_free_philos(table);
		ft_free_forks(table);
	}
	else
		ft_error("Error on malloc, clean exit\n");
}
