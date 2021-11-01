# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malatini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:14:41 by malatini          #+#    #+#              #
#    Updated: 2021/07/23 18:10:31 by malatini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	clang
OBJDIR	=	objects
SRC		=	philosophers.c atoi.c print.c routine.c check_args.c timer.c init.c
OBJ 	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror -pthread

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${GREEN}Compilation Done${RESET}"

$(OBJDIR)/%.o: %.c
	@mkdir -p objects
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
