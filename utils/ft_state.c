/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 02:54:35 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/14 05:46:43 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_state(int timestamp, t_philo *philo, char action)
{
	if (action == 'F')
		printf("%d %d has taken a fork\n", timestamp, philo->id);
	else if (action == 'E')
		printf("%d %d is eating\n", timestamp, philo->id);
	else if (action == 'S')
		printf("%d %d is sleeping\n", timestamp, philo->id);
	else if (action == 'T')
		printf("%d %d is thinking\n", timestamp, philo->id);
	else if (action == 'D')
	{
		printf("%d %d is died\n", timestamp, philo->id);
		return ;
	}
	else
		return ;
}
