/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:44:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/06 16:53:07 by lamasson         ###   ########.fr       */
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

typedef struct s_data{
	pthread_t	t_id;
	pthread_mutex_t l_f;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*m_print;
	struct s_rules	*rules;
}t_data;

typedef struct s_rules{
	int		nb_of_philo;
	int		tto_die;
	int		tto_eat;
	int		tto_sleep;
	int		nb_of_meal;
	t_data	*data;
}t_rules;

// init_rules
int		ft_init_rules(int argc, char **argv, t_rules *rules);
int		ft_parse_atoi(char *str);
t_data	*ft_init_struct_data(t_rules *rules);

//threah_crea
int	ft_thread_create(t_rules rules);

//init_mutex
void	mutex_init_print(t_data *data, t_rules rules);
void	mutex_init_fork(t_data *data, t_rules rules);

#endif
