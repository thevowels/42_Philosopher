/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:13:51 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/04 02:12:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error_exit(char *str)
{
	if (write(2, str, ft_strlen(str)) == -1)
		ft_error_exit("Error while printing error\n");
	exit(EXIT_FAILURE);
}

void	ft_sleep_ms_from(size_t ms, size_t start_time)
{
	while (ft_time_ms() < start_time + ms)
		usleep(200);
}
