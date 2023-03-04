/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:23:36 by yeye              #+#    #+#             */
/*   Updated: 2023/03/04 18:15:42 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_table	*init_ph_table(char **argv)
{
	t_table	*ph_table;

	ph_table = malloc(sizeof(t_table));
	if (!ph_table)
		return (NULL);
	ph_table->seats = ft_atoi(argv[1]);
	ph_table->t_spag = ft_atoi(argv[2]);
	ph_table->t_sleep = ft_atoi(argv[3]);
	ph_table->t_think = ft_atoi(argv[4]);
	if (argv[5])
		ph_table->dishes = ft_atoi(argv[5]);
	return (ph_table);
}

t_philo	*init_philos(t_table *ph_table)
{
	t_philo	*philos;
	t_philo	*head;
	int		i;

	i = 0;
	philos = new_philo(i++);
	head = philos;
	while (i < ph_table->seats)
		philos = add_new_philo(&philos, new_philo(i++));
	philos = philos->next;
	philos->next = head;
	head = philos;
	philos = philos->next;
	philos->prev = head;
	return (philos);
}
