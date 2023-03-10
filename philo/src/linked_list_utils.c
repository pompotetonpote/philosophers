/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:46:31 by yeye              #+#    #+#             */
/*   Updated: 2023/03/10 20:10:07 by yeye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	plog_philo_rtine(char *str, t_philo *philos, char *color, char *endc)
{	
	unsigned long	timestamp;

	timestamp = (get_time() - philos->ph_table->start_time);
	pthread_mutex_lock(&philos->ph_table->putex);
	if (!check_philo_rip_print(philos))
	{
		pthread_mutex_unlock(&philos->ph_table->putex);
		return ;
	}
	printf("%s%lu %d %s%s\n", color, timestamp,
		philos->idx, str, endc);
	pthread_mutex_unlock(&philos->ph_table->putex);
}

// int	check_plate_philos(t_philo *philos)
// {
// 	int	i;
// 	int	dishes;

// 	i = 0;
// 	dishes = 0;
// 	while (i < philos->ph_table->nbr_seats)
// 	{
// 		pthread_mutex_lock(&philos->dishes);
// 		if (philos->dishes_eaten == philos->ph_table->nbr_dishes)
// 			dishes++;
// 		pthread_mutex_unlock(&philos->dishes);
// 		if (dishes == philos->ph_table->nbr_seats)
// 			return (0);
// 		philos = philos->next;
// 	}
// 	return (1);
// }

t_philo	*new_philo(t_table *ph_table, int a)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->idx = a;
	new_philo->alive = 1;
	new_philo->ph_table = ph_table;
	new_philo->dishes_eaten = 0;
	new_philo->next = NULL;
	return (new_philo);
}	

t_philo	*add_new_philo(t_philo **philos, t_philo *philo)
{
	t_philo	*tmp;

	tmp = *philos;
	if (*philos == NULL)
		*philos = philo;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = philo;
		philo->prev = tmp;
	}
	return (tmp);
}
