# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/09/06 09:31:54 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ray_tracing

SRC = main.c file_okay.c light.c ft_objects.c image.c rt_math.c rt_math1.c \
	  mem.c

OBJ = main.o file_okay.o light.o ft_objects.o image.o rt_math.o rt_math1.o \
	  mem.o

FLAGS = -Wall -Wextra -Werror 

FETCHLIB = -L libft/ -lft

MATHLIB = -lm

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/ all
	@gcc -g -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB) $(MATHLIB)

clean:
	@$(MAKE) -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re:	fclean all
