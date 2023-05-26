NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ./srclib/ft_isalpha.c ./srclib/ft_isdigit.c ./srclib/ft_isalnum.c ./srclib/ft_isascii.c ./srclib/ft_isprint.c ./srclib/ft_strlen.c ./srclib/ft_memset.c ./srclib/ft_bzero.c ./srclib/ft_memcpy.c ./srclib/ft_memmove.c ./srclib/ft_strlcpy.c ./srclib/ft_strlcat.c ./srclib/ft_toupper.c ./srclib/ft_tolower.c ./srclib/ft_strchr.c ./srclib/ft_strrchr.c ./srclib/ft_strncmp.c ./srclib/ft_memchr.c ./srclib/ft_memcmp.c ./srclib/ft_strnstr.c ./srclib/ft_atoi.c ./srclib/ft_calloc.c ./srclib/ft_strdup.c ./srclib/ft_substr.c ./srclib/ft_strjoin.c ./srclib/ft_strtrim.c ./srclib/ft_split.c ./srclib/ft_itoa.c ./srclib/ft_strmapi.c ./srclib/ft_striteri.c ./srclib/ft_putchar_fd.c ./srclib/ft_putstr_fd.c ./srclib/ft_putendl_fd.c ./srclib/ft_putnbr_fd.c ./srclib/ft_lstnew.c ./srclib/ft_lstadd_front.c ./srclib/ft_lstsize.c ./srclib/ft_lstlast.c ./srclib/ft_lstadd_back.c ./srclib/ft_lstdelone.c ./srclib/ft_lstclear.c ./srclib/ft_lstiter.c ./srclib/ft_lstmap.c

SRCPF = ./printf/ft_printf.c ./printf/ft_putchar_pf.c ./printf/ft_putnbr_base.c ./printf/ft_putnbr_size.c ./printf/ft_putstr_pf.c ./printf/ft_strlenpf.c ./printf/ft_pourcentage.c

SRCGNL = ./gnl/get_next_line_utils.c ./gnl/get_next_line.c

all : ${NAME}

OBJS = ${SRC:.c=.o} ${SRCPF:.c=.o} ${SRCGNL:.c=.o}

.c.o :
	@${CC} ${CFLAGS} -I libft.h -I get_next_line.h -I ft_printf.h  -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@ar rcs $@ ${OBJS}

clean :
	@rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
	@rm -f libft.a

re : fclean all

.PHONY: .c.o all clean fclean bonus re

