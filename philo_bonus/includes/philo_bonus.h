/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:14:24 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/03/04 02:13:16 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX_COUNT 200

# define SEM_FORKS "/vowels_philo_forks"
# define SEM_WRITE "/vowels_philo_write"
# define SEM_IS_ALIVE "/vowels_philo_is_alive"
# define SEM_IS_READY "/vowels_philo_is_ready"
# define SEM_EATEN_PHILOS "/vowels_philo_eaten_philos"
typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	t_table				*table;
	
}						t_philo;

typedef struct s_table
{
	size_t				start_time;

	// Readonly informations about table
	int					n_philos;
	int					max_meals;
	size_t				t_eat;
	size_t				t_sleep;
	size_t				t_die;
	pid_t				*pids;
	t_philo				*philos;

	sem_t				*sem_forks;
	sem_t				*sem_write;
	sem_t				*sem_is_alive;
	sem_t				*sem_is_ready;
	sem_t				*sem_eaten_philos;

	//need to lock with sem
	pid_t				*childs;
}						t_table;

// init

void	ft_init_semaphores(t_table *table);
// Parser
void	ft_validate(int argc, char **argv);
void	ft_parse(t_table *table, char **argv);


// utils_bonus
size_t	ft_time_ms(void);
void	ft_sleep_ms(size_t ms);
int		ft_isdigit(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

// utils_extra_bonus
void	ft_error_exit(char *str);
void	ft_sleep_ms_from(size_t ms, size_t start_time);

#endif