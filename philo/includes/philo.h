/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/10 14:15:08 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ENDC		"\e[0m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[1;34m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define MAG		"\e[35m"

typedef struct t_table
{
	int				nbr_seats;
	int				t_die;
	int				t_spag;
	int				t_sleep;
	int				t_think;
	int				nbr_dishes;
	unsigned long	start_time;
	pthread_mutex_t	putex;
}	t_table;

typedef struct s_philo
{
	t_table			*ph_table;
	int				idx;
	int				r_fork;
	int				l_fork;
	int				dishes_eaten;
	unsigned long	last_meal;
	pthread_mutex_t	has_fork;
	pthread_mutex_t	healthex;
	pthread_mutex_t	timex;
	pthread_mutex_t	dishes;
	int				alive;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

/* Philos Linked-List */

t_philo			*init_philos(t_table *ph_table);
t_table			*init_ph_table(char **argv);
t_philo			*new_philo(t_table *ph_table, int a);
t_philo			*add_new_philo(t_philo **philos, t_philo *philo);

/* Threads & Routine*/

int				start_threads(t_table *ph_table, t_philo *philos,
					pthread_t *th);
void			plog_philo_rtine(char *str, t_philo *philos,
					char *color, char *endc);
int				check_philo_health(t_philo *philos);
int				check_philo_rip(t_philo *philos);
void			*philo_routine(void *arg);

/*  ERRORS  */

void			check_args_errors(int argc, char **argv);
void			error_log(char *str, t_philo **philos);

/*  UTILS  */

void			ft_putstr(char *str);
int				ft_isdigit(int a);
int				ft_atoi(const char *str);
void			free_philos(t_philo **philos);
void			free_table(t_table **ph_table);
unsigned long	get_time(void);
void			ft_usleep(unsigned long time);

#endif