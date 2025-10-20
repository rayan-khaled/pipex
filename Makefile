# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 14:55:26 by rakhaled          #+#    #+#              #
#    Updated: 2025/10/07 11:59:09 by rakhaled         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        := pipex
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -I .

SRCS        := main.c ft_split.c path.c pipex.c utils1.c \
				pipex_utils.c  utils2.c 

OBJS        := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
