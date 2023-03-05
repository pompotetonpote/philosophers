/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:18:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/05 14:33:25 by yeye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table(t_table **ph_table)
{
	t_table *tmp;

	if (!ph_table || !(*ph_table))
		return ;
	tmp = (*ph_table);
	free(tmp);
	*ph_table = NULL;	
}

void	free_philos(t_philo **philos)
{
	t_philo	*tmp;

	if (!philos || !(*philos))
		return ;
	(*philos)->prev->next = NULL;
	while (*philos)
	{
		tmp = (*philos);
		(*philos) = tmp->next;
		free(tmp);
	}
	*philos = NULL;
}

void	error_log(char *str, t_table **ph_table, t_philo **philos)
{
	free_philos(philos);
	free_table(ph_table);
	ft_putstr(str);
	exit (EXIT_SUCCESS);
}
