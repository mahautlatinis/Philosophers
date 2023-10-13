/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:59 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 18:51:33 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	sub_check(t_mem *m, t_philo *p, long unsigned int t, long unsigned int ltl)
{
	if (ltl + m->time_to_die < t)
	{
		pthread_mutex_lock(&m->stop_protect);
		m->stop = 1;
		pthread_mutex_unlock(&m->stop_protect);
		pthread_mutex_lock(&m->write_protect);
		if (m->option_specified == false)
			printf("%lums %d %s\n", get_time(m), p->id + 1, "is dead");
		pthread_mutex_unlock(&m->write_protect);
		return (0);
	}
	return (1);
}

int	check_death(t_mem	*mem, int	*stop)
{
	int					i;
	long unsigned int	time;
	long unsigned int	last_lunch_time;

	i = 0;
	if (*stop == 1)
		return (0);
	time = get_time(mem);
	while (i < mem->number_of_philosophers)
	{
		pthread_mutex_lock(mem->tab_philos[i].eating);
		last_lunch_time = mem->tab_philos[i].last_time_eat;
		pthread_mutex_unlock(mem->tab_philos[i].eating);
		if (sub_check(mem, &mem->tab_philos[i], time, last_lunch_time) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	do_routine(t_mem *mem, t_philo *philo, int *stop)
{
	pthread_mutex_lock(philo->fork_r);
	print_message_safe(philo, mem, "has taken a fork", (int *)stop);
	pthread_mutex_lock(philo->fork_l);
	print_message_safe(philo, mem, "has taken a fork", (int *)stop);
	pthread_mutex_lock(philo->eating);
	print_message_safe(philo, mem, "is eating", (int *)stop);
	philo->last_time_eat = get_time(mem);
	take_time_doing(mem, mem->t_to_eat);
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
	print_message_safe(philo, mem, "is sleeping", (int *)stop);
	take_time_doing(mem, mem->time_to_sleep);
	print_message_safe(philo, mem, "is thinking", (int *)stop);
	(philo->counter_eat)++;
	if (check_stop(mem, stop) == 0)
		return (0);
	return (1);
}

void	*give_actions(void *philo)
{
	t_philo	*not_void;
	t_mem	*mem;
	int		stop;

	not_void = (t_philo *)philo;
	mem = (t_mem *)not_void->mem;
	not_void->counter_eat = 0;
	stop = 0;
	while ((not_void->counter_eat
			< (int)mem->number_of_times_each_philosopher_must_eat
			&& mem->option_specified == true) || (mem->option_specified == false
			&& stop == 0))
	{
		if (do_routine(mem, not_void, &stop) == 0)
			return (NULL);
	}
	return (NULL);
}

int	launch_threads(t_mem *mem)
{
	int	i;

	i = 0;
	while (i < mem->number_of_philosophers)
	{
		pthread_create(&mem->philos_threads[i], NULL,
			give_actions, &mem->tab_philos[i]);
		i = i + 2;
		if (i >= mem->number_of_philosophers && i % 2 == 0)
		{
			i = 1;
			usleep(300);
		}
	}
	i = 0;
	while (i < mem->number_of_philosophers)
		pthread_join(mem->philos_threads[i++], NULL);
	return (0);
}
