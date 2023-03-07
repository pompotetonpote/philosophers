/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/07 18:54:55 by yperonne         ###   ########.fr       */
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
	pthread_mutex_lock(&philos->has_fork);
	pthread_mutex_lock(&philos->prev->has_fork);
	usleep(philos->ph_table->t_spag);
	philos->dishes_eaten += 1;
	plog_philo_rtine("has taken a fork and is eating", philos, GREEN, ENDC);
	printf("%d ate %d dishes\n", philos->idx, philos->dishes_eaten);
	pthread_mutex_unlock(&philos->has_fork);
	pthread_mutex_unlock(&philos->prev->has_fork);
}

void	philo_sleep(t_philo *philos)
{
	usleep(philos->ph_table->t_sleep);
	plog_philo_rtine("is sleeping", philos, BLUE, ENDC);
}

void	philo_think(t_philo *philos)
{
	usleep(philos->ph_table->t_think);
	plog_philo_rtine("is thinking", philos, YELLOW, ENDC);
}

void	*philo_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *) arg;
	while (philos->alive == 1)
	{
		if (philos->dishes_eaten == philos->ph_table->nbr_dishes
			&& philos->ph_table->nbr_dishes > -1)
			break ;
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
	pthread_mutex_init(&philos->putex, NULL);
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_init(&philos->has_fork, NULL);
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		// printf("philos->alive = %d, nbr_seats = %d\n", philos->alive, i);
		if (pthread_create(&th[i], NULL, &philo_routine, philos))
			error_log("Error : thread creation failed\n", &philos);
		// printf("%d\n", i);
		// sleep(3);
		i++;
		philos = philos->next;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		// printf("philos->alive = %d, nbr_seats = %d\n", philos->alive, i);
		pthread_join(th[i], NULL);
//			error_log("Error : thread creation failed\n", &philos);
		// printf("%d\n", i);
		// sleep(3);
		i++;
	}
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_mutex_destroy(&philos->has_fork);
		philos = philos->next;
		i++;
	}
	pthread_mutex_destroy(&philos->putex);
	return (0);
}
