# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 14:27:42 by lamasson          #+#    #+#              #
#    Updated: 2023/04/13 13:40:35 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS	=  -Wall -Wextra -Werror -g

RM	= rm -rf

NAME	= philo

SRCS	= main.c \
		  ft_init_rules.c \
		  ft_init_mutex.c \
		  ft_thread_crea.c \
		  ft_state_philo.c \
		  ft_state.c \
		  ft_quit.c \
		  ft_time.c

OBJS	= ${SRCS:%.c=%.o}

LIBS	= -pthread

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
