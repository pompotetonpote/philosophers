/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:09:38 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/05 18:04:57 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
/* Arguments a prendre en compte

Arg 1 = Nombre de philosophes
Arg 2 = temps avant de mourrir
Arg 3 = temps de repas
Arg 4 = temps de repos
(Arg 5 = Nombre de repas a consommer)*/
int	main(int argc, char **argv)
{
	t_table		*ph_table;
	t_philo		*philos;
	pthread_t	*th;

	ph_table = NULL;
	philos = NULL;
	check_args_errors(argc, argv);
	ph_table = init_ph_table(argv);
	philos = init_philos(ph_table);
	th = malloc(sizeof(pthread_t) * ph_table->nbr_seats);
	if (!th)
		error_log("Error : thread array NULL\n", &philos);
	start_threads(ph_table, philos, th);
	int i = 0;
	while (i++ < ft_atoi(argv[1]) && philos)
	{
		printf("idx : %d\n", philos->idx);
		philos = philos->next;
	}
	free(th);
	free_philos(&philos);
	return (0);
}
