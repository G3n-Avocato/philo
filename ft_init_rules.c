/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:25:37 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/20 16:19:36 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_rules(int argc, char **argv, t_rules *rules)
{
	int	tab[4];
	int	i;
	
	i = 0;
	if (argc == 6)
		rules->nb_of_meal = ft_parse_atoi(argv[5]);
	if (argc == 6 && rules->nb_of_meal <= 0)
		return (-1);
	while (i < 4)
	{
		tab[i] = ft_parse_atoi(argv[i + 1]);
		if (tab[i] <= 0)
			return (-1);
		i++;
	}
	rules->nb_of_philo = tab[0];
	rules->tto_die = tab[1];
	rules->tto_eat = tab[2];
	rules->tto_sleep = tab[3];
	if (argc < 6)
		rules->nb_of_meal = -1;
	rules->nb_philo_ate = 0;
	rules->death = 0;
	return (0);
}

int	ft_parse_atoi(char *str)
{
	long long	nb;

	nb = 0;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		nb *= 10;
		nb += *str - 48;
		if (nb > 2147483647)
			return (-1);
		str++;
	}
	return ((int)nb);
}

t_data	*ft_init_struct_data(t_rules *rules)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data) * rules->nb_of_philo);
	if (data == NULL)
		return (NULL);
	while (i < rules->nb_of_philo)
	{
			data[i].rules = rules;
			data[i].count_meal = 0;
			data[i].start_e = 0;
			i++;
			data[i - 1].num_philo = i;
	}
	return (data);
}
