/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:22:27 by malatini          #+#    #+#             */
/*   Updated: 2021/07/21 09:50:20 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	save_args_bis(int argc, char **argv, t_mem *mem, int *i)
{
	while (*i < argc)
	{
		if (*i == 3)
		{
			mem->t_to_eat = ft_atoi(argv[*i]);
			if (mem->t_to_eat == 0)
				return (0);
		}
		else if (*i == 4)
		{
			mem->time_to_sleep = ft_atoi(argv[*i]);
			if (mem->time_to_sleep == 0)
				return (0);
		}
		else if (*i == 5)
		{
			mem->number_of_times_each_philosopher_must_eat = ft_atoi(argv[*i]);
			if (mem->number_of_times_each_philosopher_must_eat == 0)
				return (0);
			mem->option_specified = true;
		}
		(*i)++;
	}
	return (1);
}

/*
** Permet d'enregistrer les arguments du main pour les utiliser durant
** le programme.
*/
int	save_args(int argc, char **argv, t_mem *mem)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	while (i <= argc)
	{
		if (i == 1)
		{
			mem->number_of_philosophers = ft_atoi(argv[i]);
			if (mem->number_of_philosophers == 0)
				return (0);
		}
		else if (i == 2)
		{
			mem->time_to_die = ft_atoi(argv[i]);
			if (mem->time_to_die == 0)
				return (0);
		}
		else
			ret = save_args_bis(argc, argv, mem, &i);
		i++;
	}
	return (ret);
}

/*
** Permet de verifier que les arguments du main sont correctes.
** Trop de philos peut faire planter l'ordinateur.
*/
int	check_args(t_mem *mem)
{
	if (mem->number_of_philosophers > 200)
	{
		printf("Error.\nTesting with too many philosophers is dangerous.\n");
		return (-1);
	}
	if (mem->number_of_philosophers < 1 || mem->time_to_die < 1
		|| mem->t_to_eat < 1 || mem->time_to_sleep < 1
		|| (mem->number_of_times_each_philosopher_must_eat < 1
			&& mem->option_specified == true))
	{
		printf("Error.\nWrong values.\n");
		return (-1);
	}
	return (1);
}
