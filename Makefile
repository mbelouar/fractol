SRC 		= 	src/main.c \
				src/utils.c \
				src/mandelbrot.c \
				src/julia.c \

NAME		= 	fractol
CC			= 	cc
CFLAGS 		= 	-lmlx -framework OpenGL -framework AppKit
RM 			= 	rm -f
OBJS := $(SRC:.c=.o)
 
all:		$(NAME)

$(NAME):	$(SRCS) 
			$(CC) $(CFLAGS)  $(SRCS) -o $(NAME)

clean: 
			@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re