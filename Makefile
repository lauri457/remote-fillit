# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:09:04 by lharkala          #+#    #+#              #
#    Updated: 2022/04/07 11:16:13 by lharkala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_fillit

FLAGS = -Wall -Wextra -Werror -Ilibft/inc

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIB = libft

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	gcc -O3 $(FLAGS) $(OBJS) -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	$(MAKE) -C ./$(LIB) re
	$(MAKE) -C ./$(LIB) clean

.PHONY: all clean fclean re