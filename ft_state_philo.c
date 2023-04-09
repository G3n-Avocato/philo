/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:20:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/09 16:50:14 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *rul)
{
	t_data *data;

	data = rul;
	while (data->rules->nb_philo_ate != data->rules->nb_of_meal)
	{
		take_forks(data);
		ft_eat(data);
		drop_forks(data);
		ft_sleep(data);
		ft_think(data);
	}
	return (NULL);
}

void	take_forks(t_data *data)
{
	int			error;
	long int	start_f;
	long int	time;

	start_f = get_time();
	error = pthread_mutex_lock(&data->l_f);
//	if (error != 0)
//		ft_error();
	time = get_chrono(data->rules->start_s, start_f);
	ft_print_status(data, time, "has taken a fork");
	start_f = get_time();
	error = pthread_mutex_lock(data->r_f);
//	if (error != 0)
//		ft_error();
	time = get_chrono(data->rules->start_s, start_f);
	ft_print_status(data, time, "has taken a fork");
}

void	drop_forks(t_data *data)
{
	int error;

	error = pthread_mutex_unlock(&data->l_f);
//	if (error != 0)
//		ft_error();
	error = pthread_mutex_unlock(data->r_f);
//	if (error != 0)
//		ft_error();
}

void	ft_count_philo_ate(t_data *data)
{
	int	error;
	
	error = pthread_mutex_lock(data->nb_philo_eat);
//	if (error != 0)
//		ft_error();
	data->rules->nb_philo_ate += 1;
	error = pthread_mutex_unlock(data->nb_philo_eat);
//	if (error != 0)
//		ft_error();
}

void	ft_eat(t_data *data)
{
	int	error;
	long int	time;

	data->start_e = get_time();
	time = get_chrono(data->rules->start_s, data->start_e);
	ft_print_status(data, time, "is eating");
	error = usleep(data->rules->tto_eat);
//	if (error != 0)
//		ft_error();
	if (data->rules->nb_of_meal != -1)
	{
		data->count_meal += 1;
		if (data->count_meal == data->rules->nb_of_meal)
			ft_count_philo_ate(data);
	}
}

void	ft_sleep(t_data *data)
{
	long int	start_sl;
	long int	time;
	int			error;

	start_sl = get_time();
	time = get_chrono(data->rules->start_s, start_sl);
	ft_print_status(data, time, "is sleeping");
	error = usleep(data->rules->tto_sleep);

}

void	ft_think(t_data *data)
{
	long int	start_t;
	long int	time;

	start_t = get_time();
	time = get_chrono(data->rules->start_s, start_t);
	ft_print_status(data, time, "is thinking");
}
/*

prendre une fouchette
prendre une autre fourchette 
manger
poser les 2 fourchettes 
dors
penser (print dormir)

recoder ft_usleep
variable partager entre thread doivent etre protoger par mutex

2eme partie erif mort
*/
