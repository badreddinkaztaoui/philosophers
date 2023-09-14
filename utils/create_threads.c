/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:54:13 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/14 20:38:04 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_args *args)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * args->philos_count);
	while (++i < args->philos_count)
	{
		if (pthread_mutex_init(&args->forks[i], NULL))
			ft_error("Creation of fork mutex failed.");
		philos[i].args = args;
		philos[i].id = (i + 1);
		philos[i].left_fork = philos[i].id - 1;
		philos[i].right_fork = philos[i].id % args->philos_count;
		philos[i].eat_count = 0;
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			ft_error("Creation of threads failed");
	}
	i = -1;
	while (++i < args->philos_count)
		if (pthread_join(philos[i].thread, NULL))
			ft_error("Joining of threads failed");
	ft_cleanup(philos, args);
}
