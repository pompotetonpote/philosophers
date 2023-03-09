/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:28:06 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/09 11:36:47 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_init(t_table *ph_table, t_philo *philos)
{
	int	i;

	i = 0;
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
}

void	mutex_destroy(t_table *ph_table, t_philo *philos)
{
	int	i;

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
}

int	start_threads(t_table *ph_table, t_philo *philos, pthread_t *th)
{
	int	i;

	i = 0;
	philos->ph_table->start_time = get_time();
	mutex_init(ph_table, philos);
	while (i < ph_table->nbr_seats)
	{
		if (pthread_create(&th[i], NULL, &philo_routine, philos))
			error_log("Error : thread creation failed\n", &philos);
		i++;
		if (ph_table->nbr_seats == 1)
			break ;
		philos = philos->next;
	}
//	while ()
	i = 0;
	while (i < ph_table->nbr_seats)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	mutex_destroy(ph_table, philos);
	return (0);
}
