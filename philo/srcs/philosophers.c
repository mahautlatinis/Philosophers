/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:38:37 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 18:37:12 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	manage_only_one_philo(t_mem *mem)
{
	printf("%lums %d has taken a fork\n", get_time(mem), 1);
	take_time_doing(mem, mem->time_to_die);
	printf("%lums %d is dead\n", get_time(mem), 1);
	return ;
}

int	check_stop(t_mem *mem, int *stop)
{
	pthread_mutex_lock(&mem->stop_protect);
	*stop = mem->stop;
	pthread_mutex_unlock(&mem->stop_protect);
	if (*stop == 1)
		return (0);
	return (1);
}

void	sub_manage_threads(t_mem *mem)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (true)
	{
		if (check_death(mem, &stop) == 0)
			break ;
	}
	while (i < mem->number_of_philosophers)
		pthread_join(mem->philos_threads[i++], NULL);
	return ;
}

int	manage_threads(t_mem *mem)
{
	int	i;

	i = 0;
	while (i < mem->number_of_philosophers)
	{
		pthread_create(&mem->philos_threads[i], NULL, give_actions,
			&mem->tab_philos[i]);
		i = i + 2;
		if (i >= mem->number_of_philosophers && i % 2 == 0)
		{
			i = 1;
			usleep(300);
		}
	}
	sub_manage_threads(mem);
	return (0);
}
