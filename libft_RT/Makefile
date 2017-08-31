# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/08/28 09:39:58 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ray_tracing

SRC = main.c file_handling.c

OBJ = main.o file_handling.o

FLAGS = -Wall -Wextra -Werror 

FETCHLIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/ all
	@gcc -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB)

clean:
	@$(MAKE) -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re:	fclean all
