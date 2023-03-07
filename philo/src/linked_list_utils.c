/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:46:31 by yeye              #+#    #+#             */
/*   Updated: 2023/03/07 18:34:51 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*new_philo(t_table *ph_table, int a)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->idx = a;
	new_philo->alive = 1;
	new_philo->ph_table = ph_table;
	new_philo->dishes_eaten = 0;
	new_philo->next = NULL;
	return (new_philo);
}	

t_philo	*add_new_philo(t_philo **philos, t_philo *philo)
{
	t_philo	*tmp;

	tmp = *philos;
	if (*philos == NULL)
		*philos = philo;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = philo;
		philo->prev = tmp;
	}
	return (tmp);
}
