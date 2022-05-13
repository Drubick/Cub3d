NAME				= cub_3d

FOLDER				= src/

SRCS 			=  main.c\
					parse.c\
					memory.c\
					array_parse.c\
					array_parse_aux.c\
					array_parse_map.c\
					array_parse_map_aux.c\
					Ray_casting/calculation_aux.c\
					Ray_casting/Calculations.c\
					Ray_casting/draw3D.c\
					Ray_casting/file1.c\
					Ray_casting/mlx_aux.c\
					Ray_casting/mlx_keys.c\
					array_parse_aux_2.c\
					memory_2.c\
					rendering.c

OBJS				= main.o\
					parse.o\
					memory.o\
					parse_aux.o\
					array_parse.o\
					array_parse_aux.o\
					array_parse_map.o\
					array_parse_map_aux.o\
					Ray_casting/calculation_aux.o\
					Ray_casting/Calculations.o\
					Ray_casting/draw3D.o\
					Ray_casting/file1.o\
					Ray_casting/mlx_aux.o\
					Ray_casting/mlx_keys.o\
					array_parse_aux_2.o\
					memory_2.o\
					rendering.o

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -Ilibft -I../libft -I.

RM					= rm -f

$(NAME):	${OBJS}
			cd libft && make
			#$(CC) $(CFLAGS) ${OBJ} libft/libft.a -l mlx -framework OpenGL -framework AppKit -o $(NAME)
			$(CC) $(CFLAGS) ${OBJS} libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		${NAME}

re: 		fclean all

clean:
			${RM} $(OBJS_COMU) $(OBJS_BONUS) $(OBJS)
			cd libft && make clean
			cd minilibx && make clean

fclean:		
			${RM} $(OBJS_COMU) $(OBJS)
			cd libft && make fclean
			cd minilibx && make clean
			${RM} ${NAME}
			${RM} libmlx.dylib

.PHONY: 	all clean fclean re