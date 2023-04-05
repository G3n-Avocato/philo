/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/05 20:00:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
void	*thread_routine(void *data)
{
	(void) data;
	pthread_t tid;

	tid = pthread_self();
	//printf("  Routine    Thread [%ld]\n", tid);
	return (NULL);
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
*/

static int	ft_parse_arg(int argc, char **argv, t_rules *rules)
{
	int	error;

	error = 0;
	if (argc < 5 || argc > 6) 
	{
		printf("Too few/many arguments!\n");
		return (1);
	}
	error = ft_init_rules(argc, argv, rules);
	if (error == -1)
	{
		printf("Wrong Argument!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_data	*data;
	int		error;

	if (ft_parse_arg(argc, argv, &rules) == 1)
		return (1);
	data = ft_init_struct_data(rules); 
	if (data == NULL)
		return (1);
	mutex_init_fork(data, rules);
	mutex_init_print(data, rules);
	rules.data = data;
	error = ft_thread_create(rules);
	if (error == 1)
		return (1);
/*
	int	i = 0;
	while (i < rules.nb_of_philo)
	{
		printf("%d = l_f [%p] = r_f [%p] m_print = [%p]\n", i, &data[i].l_f, data[i].r_f, data[i].m_print);
		i++;
	}
*/

//	error = ft_thread_create(data, rules);
//	if (error == 1)
//		return  (1);
//	error = ft_thread_join(data, rules);
//	if (error == 1)
//		return (1);
	return (0);
}
