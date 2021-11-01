/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:32:21 by malatini          #+#    #+#             */
/*   Updated: 2021/07/23 19:53:32 by mahautlat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*
**	Va permettre d'afficher un message de maniere propre sans data race.
*/
void	print_message_safe(t_philo *philo, t_mem *mem, char *str, int *stop)
{
	if (check_stop(mem, stop) == 0)
		return ;
	pthread_mutex_lock(&mem->write_protect);
	printf("%lums %d %s\n", get_time(mem), philo->id + 1, str);
	pthread_mutex_unlock(&mem->write_protect);
}

/*
** Permet d'afficher la recuperation des arguments du main a des fins
** de test.
*/
void	print_args(t_mem *mem)
{
	printf("number of philosophers: %i\n", mem->number_of_philosophers);
	printf("time to die : %lu\n", mem->time_to_die);
	printf("time to eat : %lu\n", mem->t_to_eat);
	printf("time to sleep : %lu\n", mem->time_to_sleep);
	printf("Optional - number of times to eat %i\n",
		mem->number_of_times_each_philosopher_must_eat);
	printf("Option bool %i\n", mem->option_specified);
}
