/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:41:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/18 17:59:49 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules->nb_of_philo)
	{
		if (pthread_mutex_lock(&data[i].start_e_mtx) != 0)
			return (1);
		if (get_chrono(data[i].start_e, get_time()) >= data[i].rules->tto_die || 
				get_chrono(data[i].rules->start_s, get_time()) >= data[i].rules->tto_die)
		{
			if (pthread_mutex_lock(&data[i].rules->death_mutex) != 0)
				return (1);
			data[i].rules->death = 1;
			if (pthread_mutex_unlock(&data[i].rules->death_mutex) != 0)
				return (1);
			if (pthread_mutex_unlock(&data[i].start_e_mtx) != 0)
				return (1);
			return (0);
		}
		if (pthread_mutex_unlock(&data[i].start_e_mtx) != 0)
			return (1);
		i++;
	}
	return (0);
}
