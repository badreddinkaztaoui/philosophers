/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:54:13 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:11:07 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	set_philo_data(t_philo *philos, t_args *args, int index)
{
	philos[index].args = args;
	philos[index].id = (index + 1);
	philos[index].left_fork = philos[index].id - 1;
	philos[index].right_fork = philos[index].id % args->philos_count;
	philos[index].eat_count = 0;
	philos[index].start_eat_time = now();
	philos[index].last_meal_time = now();
}

int	create_threads(t_args *args)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * args->philos_count);
	if (pthread_mutex_init(&args->meal_mutex, NULL))
		return (ft_error("Creation of meals mutexes failed."));
	while (++i < args->philos_count)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			return (ft_error("Creation of fork mutex failed."));
		set_philo_data(philos, args, i);
		if (pthread_create(&philos[i].thread, NULL, &simulation, &philos[i]))
			return (ft_error("Creation of threads failed"));
	}
	check_end_simulation(args, philos);
	ft_cleanup(philos, args);
	return (0);
}
