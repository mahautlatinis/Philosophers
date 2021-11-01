/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:44:49 by malatini          #+#    #+#             */
/*   Updated: 2021/07/20 14:36:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*
** Attend le temps necessaire (a l'action) passé en paramètre.
*/
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
}

/*
** Retoune le temps passé depuis le debut du chrono.
*/
long unsigned int	get_time(t_mem *mem)
{
	long unsigned int	time_spent;
	struct timeval		t;

	gettimeofday(&t, NULL);
	time_spent = t.tv_sec * 1000 + t.tv_usec / 1000 - mem->time_first;
	return (time_spent);
}

/*
** Lance le chrono
*/
void	init_time(t_mem *mem)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	mem->time_first = t.tv_sec * 1000 + t.tv_usec / 1000;
}
