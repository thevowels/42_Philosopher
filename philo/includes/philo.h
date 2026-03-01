/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:28:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/24 04:53:25 by aphyo-ht         ###   ########.fr       */
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

typedef struct s_philo
{
	int					id;
	pthread_t			tid;
	int					meals_eaten;
	size_t				last_meal;
	pthread_mutex_t		meal_mutex;

	int					philo_alive;
	pthread_mutex_t		philo_alive_mutex;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	// set on init_routine
	size_t				start_time;

	// Set on ft_parse
	int					is_ready;
	int					is_alive;
	int					eaten_philos;

	// Parsed by ft_parse
	int					n_philos;
	size_t				t_die;
	size_t				t_eat;
	size_t				t_sleep;
	int					max_meals;

	pthread_mutex_t		ready_mutex;
	pthread_mutex_t		alive_mutex;
	pthread_mutex_t		eaten_philos_mutex;
	pthread_mutex_t		write_mutex;

	t_philo				*philos;
	pthread_mutex_t		*forks;

}						t_table;

// actions.c
void					ft_eat(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					ft_think(t_philo *philo);
void					ft_print_action(t_philo *philo, char *str);
void					ft_print_die(t_philo *philo);

// routines.c
void					*philo_routine(void *ptr);
int						ft_is_philo_alive(t_philo *philo);
void					*monitor_routine(void *ptr);
void					ft_start_dining(t_table *table);

// utils.c
size_t					ft_time_ms(void);
void					ft_sleep_ms(size_t ms);
int						ft_isdigit(char c);
int						ft_strlen(char *str);
int						ft_atoi(char *str);
void					ft_error_exit(char *str);

// init.c
void					init_table(t_table *table);
void					init_forks(t_table *table);
void					init_philos(t_table *table);

// table_utils.c
void					ft_set_alive(t_table *table, int i);
int						ft_get_alive(t_table *table);
void					ft_add_eaten_philos(t_table *table);
int						ft_get_eaten_philos(t_table *table);
void					ft_wait_until_ready(t_table *table);
void					ft_ready(t_table *table);
// validations.c
void					ft_validate(int argc, char **argv);

// actions.c
void					ft_print_action(t_philo *philo, char *str);
void					ft_print_die(t_philo *philo);

// cleaner.c
void					philo_cleanup(t_table *table, int i);
void					ft_destroy_table_mutexes(t_table *table);
void					ft_destroy_forks(t_table *table, int last_fork);
void					ft_destroy_philo_mutexes(t_table *table, int count);
void					clean_exit(t_table *table);
// parser.c
void					ft_validate(int argc, char **argv);
void					ft_parse(t_table *table, char **argv);
#endif