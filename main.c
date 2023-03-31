/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/31 19:19:56 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rules	ft_init_rules(int nop, double ttd, double tte, double tts)
{
	t_rules rules;

	rules.number_of_philosophers = nop;
	rules.time_to_die = ttd;
	rules.time_to_eat = tte;
	rules.time_to_sleep = tts;
	return (rules);
}

t_data	*ft_init_struct_data(t_rules rules)
{
	t_data *data;

	data = malloc(sizeof(t_data) * rules.number_of_philosophers);
	return (data);
}

void	*thread_routine(void *data)
{
	(void) data;
	pthread_t tid;

	tid = pthread_self();
	printf("  Routine    Thread [%ld]\n", tid);
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
		printf("Creation %d Thread [%ld]\n", i, data[i].t_id);
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
		printf("Union du %d Thread [%ld]\n", i, data[i].t_id);
		i++;
	}
	return (0);
}

int	main(void)
{
	t_rules	rules;
	t_data	*data;
	int	error;

	rules = ft_init_rules(10, 15, 5, 5);
	data = ft_init_struct_data(rules);
	error = ft_thread_create(data, rules);
	if (error == 1)
		return  (1);
	error = ft_thread_join(data, rules);
	if (error == 1)
		return (1);
	return (0);
}
