/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:20:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/18 21:24:02 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *rul)
{
	t_data *data;
	int		tmp;

	data = rul;
	if (data->num_philo % 2 == 0)
	{
		if (usleep(1000) != 0)
			data->rules->error = 1;
	}
	tmp = check_eat_philo(data);	
	while (tmp != data->rules->nb_of_philo && data->rules->error != 1)
	{
		routine(data);
		tmp = check_eat_philo(data);
	}
	return (NULL);
}

void	routine(t_data *data)
{
	take_forks(data);
	if (data->rules->error == 1)
	{
		pthread_mutex_unlock(&data->l_f);
		return ;
	}
	ft_eat(data);
	if (data->rules->error == 1)
		return ;
	ft_sleep(data);
	if (data->rules->error == 1)
		return ;
	ft_think(data);
}

int		check_eat_philo(t_data *data)
{
	int	tmp;

	if (pthread_mutex_lock(&data->rules->nb_philo_eat) != 0)
		data->rules->error = 1;
	tmp = data->rules->nb_philo_ate;
	if (pthread_mutex_unlock(&data->rules->nb_philo_eat) != 0)
		data->rules->error = 1;
	return(tmp);
}

void	take_forks(t_data *data)
{
	long int	time;

//	if (pthread_mutex_lock(&data->l_f) != 0)
	pthread_mutex_lock(&data->l_f);
	if (1)
	{
		data->rules->error = 1;
		return ;
	}
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
	if (pthread_mutex_lock(data->r_f) != 0)
	{
		data->rules->error = 1;
		return ;
	}
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
}

void	drop_forks(t_data *data)
{
	if (pthread_mutex_unlock(&data->l_f) != 0)
		data->rules->error = 1;
	if (pthread_mutex_unlock(data->r_f) != 0)
		data->rules->error = 1;
}

void	ft_count_philo_ate(t_data *data)
{
	if (pthread_mutex_lock(&data->rules->nb_philo_eat) != 0)
		data->rules->error = 1;
	data->rules->nb_philo_ate += 1;
	if (pthread_mutex_unlock(&data->rules->nb_philo_eat) != 0)
		data->rules->error = 1;
}

void	ft_eat(t_data *data)
{
	long int	time;

	data->start_e = get_time();
	time = get_chrono(data->rules->start_s, data->start_e);
	ft_print_status(data, time, "is eating");
	if (usleep(data->rules->tto_eat * 1000) != 0)
		data->rules->error = 1;
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
	if (usleep(data->rules->tto_sleep * 1000) != 0)
		data->rules->error = 1;
}

void	ft_think(t_data *data)
{
	long int	start_t;
	long int	time;

	start_t = get_time();
	time = get_chrono(data->rules->start_s, start_t);
	ft_print_status(data, time, "is thinking");
}
