/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:01:55 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/19 04:48:25 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	*simulation(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[ft_min(philo->left_fork,
				philo->right_fork)]);
		ft_state(philo, 'F');
		pthread_mutex_lock(&philo->forks[ft_max(philo->left_fork,
				philo->right_fork)]);
		ft_state(philo, 'F');
		ft_state(philo, 'E');
		usleep(philo->args->eat_time * 995);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->eat_mutex);
		if (philo->args->meals_count > 0)
			philo->eat_count++;
		philo->last_meal_time = now();
		pthread_mutex_unlock(&philo->eat_mutex);
		ft_state(philo, 'S');
		usleep(philo->args->sleep_time * 995);
		ft_state(philo, 'T');
	}
	return (NULL);
}
