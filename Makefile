# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 15:57:54 by qbragard          #+#    #+#              #
#    Updated: 2019/08/26 16:14:46 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, $(NAME), $(NAME2)

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

# ****************************     LEM_IN       ****************************** #
# ********************************         *********************************** #

NAME       = lem-in
SRCS_PATH  = srcs/lem_in/
OBJS_PATH  = objs/lem_in/
SRC_NAME   = ants.c checker.c hash.c links.c main.c parser.c bfs1.c \
							bfs_utils.c send_ants.c ants_utils.c bfs2.c bfs3.c \
							send_ants_utils.c links_utils.c parser_utils.c
OBJ_NAME   = $(SRC_NAME:.c=.o)
SRCS       = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS       = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

# ******************************    VIEWER     ******************************* #

NAME2       = viewer
SRCS2_PATH  = srcs/viewer/
OBJS2_PATH  = objs/viewer/
SRC2_NAME   = main.c parser.c checker.c hash.c links.c links_utils.c \
			parser_utils.c viewer.c text.c text1.c text2.c \
			sdl_operations.c sdl_operations1.c sdl_operations2.c \
			viewer_helper.c
OBJ2_NAME   = $(SRC2_NAME:.c=.o)
SRCS2       = $(addprefix $(SRCS2_PATH),$(SRC2_NAME))
OBJS2       = $(addprefix $(OBJS2_PATH),$(OBJ2_NAME))


# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

CC      = gcc -Iincludes
CFLAGS  = -Wall -Wextra -Werror
VFLAGS		= -F ~/Library/Frameworks/ -framework SDL2 -F ~/Library/Frameworks/ -framework SDL2_ttf
LIBFT = libft/libft.a


all : $(NAME) $(NAME2)
$(LIBFT) : FORCE
	@make -C libft

# ****************************      LEM_IN      ****************************** #

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c includes/lem_in.h Makefile
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "$(NAME) -- $<\\r"

$(NAME) : $(LIBFT) $(OBJS)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $(LIBFT) $^ -o $(NAME)
	@printf "\033[32;1m$(NAME)         [ OK! ]\033[0m\\n"

# ******************************    VIEWER     ******************************* #

$(OBJS2_PATH)%.o : $(SRCS2_PATH)%.c includes/viewer.h Makefile
	@mkdir -p $(OBJS2_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "$(NAME2) -- $<\\r"

$(NAME2) : $(LIBFT) $(OBJS2)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $(LIBFT) $(VFLAGS)  $^ -o $(NAME2)
	@printf "\033[32;1m$(NAME2)         [ OK! ]\033[0m\\n"


# **************************************************************************** #
#                                  COMMANDS                                    #
# **************************************************************************** #



FORCE :

clean :
	@rm -rf objs
	@make clean -sC libft
	@printf "make: cleaning objs\\n"

fclean : clean
	@rm -rf $(NAME) $(NAME2)
	@make fclean -sC libft
	@printf "make: cleaning programs\\n"

re : fclean all
