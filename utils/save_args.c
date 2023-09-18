/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:53:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 00:52:45 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	save_args(t_args *args, int ac, char **av)
{
	if (ac == 6)
		args->meals_count = ft_atoi(av[5]);
	args->philos_count = ft_atoi(av[1]);
	args->die_time = ft_atoi(av[2]);
	args->eat_time = ft_atoi(av[3]);
	args->sleep_time = ft_atoi(av[4]);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_count);
}
