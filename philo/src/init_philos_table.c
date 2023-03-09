/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:23:36 by yeye              #+#    #+#             */
/*   Updated: 2023/03/09 14:35:03 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_philo_health(t_philo *philos)
{
	// unsigned long	res;

	// if (philos->last_meal != 0)
	// pthread_mutex_lock(&philos->timex);
	// res = get_time() - philos->last_meal;
	// printf("%lu - %lu = %lu > %d\n", get_time(), philos->last_meal, res,
	// 	philos->ph_table->t_die);
	if (get_time() - philos->last_meal
		> (unsigned long) philos->ph_table->t_die)
	{
		pthread_mutex_lock(&philos->healthex);
		philos->alive = 0;
		pthread_mutex_unlock(&philos->healthex);
		plog_philo_rtine("is dead", philos, RED, ENDC);
		// pthread_mutex_unlock(&philos->timex);
		return (0);
	}
	// pthread_mutex_unlock(&philos->timex);
	return (1);
}

int	check_philo_rip(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->ph_table->nbr_seats)
	{
		pthread_mutex_lock(&philos->healthex);
		if (philos->alive == 0)
		{
			pthread_mutex_unlock(&philos->healthex);
			return (0);
		}
		pthread_mutex_unlock(&philos->healthex);
		i++;
		if (philos->ph_table->nbr_seats == 1)
			break ;
		philos = philos->next;
	}
	return (1);
}

t_table	*init_ph_table(char **argv)
{
	t_table	*ph_table;

	ph_table = malloc(sizeof(t_table));
	if (!ph_table)
		return (NULL);
	ph_table->nbr_seats = ft_atoi(argv[1]);
	ph_table->t_die = ft_atoi(argv[2]);
	ph_table->t_spag = ft_atoi(argv[3]);
	ph_table->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		ph_table->nbr_dishes = ft_atoi(argv[5]);
	else
		ph_table->nbr_dishes = -1;
	return (ph_table);
}

t_philo	*init_philos(t_table *ph_table)
{
	t_philo	*philos;
	t_philo	*head;
	int		i;

	i = 1;
	philos = new_philo(ph_table, i++);
	head = philos;
	if (ph_table->nbr_seats == 1)
		return (philos);
	else
	{
		while (i <= ph_table->nbr_seats)
			philos = add_new_philo(&philos, new_philo(ph_table, i++));
		philos = philos->next;
		philos->next = head;
		head = philos;
		philos = philos->next;
		philos->prev = head;
	}
	return (philos);
}
