# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 14:27:42 by lamasson          #+#    #+#              #
#    Updated: 2023/04/05 18:31:43 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS	=  -Wall -Wextra -Werror -fsanitize=thread -g

RM	= rm -rf

NAME	= philo

SRCS	= main.c \
		  ft_init_rules.c \
		  ft_init_mutex.c

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
