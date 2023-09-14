/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 05:00:13 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/12 05:05:46 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_timestamp(struct timeval start_time)
{
	struct timeval	curr_time;
	int				sec;
	int				usec;

	gettimeofday(&curr_time, NULL);
	sec = (curr_time.tv_sec - start_time.tv_sec) * 1000;
	usec = (curr_time.tv_usec - start_time.tv_usec) / 1000;
	return (sec + usec);
}
