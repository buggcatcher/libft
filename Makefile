CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_strtrim.c ft_striteri.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c \
		ft_split.c 
	
#SRCSB =
OBJS = $(SRCS:.c=.o)
#OBJSB = $(SRCSB:.c=.o)
NAME = libft.a 
LIBC = ar rcs
RM = rm -f

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC}	${NAME}	${OBJS}


#bonus: ${NAME} ${OBJSB}
#	${LIBC} ${NAME} ${OBJSB}

clean:
	${RM}	${OBJS}	${OBJSB}

fclean: clean
	${RM}	${NAME}	${bonus}

re: fclean	all

.PHONY:	all	clean	bonus	fclean	re
