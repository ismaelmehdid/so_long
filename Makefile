# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:18:27 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/19 20:06:19 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ${wildcard srcs/errors_handling/*.c srcs/*.c} \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I includes

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
		 @${MAKE} -C includes/libft
		 @${CC} ${CFLAGS} ${OBJS} includes/libft/libft.a -o ${NAME}

clean:
		@${MAKE} clean -C includes/libft
		@${RM} ${OBJS}

fclean: clean
		@${MAKE} fclean -C includes/libft
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re