/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:38:37 by malatini          #+#    #+#             */
/*   Updated: 2021/08/28 16:31:14 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

/*
** Cas particulier si n'y a qu'un philo puisqu'il n y aura jamais de
** deuxieme fourchette.
*/
void	manage_only_one_philo(t_mem *mem)
{
	printf("%lums %d has taken a fork\n", get_time(mem), 1);
	take_time_doing(mem, mem->time_to_die);
	printf("%lums %d is dead\n", get_time(mem), 1);
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

/*
** Va creer tous les threads des philos et les lancer avec la fonction
** "give_actions". Va lancer les paires puis les impaires et s'arreter
** quand on aura fini.
*/
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

int	main(int argc, char **argv)
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
