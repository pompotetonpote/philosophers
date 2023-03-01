/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:09:38 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/01 21:54:08 by yeye             ###   ########.fr       */
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
	t_philo **philos;
	
	check_args_errors(argc, argv);
	init_philos_table(argc, argv, philos);
	return (0);
}
