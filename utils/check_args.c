/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:51:57 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 01:05:51 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (ft_error("Incorrect number of arguments. Expected [5] or [6]"));
	while (++i < ac)
		ft_atoi(av[i]);
	if (ft_atoi(av[1]) > 200)
		return (ft_error("Maximum number of philosophers is [200]"));
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (ft_error("Philosophers meals count can't be [0] or less."));
	return (0);
}
