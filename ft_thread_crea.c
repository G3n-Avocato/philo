/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_crea.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:52:36 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/22 14:31:27 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thread_create(t_rules rules)
{
	int	i;
	int	error;

	i = 0;
	while (i < rules.nb_of_philo)
	{
		error = pthread_create(&rules.data[i].t_id, NULL, thread_routine, \
				&rules.data[i]);
		if (error != 0)
		{
			printf("pthread_create: error thread %d\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_thread_join(t_data *data, t_rules *rules)
{
	int	i;
	int	error;

	i = 0;
	while (i < rules->nb_of_philo)
	{
		error = pthread_join(data[i].t_id, NULL);
		if (error != 0)
		{
			printf("pthread_join: error join thread %d\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}
