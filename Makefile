# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 07:44:44 by mbelouar          #+#    #+#              #
#    Updated: 2023/05/10 07:44:44 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

SRC = srcs/main.c \
      srcs/mandelbrot.c \
      srcs/julia.c \
      srcs/utils.c \
      srcs/zoom_close_esc.c \
      srcs/ft_atoif.c \
      srcs/coloring.c

NAME = fractol
CC = cc
FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(RED)Compiling fractol...$(RESET)"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)Compilation complete$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
