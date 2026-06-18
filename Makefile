# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 19:52:29 by hbani-at          #+#    #+#              #
#    Updated: 2026/06/18 01:54:53 by hbani-at         ###   ########.fr        #
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
	error.c

OBJS = $(SRC:.c=.o)

LIBFT_DIR		= ./libft
LIBFT_A			= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@printf "$(OK_COLOR)$(OK_STRING) philo excutable cerated\n$(NO_COLOR)"

$(LIBFT_A):
	@make --no-print-directory -C $(LIBFT_DIR) all bonus
	@printf "%b" "$(OK_COLOR)$(OK_STRING) libft archive created\n$(NO_COLOR)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $<\n$(NO_COLOR)"

clean:
	@rm -f $(OBJS)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) philo Object files cleaned\n$(NO_COLOR)";
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) philo executable cleaned\n$(NO_COLOR)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
