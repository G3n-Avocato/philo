/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:05:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/20 18:25:36 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init_utils(t_rules *rules)
{

	pthread_mutex_init(&rules->m_print, NULL);
	pthread_mutex_init(&rules->nb_philo_eat, NULL);
	pthread_mutex_init(&rules->death_mutex, NULL);
}

void	mutex_init_fork(t_data *data, t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.nb_of_philo)
	{
		pthread_mutex_init(&data[i].l_f, NULL);
		pthread_mutex_init(&data[i].start_e_mtx, NULL);
		i++;
	}
	i = 0;
	while (i < rules.nb_of_philo - 1)
	{
		data[i].r_f = &data[i + 1].l_f;
		i++;
	}
	data[i].r_f = &data[0].l_f;
}
