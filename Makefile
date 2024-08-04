CC = gcc
CFLAGS = -Wall -Wextra -Werror 
MLXFLAGS = -lmlx -lXext -lX11 -lm

NAME = so_long
SRCS = srcs/main.c \
		libft/ft_utils.c\
		libft/ft_split.c\
		libft/ft_putnbr_fd.c\
		libft/ft_putstr_fd.c\
		srcs/utils.c\
		srcs/utils1.c\
		srcs/utils2.c\
		srcs/utils3.c\
		srcs/flood_fill.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c
OBJCS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJCS)
	$(CC) $(CFLAGS)  -o $@ $(OBJCS) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJCS)

fclean: clean
	rm -rf $(NAME) $(OBJCS)

re: fclean all

.PHONY: all clean fclean re
