/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:01:55 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:01:57 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*simulation(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
		ft_state(philo, 'F');
		pthread_mutex_lock(&philo->args->forks[philo->right_fork]);
		ft_state(philo, 'F');
		ft_state(philo, 'E');
		usleep(philo->args->eat_time * 1000);
		pthread_mutex_unlock(&philo->args->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->args->meal_mutex);
		if (philo->args->meals_count > 0)
			philo->eat_count++;
		philo->last_meal_time = now();
		pthread_mutex_unlock(&philo->args->meal_mutex);
		ft_state(philo, 'S');
		usleep(philo->args->sleep_time * 1000);
		ft_state(philo, 'T');
	}
	return (NULL);
}
