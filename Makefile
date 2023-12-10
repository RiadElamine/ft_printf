# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relamine <relamine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 13:46:45 by relamine          #+#    #+#              #
#    Updated: 2023/12/09 12:30:21 by relamine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_hex.c ft_pointer.c ft_printf.c 

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean :
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all