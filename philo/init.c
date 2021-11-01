/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:22:14 by malatini          #+#    #+#             */
/*   Updated: 2021/07/20 14:30:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*
** Initialise la structure principale et verifie les arguments.
** Gere le cas particulier de 1 seul philo.
*/
int	init_args(int argc, char **argv, t_mem *mem)
{
	if (argc < 5 || argc > 6)
		return (0);
	init_mem(mem);
	if (save_args(argc, argv, mem) == 0)
		return (0);
	if (check_args(mem) == -1)
		return (0);
	if (mem->number_of_philosophers == 1)
	{
		manage_only_one_philo(mem);
		return (0);
	}
	return (1);
}

/*
** Initialise le tableau de philos pour ne pas avoir de garbage value.
*/
int	init_philos(t_mem *mem)
{
	int	i;

	i = 0;
	while (i < mem->number_of_philosophers)
	{
		mem->tab_philos[i].id = i;
		mem->tab_philos[i].last_time_eat = 0;
		mem->tab_philos[i].counter_eat = 0;
		mem->tab_philos[i].mem = (void *)mem;
		i++;
	}
	return (SUCCESS);
}

/*
** Initialise la structure principale pour eviter des garbages values.
*/
void	init_mem(t_mem *mem)
{
	mem->number_of_philosophers = 0;
	mem->time_to_die = 0;
	mem->t_to_eat = 0;
	mem->option_specified = false;
	mem->number_of_times_each_philosopher_must_eat = 0;
	mem->stop = false;
	init_time(mem);
	mem->stop = false;
}

/*
** Initialise les mutex, indique les fourchettes droites et gauches pour
** les philos.
*/
int	init_all_mutex(t_mem *mem)
{
	int				i;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	m_eating[200];

	i = 0;
	while (i < mem->number_of_philosophers)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return (errno);
		if (pthread_mutex_init(&m_eating[i], NULL))
			return (errno);
		mem->tab_philos[i].fork_r = &fork[i];
		mem->tab_philos[i].eating = &m_eating[i];
		if (i != mem->number_of_philosophers - 1)
			mem->tab_philos[i].fork_l = &fork[i + 1];
		else
			mem->tab_philos[i].fork_l = &fork[0];
		i++;
	}
	return (0);
}
