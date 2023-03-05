/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/05 18:27:04 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	lock_fork_eat(t_philo *philos, pthread_mutex_t has_fork)
// {
// 	pthread_mutex_lock(&philos->has_fork);
// 	pthread_mutex_lock(&philos->next->has_fork);
// 	sleep(0.2);
// 	pthread_mutex_unlock(&philos->has_fork);
// 	pthread_mutex_unlock(&philos->next->has_fork);
// }

// void	*routine(void *arg)
// {
	
// }

void	philo_spag(t_philo *philos)
{
	
}
void	philo_sleep(t_philo *philos)
{
	
}
void	philo_think(t_philo *philos)
{
	
}

void	*philo_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *) arg;
	while (philos->alive == 1)
	{
		philo_spag(philos);
		philo_sleep(philos);
		philo_think(philos);
	}
	return ((void *) NULL);
}

int	start_threads(t_table *ph_table, t_philo *philos, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_init(&philos->has_fork, NULL);
		philos = philos->next;
		i++;
	}
	printf("debug 'threads' after mutex init\n");
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		printf("philos->alive = %d, nbr_seats = %d\n", philos->alive, i);
		if (pthread_create(&th[i], NULL, &philo_routine, philos))
		{
			printf("ph_table->th[%d] = %p\n", i, th[i]);
			error_log("Error : thread creation failed\n", &philos);
			i++;
		}
		philos = philos->next;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_destroy(&philos->has_fork);
		philos = philos->next;
		i++;
	}
	return (0);
}
