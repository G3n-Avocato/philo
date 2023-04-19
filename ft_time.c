/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:43:56 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/19 13:42:32 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	long int	time;
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

long int	get_chrono(long int start_s, long int end)
{
	long int	time;

	time = end - start_s;
	return (time);
}

void	ft_print_status(t_data *data, long int time, char *str)
{
	pthread_mutex_lock(&data->rules->m_print);
	printf("%ld %d %s\n", time, data->num_philo, str);
	pthread_mutex_unlock(&data->rules->m_print);
}
