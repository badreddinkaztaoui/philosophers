/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:54:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:08:31 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_state(t_philo *philo, char action)
{
	size_t	timestamp;

	timestamp = now() - philo->start_eat_time;
	if (action == 'F')
		printf("%lu %d has taken a fork\n", timestamp, philo->id);
	else if (action == 'E')
		printf("%lu %d is eating\n", timestamp, philo->id);
	else if (action == 'S')
		printf("%lu %d is sleeping\n", timestamp, philo->id);
	else if (action == 'T')
		printf("%lu %d is thinking\n", timestamp, philo->id);
	else if (action == 'D')
		printf("%lu %d is died\n", timestamp, philo->id);
}
