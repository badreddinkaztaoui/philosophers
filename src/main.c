/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:08:36 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/20 04:33:36 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	t_args			args;
	int				i;

	if (check_args(ac, av) == -1)
		return (1);
	save_args(&args, ac, av);
	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * args.philos_count);
	philos = malloc(sizeof(t_philo) * args.philos_count);
	while (++i < args.philos_count)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			ft_error("Creation of forks mutexes failed.");
	if (create_threads(philos, &args, forks) == -1)
		return (1);
	free(forks);
	free(philos);
	return (0);
}
