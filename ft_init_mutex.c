/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:05:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/07 17:53:16 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init_print(t_data *data, t_rules rules)
{
	pthread_mutex_t	m_print;
	int		i;

	i = 0;
	pthread_mutex_init(&m_print, NULL);
	while (i < rules.nb_of_philo)
	{
		data[i].m_print = &m_print;
		i++;
	}
}

void	mutex_init_nb_meal(t_data *data, t_rules rules)
{
	pthread_mutex_t	nb_philo_eat;
	int				i;

	i = 0;
	pthread_mutex_init(&nb_philo_eat, NULL);
	while (i < rules.nb_of_philo)
	{
		data[i].nb_philo_eat = &nb_philo_eat;
		i++;
	}
}

void	mutex_init_fork(t_data *data, t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.nb_of_philo)
	{
		pthread_mutex_init(&data[i].l_f, NULL);
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
