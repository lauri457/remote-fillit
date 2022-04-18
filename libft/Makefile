# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 13:06:34 by lharkala          #+#    #+#              #
#    Updated: 2022/04/07 11:16:43 by lharkala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -O3

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC =	mem/v_set.c \
		mem/v_bzero.c \
		mem/v_cpy.c \
		mem/v_chr.c \
		mem/v_ccpy.c \
		mem/v_move.c \
		mem/v_cmp.c \
		mem/v_alloc.c \
		mem/v_del.c \
		mem/v_calloc.c \
		str/s_len.c \
		str/s_dup.c \
		str/s_cpy.c \
		str/s_ncpy.c \
		str/s_cat.c \
		str/s_ncat.c \
		str/s_lcat.c \
		str/s_chr.c \
		str/s_rchr.c \
		str/s_cmp.c \
		str/s_ncmp.c \
		str/s_str.c \
		str/s_nstr.c \
		str/s_lcpy.c \
		str/s_new.c \
		str/s_del.c \
		str/s_clr.c \
		str/s_iter.c \
		str/s_iteri.c \
		str/s_map.c \
		str/s_mapi.c \
		str/s_equ.c \
		str/s_nequ.c \
		str/s_sub.c \
		str/s_join.c \
		str/s_trim.c \
		str/s_split.c \
		int/c_itoa.c \
		int/c_atoi.c \
		chars/is_upper.c \
		chars/is_lower.c \
		chars/is_alpha.c \
		chars/is_digit.c \
		chars/is_alnum.c \
		chars/is_ascii.c \
		chars/is_print.c \
		chars/is_space.c \
		chars/c_toupper.c \
		chars/c_tolower.c \
		io/fd_putchar.c \
		io/fd_putstr.c \
		io/fd_putendl.c \
		io/fd_putnbr.c \
		io/fd_getline.c \
		list/l_new.c \
		list/l_delone.c \
		list/l_del.c \
		list/l_add.c \
		list/l_iter.c \
		list/l_map.c \

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))
INDEX		=	0

all :
	@$(MAKE) $(NAME)

$(NAME) :		$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "make $(NAME)\n"

$(DIR) :
	@mkdir -p $@

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(DIR)
	@$(CC) $(FLAGS) -c $< -o $@\
		-I $(INC_DIR)

clean :
	@if [ -d $(OBJ_DIR) ]; \
	then \
		rm -rf $(OBJ_DIR); \
		printf "clean $(NAME)\n"; \
	fi;

fclean :		clean
	@if [ -e $(NAME) ]; \
	then \
		rm -rf $(NAME); \
		printf "fclean $(NAME)\n"; \
	fi;

re :			fclean
	@$(MAKE) $(NAME)

.PHONY :		fclean clean re