/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:55:12 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/14 20:52:48 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *args)
{
	t_philo			*philo;
	int				curr_time;
	int				counter;

	philo = (t_philo *)args;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		curr_time = get_timestamp(philo->args->start_time);
		if (curr_time - philo->last_meal_time > philo->args->die_time)
			ft_state(curr_time, philo, 'D');
		pthread_mutex_lock(&philo->args->forks[philo->left_fork]);
		ft_state(curr_time, philo, 'F');
		pthread_mutex_lock(&philo->args->forks[philo->right_fork]);
		ft_state(curr_time, philo, 'F');
		ft_state(curr_time, philo, 'E');
		usleep(philo->args->eat_time * 1000);
		pthread_mutex_unlock(&philo->args->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->args->forks[philo->left_fork]);
		if (philo->args->meals_count > 0)
			philo->eat_count++;
		philo->last_meal_time = curr_time;
		ft_state(curr_time, philo, 'S');
		usleep(philo->args->sleep_time * 1000);
		ft_state(curr_time, philo, 'T');
	}
	return (NULL);
}
