/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:10:27 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/01 18:08:49 by yperonne         ###   ########.fr       */
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
	int				*head;
	int				fork;
	struct s_philo	*next;
}	t_philo;

/*  ERRORS  */

void	check_args_errors(int argc, char **argv);
void	error_log(char *str);

/*  UTILS  */

void	ft_putstr(char *str);
int		ft_isdigit(int a);

#endif