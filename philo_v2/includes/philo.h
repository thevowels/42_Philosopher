/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:28:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 18:18:46 by aphyo-ht         ###   ########.fr       */
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

typedef struct s_times
{
	size_t				t_die;
	size_t				t_eat;
	size_t				t_sleep;
	size_t				last_meal;
	size_t				born_time;
}						t_times;

typedef struct s_philo
{
	int					id;
	t_times				times;
	t_mutexes			mutexes;
	int					must_eat;
	pthread_t			thread_id;
	int					meals_eaten;
	int					philo_count;
}						t_philo;

typedef struct s_table
{
	t_mutexes			*forks;
	t_philo				*philos;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		write_mutex;
}						t_table;

// init.c
void					init_table(t_table *table, t_philo *philos,
							pthread_mutex_t *forks);

// str_utils.c
size_t					ft_strlen(const char *s);
long					ft_atoi(const char *str);

#endif