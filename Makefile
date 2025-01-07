NAME		=	pipex

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

INCLUDES	=	-I./includes

SRCS		=	main.c \
				srcs/env/core.c \
				srcs/fork/core.c \
				srcs/libft/ft_free_tbl.c \
				srcs/libft/ft_split.c \
				srcs/libft/ft_strdup.c \
				srcs/libft/ft_strjoin.c \
				srcs/libft/ft_strlcpy.c \
				srcs/libft/ft_strlen.c \
				srcs/libft/ft_strncmp.c \
				srcs/libft/ft_substr.c \

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re