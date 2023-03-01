/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:09:38 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/01 17:25:46 by yperonne         ###   ########.fr       */
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
	check_args_errors(argc, argv);
	return (0);
}
