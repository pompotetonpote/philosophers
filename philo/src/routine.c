/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/10 17:12:46 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_spag(t_philo *philos)
{
	if (philos->next == NULL)
		return ;
	else
	{	
		if (philos->idx % 2 == 0 && philos->dishes_eaten == 0)
			ft_usleep(philos->ph_table->t_spag * 0.2);
		pthread_mutex_lock(&philos->has_fork);
		plog_philo_rtine("has taken a fork", philos, CYAN, ENDC);
		pthread_mutex_lock(&philos->prev->has_fork);
		plog_philo_rtine("has taken a fork", philos, CYAN, ENDC);
		plog_philo_rtine("is eating", philos, GREEN, ENDC);
		ft_usleep(philos->ph_table->t_spag);
		pthread_mutex_lock(&philos->timex);
		philos->last_meal = get_time();
		pthread_mutex_unlock(&philos->timex);
		pthread_mutex_lock(&philos->dishes);
		philos->dishes_eaten += 1;
		pthread_mutex_unlock(&philos->dishes);
		pthread_mutex_unlock(&philos->has_fork);
		pthread_mutex_unlock(&philos->prev->has_fork);
	}
}

void	philo_sleep(t_philo *philos)
{
	plog_philo_rtine("is sleeping", philos, BLUE, ENDC);
	if (philos->ph_table->t_sleep > 0)
		ft_usleep(philos->ph_table->t_sleep);
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
			&& philos->ph_table->nbr_dishes > 0)
		{	
			plog_philo_rtine("ate all the plates", philos, MAG, ENDC);
			break ;
		}
		// if (!check_plate_philos(philos))
		// 	break ;
		philo_spag(philos);
		if (!check_philo_rip(philos))
			break ;
		philo_sleep(philos);
		if (!check_philo_rip(philos))
			break ;
		philo_think(philos);
		if (!check_philo_rip(philos))
			break ;
	}
	return ((void *) NULL);
}
