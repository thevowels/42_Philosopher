/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:45:00 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/04 02:18:10 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	ft_eat(t_philo *philo)
// {
// 	lock_forks(philo);
// 	pthread_mutex_lock(&philo->meal_mutex);
// 	philo->last_meal = ft_time_ms();
// 	ft_print_action(philo, "is eating");
// 	philo->meals_eaten += 1;
// 	pthread_mutex_unlock(&philo->meal_mutex);
// 	ft_sleep_ms(philo->table->t_eat);
// 	if (philo->table->max_meals != -1
// 		&& philo->meals_eaten == philo->table->max_meals)
// 		ft_add_eaten_philos(philo->table);
// 	pthread_mutex_unlock(philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// }
void	ft_eat(t_philo *philo)
{
	// locking forks
	size_t start_time;
	sem_wait(philo->table->sem_forks);
	sem_wait(philo->table->sem_forks);
	start_time = ft_time_ms();
	// printing action.
	ft_print_action(philo,"is eating");
	// lock meal_mutex and increase meals eaten
	// TODO:
	ft_sleep_ms_from(philo->table->t_eat, start_time);
	sem_post(philo->table->sem_forks);
	sem_post(philo->table->sem_forks);
	if(philo->table->max_meals == philo->meals_eaten)
		sem_post(philo->table->sem_eaten_philos);
}

void	ft_sleep(t_philo *philo)
{
	size_t	start_time;
	start_time = ft_time_ms();
	ft_print_action(philo, "is sleeping");
	ft_sleep_ms_from(philo->table->t_sleep, start_time);
}

void	ft_think(t_philo *philo)
{
	ft_print_action(philo, "is thinking");
}

// void	ft_print_action(t_philo *philo, char *str)
// {
// 	size_t	passed_time;

// 	pthread_mutex_lock(&philo->table->write_mutex);
// 	passed_time = ft_time_ms() - philo->table->start_time;
// 	if (!ft_get_alive(philo->table))
// 	{
// 		pthread_mutex_unlock(&philo->table->write_mutex);
// 		return ;
// 	}
// 	printf("%ld %d %s\n", passed_time, philo->id, str);
// 	pthread_mutex_unlock(&philo->table->write_mutex);
// }

void	ft_print_action(t_philo *philo, char *str)
{
	size_t	passed_time;

	sem_wait(philo->table->sem_write);
	passed_time = ft_time_ms() - philo->table->start_time;
	if (!ft_get_alive(philo->table))
	{
		sem_post(philo->table->sem_write);
		return ;
	}
	printf("%ld %d %s\n", passed_time, philo->id, str);
	sem_post(philo->table->sem_write);
}



void	ft_print_die(t_philo *philo)
{
	size_t	time_ms;

	time_ms = ft_time_ms() - (philo->table->start_time);
	sem_wait(philo->table->sem_write);
	printf("%ld %d died\n", time_ms, philo->id);
	sem_post(philo->table->sem_write);
}
