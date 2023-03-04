/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:09:38 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/04 16:48:29 by yperonne         ###   ########.fr       */
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
	t_philo	*philos;

	philos = NULL;
	check_args_errors(argc, argv);
	philos = init_philos_table(argv);
	if (!philos)
		error_log("Philos missing!\n", &philos);
	int i = 0;
	while (i++ < ft_atoi(argv[1]) && philos)
	{
		printf("idx : %d\n", philos->idx);
		philos = philos->next;
	}
	free_philos(&philos);
	return (0);
}
