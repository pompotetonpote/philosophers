/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/04 16:55:23 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				idx;
	int				mseat;
	int				mssleep;
	int				msthink;
	int				fork;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

/* Philos Linked-List */

t_philo	*init_philos_table(char **argv);
t_philo	*new_philo(int a);
t_philo	*add_new_philo(t_philo **philos, t_philo *philo);

/*  ERRORS  */

void	check_args_errors(int argc, char **argv);
void	error_log(char *str, t_philo **philos);

/*  UTILS  */

void	ft_putstr(char *str);
int		ft_isdigit(int a);
int		ft_atoi(const char *str);
void	free_philos(t_philo **philos);

#endif