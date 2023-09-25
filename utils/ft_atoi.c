/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 03:49:13 by bkaztaou          #+#    #+#             */
/*   Updated: 2023/09/08 21:39:01 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_iswspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static void	ft_isinrange(int result, char c)
{
	if (result > (INT_MAX - (c - '0')) / 10)
		ft_error("Number should be less than MAX_INT");
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (ft_iswspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (ft_error("Number should be positive"), -1);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (ft_error("Number should be valid"), -1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error("Number should be valid"), -1);
		ft_isinrange(result, str[i]);
		result = result * 10 + str[i++] - '0';
	}
	return (result);
}
