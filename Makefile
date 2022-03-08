# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 15:03:25 by adubeau           #+#    #+#              #
#    Updated: 2022/03/05 16:42:33 by adubeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo

SRCS		= 	srcs/main.c \
				srcs/utils.c

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf
EXEC		= gcc -o
FLAGS		= -Wall -Werror -Wextra -c -g
INCS		= ./includes
CC			= gcc
CP			= cp

.c.o:
	$(CC) $(FLAGS) $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(EXEC) $(NAME) $(OBJS) $(LIB)

clean:
	@clear all
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM)

re: fclean all clean

.PHONY: all clean fclean re .c.o
