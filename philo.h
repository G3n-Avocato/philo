/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:44:41 by lamasson          #+#    #+#             */
/*   Updated: 2023/04/13 15:32:33 by lamasson         ###   ########.fr       */
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
	pthread_t		t_id;
	int				num_philo;
	pthread_mutex_t l_f;
	pthread_mutex_t	*r_f;
	int				count_meal;
	long int		start_e;	
	struct s_rules	*rules;
}t_data;

typedef struct s_rules{
	int			nb_of_philo;
	int			tto_die;
	int			tto_eat;
	int			tto_sleep;
	int			nb_of_meal;
	long int	start_s;
	int			nb_philo_ate;
	pthread_mutex_t m_print;
	pthread_mutex_t nb_philo_eat;
	t_data	*data;
}t_rules;

// init_rules
int		ft_init_rules(int argc, char **argv, t_rules *rules);
int		ft_parse_atoi(char *str);
t_data	*ft_init_struct_data(t_rules *rules);

//threah_crea
int	ft_thread_create(t_rules rules);
int	ft_thread_join(t_data *data, t_rules *rules);

//init_mutex
void	mutex_init_utils(t_rules *rules);
void	mutex_init_fork(t_data *data, t_rules rules);

//time.c
long int	get_time(void);
long int	get_chrono(long int start_s, long int end);
void		ft_print_status(t_data *data, long int time, char *str);

//thread_routine
void	*thread_routine(void *rul);
void	take_forks(t_data *data);
void	drop_forks(t_data *data);
void	ft_count_philo_ate(t_data *data);
void	ft_eat(t_data *data);
void	ft_sleep(t_data *data);
void	ft_think(t_data *data);

//quit
void	ft_end_simu(t_data *data, t_rules *rules);
void	ft_destroy_mutex_fork(t_data *data, t_rules *rules);
void	ft_destroy_mutex_utils(t_rules *rules);



#endif
