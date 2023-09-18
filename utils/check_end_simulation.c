/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:42:28 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 00:43:40 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	death(t_philo *philo)
{
	if (now() - philo->last_meal_time > philo->args->die_time)
		return (ft_state(philo, 'D'), 1);
	return (0);
}

void	fill_cache(int *cache, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		cache[i] = 0;
}

int	all_philos_eat(int *cache, int len)
{
	int	i;

	i = 0;
	while (cache[i] == 1)
		i++;
	if (i == len)
		return (1);
	return (0);
}

void	check_end_simulation(t_args *args, t_philo *philos)
{
	int	i;
	int	cache[255];

	i = 0;
	fill_cache(cache, args->philos_count);
	while (i < args->philos_count)
	{
		pthread_mutex_lock(&args->meal_mutex);
		if (args->meals_count > 0 && (philos[i].eat_count == args->meals_count))
		{
			cache[i] = 1;
			if (all_philos_eat(cache, args->philos_count))
				return ;
		}
		if (death(&philos[i]))
			return ;
		i++;
		if (i == args->philos_count)
			i = 0;
		pthread_mutex_unlock(&args->meal_mutex);
	}
}
