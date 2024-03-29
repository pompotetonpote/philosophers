/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:29:14 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/10 16:11:32 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*Arg 1 = Nombre de philosophes
Arg 2 = temps avant de mourrir
Arg 3 = temps de repas
Arg 4 = temps de repos
(Arg 5 = Nombre de repas a consommer)*/
int	check_args_digit(char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (argv[i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (!ft_isdigit(argv[i][j]) && argv[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void	check_args_errors(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
		error_log("Error : Invalid number of arguments\n", NULL);
	if (!check_args_digit(argv))
		error_log("Error : Unauthorized argument\n", NULL);
	if (ft_atoi(argv[1]) < 1)
		error_log("Error : Need at least one philo\n", NULL);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) == 0)
			error_log("Error : Philos need to eat at least 1 dish\n", NULL);
	}
}
