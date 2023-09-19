/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:45:59 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:28:52 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	now(void)
{
	struct timeval	time;
	long			miliseconds;

	gettimeofday(&time, NULL);
	miliseconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (miliseconds);
}
