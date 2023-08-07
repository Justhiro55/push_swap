# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 17:24:52 by hhagiwar          #+#    #+#              #
#    Updated: 2023/08/07 15:09:31 by hhagiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = algorithm.c check_atoi.c compress.c error.c exec.c free.c push_swap.c stack.c utils_alg.c \
		func/libft/ft_isalpha.c \
		func/libft/ft_isdigit.c \
		func/libft/ft_isalnum.c \
		func/libft/ft_isascii.c \
		func/libft/ft_isprint.c \
		func/libft/ft_strlen.c \
		func/libft/ft_memset.c \
		func/libft/ft_bzero.c \
		func/libft/ft_memcpy.c \
		func/libft/ft_memmove.c \
		func/libft/ft_strlcpy.c \
		func/libft/ft_strlcat.c \
		func/libft/ft_toupper.c \
		func/libft/ft_tolower.c \
		func/libft/ft_strchr.c \
		func/libft/ft_strrchr.c \
		func/libft/ft_strncmp.c \
		func/libft/ft_strnstr.c \
		func/libft/ft_memchr.c \
		func/libft/ft_memcmp.c \
		func/libft/ft_atoi.c \
		func/libft/ft_itoa.c \
		func/libft/ft_calloc.c \
		func/libft/ft_strdup.c \
		func/libft/ft_substr.c \
		func/libft/ft_strjoin.c \
		func/libft/ft_strtrim.c \
		func/libft/ft_strmapi.c \
		func/libft/ft_striteri.c \
		func/libft/ft_putchar_fd.c \
		func/libft/ft_putstr_fd.c \
		func/libft/ft_putendl_fd.c \
		func/libft/ft_putnbr_fd.c \
		func/libft/ft_split.c \
		func/ft_printf/ft_printf.c \
		func/ft_printf/ft_putchar_printf.c \
		func/ft_printf/ft_putnbr_p.c \
		func/ft_printf/ft_putnbr.c \
		func/ft_printf/ft_putstr_printf.c \
		func/ft_printf/ft_strlen.c

OBJS = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
# LIBC  = ar rc

# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${RMFLAGS} ${OBJS}
    
fclean: clean
	${RM} ${RMFLAGS} ${NAME}
re: fclean all

.PHONY: bonus all clean fclean re
