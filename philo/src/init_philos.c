/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:23:36 by yeye              #+#    #+#             */
/*   Updated: 2023/03/04 16:41:24 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*init_philos_table(char **argv)
{
	t_philo	*philos;
	t_philo	*head;
	int		i;

	i = 0;
	philos = new_philo(i++);
	head = philos;
	while (i < ft_atoi(argv[1]))
		philos = add_new_philo(&philos, new_philo(i++));
	philos = philos->next;
	philos->next = head;
	head = philos;
	philos = philos->next;
	philos->prev = head;
	return (philos);
}
