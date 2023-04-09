/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:13:11 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/08 12:34:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(t_data *data, t_rules rules)
{
	ft_thread_join(data, rules);
	ft_destroy_mutex_utils(data, rules);
	ft_destroy_mutex_fork(data, rules);
	free(data);
}

void	ft_destroy_mutex_fork(t_data *data, t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.nb_of_philo)
	{
		pthread_mutex_destroy(&data[i].l_f);
		i++;
	}
}

void	ft_destroy_mutex_utils(t_data *data, t_rules rules)
{
	pthread_mutex_destroy(data->m_print);
	pthread_mutex_destroy(data->nb_philo_eat);
}
