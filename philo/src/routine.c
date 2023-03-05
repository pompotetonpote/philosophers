/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:41:51 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/05 14:33:56 by yeye             ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *) arg;
	while (philos->alive == 1)
	{
		if (pthread_mutex_lock(&philos->has_fork))
		{
			if (pthread_mutex_lock(&philos->next->has_fork))
			{
				sleep(1);
				pthread_mutex_unlock(&philos->next->has_fork);
			}
			else if (pthread_mutex_lock(&philos->prev->has_fork))
			{
				sleep(1);
				pthread_mutex_unlock(&philos->prev->has_fork);
			}
		}
		pthread_mutex_unlock(&philos->has_fork);
	}
	return (void *) (NULL);
}

int	threads(t_table *ph_table, t_philo *philos)
{
	int	i;

	i = 0;
	while(i < ph_table->seats)
	{
		pthread_mutex_init(&philos->has_fork, NULL);
		philos = philos->next;
		i++;
	}
	i = 0;
	while (i < ph_table->seats)
	{
		if (!pthread_create(&ph_table->th[i++], NULL, &routine, philos))
			error_log("Error : thread creation failed", ph_table, &philos);
		philos = philos->next;
	}
	i = 0;
		while(i < ph_table->seats)
	{
		pthread_mutex_destroy(&philos->has_fork);
		philos = philos->next;
		i++;
	}

	return (0);
}
