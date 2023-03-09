/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/09 14:34:51 by yperonne         ###   ########.fr       */
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
	if (philos->next == NULL)
		return ;
	else
	{	
		if (philos->idx % 2 == 0)
			usleep (philos->ph_table->t_spag * 250);
		pthread_mutex_lock(&philos->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
		pthread_mutex_lock(&philos->prev->has_fork);
		plog_philo_rtine("has taken a fork", philos, GREEN, ENDC);
		usleep(philos->ph_table->t_spag * 1000);
		// pthread_mutex_lock(&philos->timex);
		philos->last_meal = get_time();
		// pthread_mutex_unlock(&philos->timex);
		philos->dishes_eaten += 1;
		pthread_mutex_unlock(&philos->has_fork);
		pthread_mutex_unlock(&philos->prev->has_fork);
	}
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
	while (1)
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
		// if (!check_philo_health(philos))
		// 	break ;
		if (!check_philo_rip(philos))
			break ;
	}
	return ((void *) NULL);
}
