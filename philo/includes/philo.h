/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/05 14:29:43 by yeye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>


typedef struct s_philo
{
	int				idx;
	int				fork;
	int				free_fork;
	pthread_mutex_t	has_fork;
	int				alive;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

typedef struct t_table
{
	int				seats;
	pthread_t		*th;
	int				t_spag;
	int				t_sleep;
	int				t_think;
	int				dishes;
//	struct s_philo	philos;
}	t_table;

/* Philos Linked-List */

t_philo	*init_philos(t_table *ph_table);
t_table	*init_ph_table(char **argv);
t_philo	*new_philo(int a);
t_philo	*add_new_philo(t_philo **philos, t_philo *philo);

/*  ERRORS  */

void	check_args_errors(int argc, char **argv);
void	error_log(char *str, t_table *ph_table, t_philo **philos);

/*  UTILS  */

void	ft_putstr(char *str);
int		ft_isdigit(int a);
int		ft_atoi(const char *str);
void	free_philos(t_philo **philos);

#endif