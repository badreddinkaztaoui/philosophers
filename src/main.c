/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:08:36 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/18 00:54:54 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_args	args;

	if (check_args(ac, av))
		return (1);
	save_args(&args, ac, av);
	if (create_threads(&args))
		return (1);
	return (0);
}
