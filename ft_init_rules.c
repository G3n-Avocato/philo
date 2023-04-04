/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:25:37 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/04 18:20:02 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rules	ft_init_rules(int argc, char **argv)
{
	t_rules	rules;

	rules.nb_of_philo = ft_atoi(argv[1]);
	rules.tto_die = ft_atoi(argv[2]);
	rules.tto_eat = ft_atoi(argv[3]);
	rules.tto_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		rules.nb_of_meal = ft_atoi(argv[5]);
	if (ft_check_int(rules) == -1)
		return (NULL); //gestion erreur fausse
	return (rules);
}

t_data	*ft_init_struct_data(t_rules rules)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * rules.nb_of_philo);
	return (data);
}
