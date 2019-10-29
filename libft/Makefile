# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 17:30:23 by lzimmerm          #+#    #+#              #
#    Updated: 2019/08/26 16:14:48 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

SRC_NAME = ft_atoi.c ft_bzero.c ft_factorial.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c \
	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
	ft_putnbr_fd.c ft_putnbr.c ft_putstr.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_putstr_fd.c ft_count_words_c.c ft_intlen.c ft_lstcount.c \
	ft_lstsize.c ft_pow.c ft_swap.c ft_count_words.c ft_pos.c \
	ft_strjoin_left_free.c ft_atoi_advanced.c ft_strndup.c \
	ft_count_words_line_c.c ft_is_prime.c ft_find_next_prime.c


SRCS_PATH = ./
OBJS_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror
I_FLAG = -Iincludes

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c libft.h Makefile
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(I_FLAG) -o $@ -c $<

all : $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\033[32;1mlibft          [ OK! ]\033[0m\\n"

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "Libft directory is clean"

re : fclean all
