/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:44:49 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 18:31:49 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_time_doing(t_mem *mem, long unsigned int time_to_spend)
{
	unsigned int	start;
	unsigned int	current;
	int				stop;

	start = get_time(mem);
	current = start;
	stop = 0;
	while (current < start + time_to_spend)
	{
		usleep(100);
		current = get_time(mem);
		if (mem->number_of_philosophers != 1)
		{
			if (check_stop(mem, &stop) == 0 && time_to_spend != mem->t_to_eat)
				break ;
		}
	}
	return ;
}

long unsigned int	get_time(t_mem *mem)
{
	long unsigned int	time_spent;
	struct timeval		t;

	gettimeofday(&t, NULL);
	time_spent = t.tv_sec * 1000 + t.tv_usec / 1000 - mem->time_first;
	return (time_spent);
}

void	init_time(t_mem *mem)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	mem->time_first = t.tv_sec * 1000 + t.tv_usec / 1000;
	return ;
}
