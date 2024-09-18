# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:14:41 by malatini          #+#    #+#              #
#    Updated: 2023/10/13 18:50:43 by mahautlatin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	clang
OBJDIR	=	objects

SRC		=	./srcs/main.c \
 			./srcs/philosophers.c \
            ./srcs/atoi.c \
            ./srcs/print.c \
            ./srcs/routine.c \
            ./srcs/check_args.c \
            ./srcs/timer.c \
            ./srcs/init.c 

OBJ 	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -pthread #-fsanitize=thread for race conditions

ifneq (,$(findstring xterm,${TERM}))
			GREEN := $(shell tput -Txterm setaf 2)
			RESET := $(shell tput -Txterm sgr0)
else
			GREEN := ""
			RESET := ""
endif

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./include/

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I./include/ -L./libftprintf/ -lftprintf

all: 		$(NAME)

clean:
			@rm -rf $(OBJ)

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all

bonus: 		all

.PHONY: 	clean fclean all re bonus
