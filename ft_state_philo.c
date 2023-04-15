/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:20:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/15 18:28:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *rul)
{
	t_data *data;
	int		tmp;

	data = rul;
	if (data->num_philo % 2 == 0)
		usleep(1000);
	tmp = check_eat_philo(data);	
	while (tmp != data->rules->nb_of_philo)
	{
		take_forks(data);
		ft_eat(data);
		ft_sleep(data);
		ft_think(data);
		tmp = check_eat_philo(data);
	}
	return (NULL);
}

int		check_eat_philo(t_data *data)
{
	int	tmp;

	if (pthread_mutex_lock(&data->rules->nb_philo_eat) != 0)
		ft_error(data);
	tmp = data->rules->nb_philo_ate;
	if (pthread_mutex_unlock(&data->rules->nb_philo_eat) != 0)
		ft_error(data);
	return(tmp);
}

void	take_forks(t_data *data)
{
	int			error;
	long int	time;

	error = pthread_mutex_lock(&data->l_f);
	ft_error(data);
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
	error = pthread_mutex_lock(data->r_f);
	if (error != 0)
		ft_error(data);
	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "has taken a fork");
}

void	drop_forks(t_data *data)
{
	int error;

	error = pthread_mutex_unlock(&data->l_f);
	if (error != 0)
		ft_error(data);
	error = pthread_mutex_unlock(data->r_f);
	if (error != 0)
		ft_error(data);
}

void	ft_count_philo_ate(t_data *data)
{
	int	error;
	
	error = pthread_mutex_lock(&data->rules->nb_philo_eat);
	if (error != 0)
		ft_error(data);
	data->rules->nb_philo_ate += 1;
	error = pthread_mutex_unlock(&data->rules->nb_philo_eat);
	if (error != 0)
		ft_error(data);
}

void	ft_eat(t_data *data)
{
	int	error;
	long int	time;

	data->start_e = get_time();
	time = get_chrono(data->rules->start_s, data->start_e);
	ft_print_status(data, time, "is eating");
	error = usleep(data->rules->tto_eat * 1000);
	if (error != 0)
		ft_error(data);
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
	int			error;

	time = get_chrono(data->rules->start_s, get_time());
	ft_print_status(data, time, "is sleeping");
	error = usleep(data->rules->tto_sleep * 1000);
	if (error != 0)
		ft_error(data);
}

void	ft_think(t_data *data)
{
	long int	start_t;
	long int	time;

	start_t = get_time();
	time = get_chrono(data->rules->start_s, start_t);
	ft_print_status(data, time, "is thinking");
}
