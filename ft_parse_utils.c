/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:30:58 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/04 18:06:18 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long long	neg;
	long long	nb;

	nb = 0;
	neg = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - 48;
		if (nb * neg > 2147483647)
			return (-1);
		str++;
	}
	return ((int)nb * neg);
}

int	ft_check_int(t_rules rules)
{
	if (rules.nb_of_philo == -1 || rules.tto_die == -1)
		return (-1);
	if (rules.tto_eat == -1 || rules.tto_sleep == -1)
		return (-1);
	return (0);
}
