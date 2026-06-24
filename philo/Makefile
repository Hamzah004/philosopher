# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <hbani-at@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 19:52:29 by hbani-at          #+#    #+#              #
#    Updated: 2026/06/21 18:37:39 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[0;34m
OK_COLOR    = \033[0;32m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
COM_STRING   = "Compiling"

CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra

NAME = philo
SRC = 	main.c \
	error.c \
	init.c \
	time.c \
	print.c \
	routine.c \
	monitoring.c \
	cleanup.c \
	utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(OK_COLOR)$(OK_STRING) philo excutable cerated\n$(NO_COLOR)"

%.o : %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $<\n$(NO_COLOR)"

clean:
	@rm -f $(OBJS)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) philo Object files cleaned\n$(NO_COLOR)";

fclean: clean
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) philo executable cleaned\n$(NO_COLOR)"

re: fclean all

gdb: $(NAME)
	gdb -tui ./$(NAME)

.PHONY: all clean fclean re
