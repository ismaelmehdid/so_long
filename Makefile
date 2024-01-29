# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismaelmehdid <ismaelmehdid@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:18:27 by ismaelmehdi       #+#    #+#              #
#    Updated: 2024/01/28 13:41:12 by ismaelmehdi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = ${wildcard srcs/errors_handling/*.c srcs/*.c srcs/render/*.c} \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c

SRCS_BONUS = ${wildcard srcs_bonus/errors_handling_bonus/*.c srcs_bonus/*.c \
		srcs_bonus/render_bonus/*.c} \
		includes/get_next_line/get_next_line.c \
		includes/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

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

${NAME_BONUS}: ${OBJS_BONUS}
		 @${MAKE} -C includes/libft
		 @${MAKE} -C includes/printf
		 @${MAKE} -C includes/minilibx-linux
		 @${CC} ${CFLAGS} ${OBJS_BONUS} ${LDFLAGS} -o ${NAME_BONUS}

clean:
		@${MAKE} clean -C includes/libft
		@${MAKE} clean -C includes/printf
		@${MAKE} clean -C includes/minilibx-linux
		@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		@${MAKE} fclean -C includes/libft
		@${MAKE} fclean -C includes/printf
		@${MAKE} clean -C includes/minilibx-linux
		@${RM} ${NAME} ${OBJS} ${NAME_BONUS} ${OBJS_BONUS}

re: fclean all

bonus: ${NAME_BONUS}

.PHONY: all clean fclean re