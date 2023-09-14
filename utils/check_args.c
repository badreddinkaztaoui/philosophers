/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:51:57 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/12 04:58:37 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 6)
		ft_error("Incorrect number of arguments. Expected [5]");
	while (++i < 6)
		ft_atoi(av[i]);
}
