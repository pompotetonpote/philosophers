/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:46:31 by yeye              #+#    #+#             */
/*   Updated: 2023/03/04 16:15:27 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*new_philo(int a)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->idx = a;
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
