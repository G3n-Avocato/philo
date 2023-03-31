/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:44:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/03/31 18:47:52 by lamasson         ###   ########.fr       */
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
	int	number_of_philosophers;
	double	time_to_die;
	double	time_to_eat;
	double	time_to_sleep;
}t_rules;

typedef struct s_data{
	pthread_t	t_id;
}t_data;

#endif
