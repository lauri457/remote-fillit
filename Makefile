# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:09:04 by lharkala          #+#    #+#              #
#    Updated: 2022/04/27 00:12:08 by lharkala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -Ilibft

SRCS = 	main.c \
		parser.c \
		valid.c \
		solver.c \
		map.c \
		utils.c

OBJS = $(SRCS:.c=.o)

LIB = libft

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJS) -I. -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	$(MAKE) -C ./$(LIB) re
	$(MAKE) -C ./$(LIB) clean

.PHONY: all clean fclean re
