/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:09:04 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/14 20:40:49 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* INCLUDES */

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>

/* STRUCTS */

typedef struct s_args
{
	struct timeval	start_time;
	pthread_mutex_t	*forks;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				philos_count;
	int				meals_count;
}	t_args;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	t_args		*args;
	int			last_meal_time;
}	t_philo;

/* FUNCTIONS PROTOTYPE */

int		ft_atoi(char *str);
int		get_timestamp(struct timeval start_time);
void	*routine(void *args);
void	ft_error(char *message);
void	create_threads(t_args *args);
void	check_args(int ac, char **av);
void	save_args(t_args *args, char **av);
void	ft_state(int timestamp, t_philo *philo, char action);
void	ft_cleanup(t_philo *philos, t_args *args);

#endif
