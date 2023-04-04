/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:44:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/04 18:21:34 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <string.h> //memset
# include <stdlib.h> //malloc
# include <unistd.h> //write usleep
# include <sys/time.h> //gettimeofday
# include <pthread.h> //thread

typedef struct s_rules{
	int		nb_of_philo;
	int		tto_die;
	int		tto_eat;
	int		tto_sleep;
	int		nb_of_meal;
}t_rules;

typedef struct s_data{
	pthread_t	t_id;
}t_data;

typedef struct s_mutex{
	pthread_mutex_t co_mut;
	unsigned int	count;
}t_mutex;

// init_rules
t_rules	ft_init_rules(int argc, char **argv);
int		ft_atoi(char *str);
int		ft_check_int(t_rules rules);
t_data	*ft_init_struct_data(t_rules rules);

#endif
