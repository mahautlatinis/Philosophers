/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:37:13 by malatini          #+#    #+#             */
/*   Updated: 2023/10/09 21:25:28 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/errno.h>
# define ERROR -1
# define SUCCESS 1

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		*eating;
	long unsigned int	last_time_eat;
	int					counter_eat;
	bool				option_specified;
	void				*mem;
}				t_philo;

typedef struct s_mem
{
	int					number_of_philosophers;
	long unsigned int	time_to_die;
	long unsigned int	t_to_eat;
	long unsigned int	time_to_sleep;
	bool				option_specified;
	unsigned int		number_of_times_each_philosopher_must_eat;
	long unsigned int	time_first;
	bool				stop;
	t_philo				tab_philos[200];
	pthread_t			philos_threads[200];
	pthread_mutex_t		forks_mutex[200];
	pthread_mutex_t		stop_protect;
	pthread_mutex_t		write_protect;
}				t_mem;

typedef struct s_atoi_var
{
	long	i;
	long	max;
	long	sign;
	long	result;
}				t_atoi_var;

int					ft_isdigit(int c);
long				ft_atoi(char *str);
void				print_args(t_mem *mem);
int					save_args(int argc, char **argv, t_mem *mem);
void				*give_actions(void *arg);
void				init_time(t_mem *mem);
void				take_time_doing(t_mem *mem, long unsigned int t);
void				init_mem(t_mem *mem);
long unsigned int	get_time(t_mem *mem);
void				manage_only_one_philo(t_mem *mem);
int					init_philo_thread(t_mem *mem);
int					launch_threads(t_mem *mem);
int					check_args(t_mem *mem);
int					init_philos(t_mem *mem);
int					check_death(t_mem	*mem, int *stop);
int					init_all_mutex(t_mem *mem);
void				print_message_safe(t_philo *philo, t_mem *mem,
						char *str, int *stop);
void				print_args(t_mem *mem);
int					init_args(int argc, char **argv, t_mem *mem);
int					manage_threads(t_mem *mem);
int					ft_isalpha(int c);
int					save_args_bis(int ac, char **av, t_mem *m, int *i);
int					check_stop(t_mem *mem, int *stop);
void				manage_only_one_philo(t_mem *mem);

#endif
