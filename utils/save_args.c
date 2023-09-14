/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:53:19 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/14 04:14:16 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	save_args(t_args *args, char **av)
{
	args->philos_count = ft_atoi(av[1]);
	args->meals_count = ft_atoi(av[5]);
	args->die_time = ft_atoi(av[2]);
	args->eat_time = ft_atoi(av[3]);
	args->sleep_time = ft_atoi(av[4]);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_count);
	gettimeofday(&args->start_time, NULL);
}
