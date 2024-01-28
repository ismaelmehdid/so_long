# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:18:27 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/28 00:23:08 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ${wildcard srcs/errors_handling/*.c srcs/*.c srcs/render/*.c} \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I includes
LDFLAGS = -L includes/libft -L includes/minilibx-linux -L\
		includes/printf -lftprintf -lft -lmlx -lX11 -lXext -lbsd

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
		 @${MAKE} -C includes/libft
		 @${MAKE} -C includes/printf
		 @${MAKE} -C includes/minilibx-linux
		 @${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

clean:
		@${MAKE} clean -C includes/libft
		@${MAKE} clean -C includes/printf
		@${MAKE} clean -C includes/minilibx-linux
		@${RM} ${OBJS}

fclean: clean
		@${MAKE} fclean -C includes/libft
		@${MAKE} fclean -C includes/printf
		@${MAKE} clean -C includes/minilibx-linux
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re