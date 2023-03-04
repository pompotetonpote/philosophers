/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:18:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/04 16:55:22 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philos(t_philo **philos)
{
	t_philo	*tmp;

	if (!philos || !(*philos))
		return ;
	while (*philos)
	{
		tmp = (*philos);
		(*philos) = tmp->next;
		free(tmp);
	}
	*philos = NULL;
}

void	error_log(char *str, t_philo **philos)
{
	free_philos(philos);
	ft_putstr(str);
	exit (EXIT_SUCCESS);
}
