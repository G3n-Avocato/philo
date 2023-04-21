/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:47:59 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/21 19:33:00 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_data *data)
{
	long int	time;

	pthread_mutex_lock(&data->l_f);
	if (check_end(data) == 1)
	{
		pthread_mutex_lock(data->r_f);
		return ;
	}
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
	pthread_mutex_lock(data->r_f);
	if (check_end(data) == 1)
		return ;
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
}

void	ft_eat(t_data *data)
{
	long int	time;

	pthread_mutex_lock(&data->start_e_mtx);
	data->start_e = get_time();
	time = get_chrono(data->rules->start_s, data->start_e);
	pthread_mutex_unlock(&data->start_e_mtx);
	ft_print_status(data, time, "is eating");
	ft_usleep(data, data->rules->tto_eat);
	drop_forks(data);
	if (data->rules->nb_of_meal != -1)
	{
		data->count_meal += 1;
		if (data->count_meal == data->rules->nb_of_meal)
			ft_count_philo_ate(data);
	}
}

void	ft_sleep(t_data *data)
{
	long int	time;

	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "is sleeping");
	ft_usleep(data, data->rules->tto_sleep);
}

void	ft_think(t_data *data)
{
	long int	time;

	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "is thinking");
}
