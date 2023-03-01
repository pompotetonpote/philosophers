/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeye <yeye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:29:14 by yperonne          #+#    #+#             */
/*   Updated: 2023/03/01 21:17:31 by yeye             ###   ########.fr       */
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

int	check_args_nonull(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!ft_atoi(argv[1]) || !ft_atoi(argv[2]) || !ft_atoi(argv[3])
		|| !ft_atoi(argv[4]))
			return (0);
		i++;
	}
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (0);
	}
	return (1);
}

void	check_args_errors(int argc, char **argv)
{

	if (argc > 6 || argc < 5)
		error_log("Error : Invalid number of arguments\n");
	if (!check_args_nonull(argc, argv))
		error_log("Error : Empty argument\n");
	if (!check_args_digit(argv))
		error_log("Error : Arguments are not only composed of numbers\n");
}
