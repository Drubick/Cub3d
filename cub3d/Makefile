NAME				= cub_3d

FOLDER				= src/

SRCS 			=  main.c\
					parse.c\
					array_parse.c\
					array_parse_map.c

OBJS				= ${SRCS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -Ilibft -fsanitize=address -I../libft -I.

RM					= rm -f

$(NAME):	${OBJS}
			cd libft && make
			#$(CC) $(CFLAGS) ${OBJ} libft/libft.a 
			$(CC) $(CFLAGS) ${OBJS} libft/libft.a 

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
			${RM} so_long
			${RM} libmlx.dylib

.PHONY: 	all clean fclean re