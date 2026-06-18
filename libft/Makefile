# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amufleh <amufleh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 11:18:27 by amufleh           #+#    #+#              #
#    Updated: 2026/06/18 01:55:11 by hbani-at         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# ----------------------------- output colors ------------------------------- #
COM_COLOR	= \033[0;34m
OK_COLOR	= \033[0;32m
NO_COLOR	= \033[m
COM_STRING	= Compiling
OK_STRING	= [OK]

# ------------------------------- sources ----------------------------------- #
SRC =	ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
	ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_strtrim.c \
	ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
	ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
	ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c \
	ft_toupper.c ft_strndup.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
	ft_strjoin.c ft_strnstr.c ft_split.c ft_strcmp.c ft_atol.c

BONUS =	ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c \
	ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# -------------------------------- rules ------------------------------------ #
all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) libft.a created\n$(NO_COLOR)"

bonus: $(BONUS_OBJ)
	@$(AR) $(NAME) $(BONUS_OBJ)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) libft bonus added\n$(NO_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $<\n$(NO_COLOR)"

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) libft object files cleaned\n$(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING) libft.a cleaned\n$(NO_COLOR)"

re: fclean all

.PHONY: all bonus clean fclean re
