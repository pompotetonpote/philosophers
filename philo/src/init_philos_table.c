/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:23:36 by yeye              #+#    #+#             */
/*   Updated: 2023/03/08 21:44:20 by yeye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_philo_health(t_philo *philos)
{
	unsigned long	res;
	res = get_time() - philos->last_meal;
	printf("%lu - %lu = %lu > %d\n", get_time(), philos->last_meal, res, philos->ph_table->t_die);
//	sleep(3);
	if (get_time() - philos->last_meal
		> (unsigned long) philos->ph_table->t_die)
	{
		pthread_mutex_lock(&philos->healthex);
		philos->alive = 0;
		pthread_mutex_unlock(&philos->healthex);
		plog_philo_rtine("is dead", philos, RED, ENDC);
		return (0);
	}
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
	if (philos->dishes_eaten == philos->ph_table->nbr_dishes
		&& philos->ph_table->nbr_dishes > -1)
		write(1,"debug init_philo\n", 17);
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

int	start_threads(t_table *ph_table, t_philo *philos, pthread_t *th)
{
	int	i;

	i = 0;
	philos->ph_table->start_time = get_time();
	pthread_mutex_init(&philos->putex, NULL);
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_init(&philos->healthex, NULL);
		pthread_mutex_init(&philos->has_fork, NULL);
		if (ph_table->nbr_seats == 1)
			break ;
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		if (pthread_create(&th[i], NULL, &philo_routine, philos))
			error_log("Error : thread creation failed\n", &philos);
		i++;
		if (ph_table->nbr_seats == 1)
			break ;
		philos = philos->next;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_destroy(&philos->healthex);
		pthread_mutex_destroy(&philos->has_fork);
		if (ph_table->nbr_seats == 1)
			break ;
		philos = philos->next;
		i++;
	}
	pthread_mutex_destroy(&philos->putex);
	return (0);
}
