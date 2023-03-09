/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:18:40 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/09 13:36:00 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	free_table(t_table **ph_table)
// {
// 	t_table	*tmp;

// 	if (!ph_table || !(*ph_table))
// 		return ;
// 	// if ((*ph_table)->th)
// 	// 	free((*ph_table)->th);
// 	tmp = (*ph_table);
// 	free(tmp);
// 	*ph_table = NULL;
// }

void	free_philos(t_philo **philos)
{
	t_philo	*tmp;

	if (!philos || !(*philos))
		return ;
	if ((*philos)->ph_table)
		free((*philos)->ph_table);
	if((*philos)->next != NULL)
		(*philos)->prev->next = NULL;
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
