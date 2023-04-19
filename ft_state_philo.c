/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:20:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/19 18:43:44 by lamasson         ###   ########.fr       */
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
		routine(data);
		tmp = check_eat_philo(data);
	}
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

int		check_eat_philo(t_data *data)
{
	int	tmp;

	pthread_mutex_lock(&data->rules->nb_philo_eat);
	tmp = data->rules->nb_philo_ate;
	pthread_mutex_unlock(&data->rules->nb_philo_eat);
	return(tmp);
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
