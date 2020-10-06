SRCS	= ./srcs/main.c ./srcs/displayer.c ./srcs/store_map.c ./srcs/list_util.c ./srcs/string_util.c ./srcs/parse_util1.c ./srcs/map_validation.c ./srcs/stdin_map.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}


all : ${NAME}
	${RM} ${OBJS}

run :
	./${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}
