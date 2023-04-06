/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:43:56 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/06 17:10:22 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_m()
{
	long int	time;
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}



void	ft_print_statut(pthread_t philo, long int times)
{
	printf("%ld [%ld] is taken a fork\n", times, philo);
	printf("%ld [%ld] is eating\n", times, philo);
	printf("%ld [%ld] is sleeping\n", times, philo);
	printf("%ld [%ld] is thinking\n", times, philo);
}
