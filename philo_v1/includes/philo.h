/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 05:28:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/21 17:21:47 by aphyo-ht         ###   ########.fr       */
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

typedef enum e_clean_sig
{
	NONE,
	FORKS,
	FORKS_PHILOS,
	SUCCESS
}						t_clean_sig;

typedef struct s_philo
{
	int					idx;
	int					n_meals;
	long				last_meal;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		*left_fork_mutex;
	pthread_mutex_t		*right_fork_mutex;
	int					has_forks;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	int					n_philo;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					max_meals;
	long				start_ms;
	int					stop;
	int					f_philos;
	pthread_mutex_t		stop_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		ready_mutex;
	pthread_mutex_t		finish_mutex;
	t_philo				*philos;
	pthread_t			monitor;
	int					ready;
}						t_table;

// race_utils.c
void					ft_set_stop(t_table *table);
int						ft_is_stop(t_table *table);
int						ft_print_action(t_philo *philo, char *str);

// libft.c
int						ft_isdigit(char c);
int						ft_strlen(char *str);
void					ft_putstr_fd(char *str, int fd);

// utils.c
int						ft_atoi(char *str);
int						ft_error(char *str);
long					ft_time_ms(void);
void					ft_sleep_ms(long ms);
void					ft_wait_until_ready(t_philo *philo);
// validations.c
void						ft_check_args(char **argv);
void						ft_check_durations(t_table *table);
// init.c
void					init_table(int argc, char **argv, t_table *table);
void					init_philos(t_table *table);
// clean.c
void					ft_free_forks(t_table *table);
void					ft_free_philos(t_table *table);
void					ft_clean_exit(t_table *table, t_clean_sig sig);

// mem.c
void					ft_create_forks(t_table *table);
void					ft_assign_forks(t_table *table, t_philo *philo);
void					ft_create_philos(t_table *table);

// launch.c
void					enjoy_meal(t_philo *philo);
void					*routine(void *arg);
void					*ft_host_routine(void *arg);
void					ft_launch_dining(t_table *table);
// threads.c
void					ft_create_philo_threads(t_table *table,
							pthread_t **philo_threads);
void					ft_thread_join(pthread_t *host, pthread_t *philos,
							int philo_count);

// host.c
int						ft_finished_philos(t_table *table);
void					ft_print_die(t_philo *philo);
int						ft_is_alive(t_philo *philo);
void					ft_stop_table(t_table *table);
int						ft_is_stop(t_table *table);
#endif