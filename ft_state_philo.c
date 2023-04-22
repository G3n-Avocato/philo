/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:20:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/22 18:50:07 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *rul)
{
	t_data	*data;

	data = rul;
	if (data->rules->nb_of_philo == 1)
	{
		only_one(data);
		return (NULL);
	}
	if (data->num_philo % 2 == 0)
	{
		ft_think(data);
		usleep(1000);
	}
	while (check_eat_philo(data) != 1 && check_end(data) != 1)
		routine(data);
	return (NULL);
}

void	routine(t_data *data)
{
	take_forks(data);
	if (check_end(data) == 1)
	{
		drop_forks(data);
		return ;
	}
	ft_eat(data);
	if (check_end(data) == 1)
		return ;
	ft_sleep(data);
	if (check_end(data) == 1)
		return ;
	ft_think(data);
}

int	check_eat_philo(t_data *data)
{
	pthread_mutex_lock(&data->rules->nb_philo_eat);
	if (data->rules->nb_philo_ate == data->rules->nb_of_philo)
	{
		pthread_mutex_unlock(&data->rules->nb_philo_eat);
		return (1);
	}
	pthread_mutex_unlock(&data->rules->nb_philo_eat);
	return (0);
}

void	drop_forks(t_data *data)
{
	pthread_mutex_unlock(&data->l_f);
	pthread_mutex_unlock(data->r_f);
}

void	ft_count_philo_ate(t_data *data)
{
	pthread_mutex_lock(&data->rules->nb_philo_eat);
	data->rules->nb_philo_ate += 1;
	pthread_mutex_unlock(&data->rules->nb_philo_eat);
}
