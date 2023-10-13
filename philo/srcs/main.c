/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:37:17 by mahautlatin       #+#    #+#             */
/*   Updated: 2023/10/13 18:45:02 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_mem			mem;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_write;

	if (pthread_mutex_init(&m_stop, NULL))
		return (errno);
	mem.stop_protect = m_stop;
	if (pthread_mutex_init(&m_write, NULL))
		return (errno);
	mem.write_protect = m_write;
	if (init_args(argc, argv, &mem) == 0)
		return (0);
	if (init_all_mutex(&mem) != 0)
		return (errno);
	init_philos(&mem);
	return (manage_threads(&mem));
}