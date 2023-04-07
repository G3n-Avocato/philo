/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/07 18:19:49 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	t_rules		rules;
	t_data		*data;
	int			error;

	rules.start_s = get_time();
	if (ft_parse_arg(argc, argv, &rules) == 1)
		return (1);
	data = ft_init_struct_data(&rules); 
	if (data == NULL)
		return (1);
	mutex_init_fork(data, rules);
	mutex_init_print(data, rules);
	if (rules.nb_of_meal != -1)
		mutex_init_nb_meal(data, rules);
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
