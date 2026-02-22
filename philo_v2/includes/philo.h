/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:28:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/22 23:36:08 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define PHILO_MAX_COUNT 200

typedef struct s_table	t_table;

typedef struct s_mutexes
{
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*write_mutex;
	pthread_mutex_t		*meal_mutex;
}						t_mutexes;

typedef struct s_philo
{
	int					id;
	t_mutexes			mutexes;
	pthread_t			thread_id;
	int					meals_eaten;
	size_t				last_meal;
	size_t				born_time;
}						t_philo;

typedef struct s_table
{
	t_mutexes			*forks;
	t_philo				*philos;
	size_t				t_die;
	size_t				t_eat;
	size_t				t_sleep;
	int					n_philos;
	int					n_meals;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		write_mutex;
}						t_table;

// validation.c
void					ft_validate(int argc, char **argv);

// utils.c
size_t					get_current_time(void);
int						ft_isdigit(char c);
int						ft_strlen(char *str);
int						ft_atoi(char *str);
void					ft_error_exit(char *str);

// init.c
void					init_table(t_table *table);
void					init_forks(t_table *table);
void					init_philos(t_table *table);

// clean.c
void					ft_destroy_forks(t_table *table, int last_fork);
void					ft_destroy_table(t_table *table);
#endif