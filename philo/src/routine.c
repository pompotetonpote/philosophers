/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/08 17:05:00 by yperonne         ###   ########.fr       */
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
	if (philos->idx % 2 == 0)
	{
		pthread_mutex_lock(&philos->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
		pthread_mutex_lock(&philos->prev->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
	}
	else
	{
		pthread_mutex_lock(&philos->prev->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
		pthread_mutex_lock(&philos->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
	}
	usleep(philos->ph_table->t_spag * 1000);
	philos->last_meal = get_time();
	philos->dishes_eaten += 1;
//	printf("%d ate %d dishes\n", philos->idx, philos->dishes_eaten);
	pthread_mutex_unlock(&philos->has_fork);
	pthread_mutex_unlock(&philos->prev->has_fork);
}

void	philo_sleep(t_philo *philos)
{
	usleep(philos->ph_table->t_sleep * 1000);
	plog_philo_rtine("is sleeping", philos, BLUE, ENDC);
}

void	philo_think(t_philo *philos)
{
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
		if (!check_philo_rip(philos))
			break ;
		philo_sleep(philos);
		if (!check_philo_rip(philos))
			break ;
		philo_think(philos);
		if (!check_philo_health(philos))
			break ;
		if (!check_philo_rip(philos))
			break ;
	}
	return ((void *) NULL);
}

int	start_threads(t_table *ph_table, t_philo *philos, pthread_t *th)
{
	int	i;

	i = 0;
	philos->ph_table->start_time = get_time();
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
		if (pthread_create(&th[i], NULL, &philo_routine, philos))
			error_log("Error : thread creation failed\n", &philos);
		i++;
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
		pthread_mutex_destroy(&philos->has_fork);
		philos = philos->next;
		i++;
	}
	pthread_mutex_destroy(&philos->putex);
	return (0);
}
