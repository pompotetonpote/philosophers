/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/01 21:54:00 by yeye             ###   ########.fr       */
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
	int				*head;
	int				fork;
	struct s_philo	*next;
}	t_philo;

/* Philos Linked-List */

void	init_philos_table(int argc, char **argv, t_philo **philos);

/*  ERRORS  */

void	check_args_errors(int argc, char **argv);
void	error_log(char *str);

/*  UTILS  */

void	ft_putstr(char *str);
int		ft_isdigit(int a);
int		ft_atoi(const char *str);

#endif