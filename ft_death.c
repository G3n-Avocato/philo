/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:41:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/19 13:41:14 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->nb_of_philo)
	{
		pthread_mutex_lock(&data[i].start_e_mtx);
		if (get_chrono(data[i].start_e, get_time()) >= data[i].rules->tto_die || 
				get_chrono(data[i].rules->start_s, get_time()) >= data[i].rules->tto_die)
		{
			pthread_mutex_lock(&data[i].rules->death_mutex);
			data[i].rules->death = 1;
			pthread_mutex_unlock(&data[i].rules->death_mutex);
			pthread_mutex_unlock(&data[i].start_e_mtx);
			return (0);
		}
		pthread_mutex_unlock(&data[i].start_e_mtx);
		i++;
	}
	return (0);
}
