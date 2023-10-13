/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:32:21 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 18:31:43 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include "../include/ft_printf.h"

void	print_message_safe(t_philo *philo, t_mem *mem, char *str, int *stop)
{
	if (check_stop(mem, stop) == 0)
		return ;
	pthread_mutex_lock(&mem->write_protect);
	ft_printf("%lums %d %s\n", get_time(mem), philo->id + 1, str);
	pthread_mutex_unlock(&mem->write_protect);
	return ;
}
