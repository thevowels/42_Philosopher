/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:52:54 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/23 06:14:32 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait_to_start(t_table *table)
{
	while(1)
	{
		pthread_mutex_lock(&table->ready_mutex);
		if(table->ready == 1)
		{
			pthread_mutex_unlock(&table->ready_mutex);
			break;
		}
		pthread_mutex_unlock(&table->ready_mutex);
		usleep(100);
	}

}

void	ft_sleep(size_t mls)
{ 
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < mls)
		usleep(100);
}
