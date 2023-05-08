SRC 		= 	srcs/main.c \
				srcs/utils.c \
				srcs/mandelbrot.c \
				srcs/julia.c \
				srcs/utils_2.c \
				srcs/coloring.c \

NAME		= 	fractol
CC			= 	cc
FLAGS 		= 	-lmlx -framework OpenGL -framework AppKit
RM 			= 	rm -f
OBJS := $(SRC:.c=.o)
 
all:		$(NAME)

$(NAME):	$(OBJS) 
			$(CC) $(FLAGS)  $(SRC) -o $(NAME)

clean: 
			@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re