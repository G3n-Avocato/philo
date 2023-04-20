/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:41:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/20 18:25:30 by lamasson         ###   ########.fr       */
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
	else
	{
		pthread_mutex_unlock(&data->rules->death_mutex);
		return (0);
	}
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

int	start_death_simu(t_data data)
{
	int	time_s;

	if (data.count_meal == 0)
	{
		time_s = get_chrono(data.rules->start_s, get_time());
		if (time_s >= data.rules->tto_die)
			return (1);
	}
	return (0);
}

int	death(t_data *data)
{
	int	i;
	int	time_e;
	int	time_s;

	i = 0;
	while (i < data->rules->nb_of_philo)
	{
		pthread_mutex_lock(&data[i].start_e_mtx);
		time_e = get_chrono(data[i].start_e, get_time());
		time_s = start_death_simu(data[i]);
		pthread_mutex_unlock(&data[i].start_e_mtx);
		if (time_e >= data[i].rules->tto_die || time_s == 1)
		{
			philo_death(&data[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
