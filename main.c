/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/04 18:20:16 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *data)
{
	(void) data;
	pthread_t tid;

	tid = pthread_self();
	//printf("  Routine    Thread [%ld]\n", tid);
	return (NULL);
}

int	ft_thread_create(t_data *data, t_rules rules)
{
	int	i;
	int	error;

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		error = pthread_create(&data[i].t_id, NULL, thread_routine, NULL);
		if (error != 0)
		{
			printf("Error create Thread %d\n", i);
			return (1);
		}
	//	printf("Creation %d Thread [%ld]\n", i, data[i].t_id);
		i++;
	}
	return (0);
}

int	ft_thread_join(t_data *data, t_rules rules)
{
	int i;
	int error;

	i = 0;
	while (i < rules.number_of_philosophers)
	{
		error = pthread_join(data[i].t_id, NULL);
		if (error != 0)
		{
			printf("Error join Thread %d\n", i);
			return (1);
		}
	//	printf("Union du %d Thread [%ld]\n", i, data[i].t_id);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_data	*data;
	int	error;

	rules = ft_init_rules(argc, argv);
	data = ft_init_struct_data(rules);
	error = ft_thread_create(data, rules);
	if (error == 1)
		return  (1);
	error = ft_thread_join(data, rules);
	if (error == 1)
		return (1);
	return (0);
}
