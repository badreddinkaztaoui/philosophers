/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 04:17:14 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:10:51 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_cleanup(t_philo *philos, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->philos_count)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->meal_mutex);
	free(philos);
	free(args->forks);
}
