/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:24 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/13 15:32:18 by lamasson         ###   ########.fr       */
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
	mutex_init_utils(&rules);
	rules.data = data;
	error = ft_thread_create(rules);
	if (error == 1)
		return (1);
	ft_end_simu(data, &rules);
	return (0);
}
