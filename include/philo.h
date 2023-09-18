/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:09:04 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:10:44 by bkaztaou         ###   ########.fr       */
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
	pthread_mutex_t	meal_mutex;
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
	t_args		*args;
	int			id;
	size_t		left_fork;
	size_t		right_fork;
	size_t		eat_count;
	size_t		start_eat_time;
	size_t		last_meal_time;
}	t_philo;

/* FUNCTIONS PROTOTYPE */

int		ft_atoi(char *str);
void	*simulation(void *args);
int		ft_error(char *message);
int		create_threads(t_args *args);
int		check_args(int ac, char **av);
void	save_args(t_args *args, int ac, char **av);
void	ft_state(t_philo *philo, char action);
void	check_end_simulation(t_args *args, t_philo *philos);
void	ft_cleanup(t_philo *philos, t_args *args);
long	now(void);

#endif
