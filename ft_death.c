/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:41:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/22 14:29:18 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_data *data)
{	
	pthread_mutex_lock(&data->rules->death_mutex);
	if (data->rules->death == 1)
	{
		pthread_mutex_unlock(&data->rules->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->rules->death_mutex);
	return (0);
}

void	philo_death(t_data *data)
{
	long int	time;

	pthread_mutex_lock(&data->rules->death_mutex);
	data->rules->death = 1;
	pthread_mutex_unlock(&data->rules->death_mutex);
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "died");
}

int	death(t_data *data)
{
	int	i;
	int	eat;

	i = 0;
	while (check_end(data) != 1 && check_eat_philo(data) != 1)
	{
		while (i < data->rules->nb_of_philo)
		{
			pthread_mutex_lock(&data[i].start_e_mtx);
			eat = get_chrono(data[i].start_e, get_time());
			pthread_mutex_unlock(&data[i].start_e_mtx);
			if (eat >= data[i].rules->tto_die)
			{
				philo_death(&data[i]);
				return (1);
			}
			i++;
		}
		i = 0;
	}
	return (0);
}
