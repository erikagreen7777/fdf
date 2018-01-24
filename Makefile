NAME = fdf

FLAGS = -Wall -Werror -Wextra -g

LIBS = libft/libft.a\
	   minilibx_macos/libmlx.a

SRCS = srcs/main.c\
	   srcs/validate.c \
	   srcs/parse.c \
	   srcs/draw_line.c \
	   srcs/colors.c \
	   srcs/sizes.c
	

FRAMEWORKS = -framework OpenGL -framework AppKit

OFILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(CFLAGS) -o $@ $(OFILES) $(LIBS) $(FRAMEWORKS)
	@echo "\033[32m[fdf]\033[0m"
	
%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂❂❂"

clean:
	@/bin/rm -f rm $(OFILES)
	@echo "\033[31m[.o files deleted]\033[0m"
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	@/bin/rm -f rm $(NAME)
	@echo "\033[31m[executable deleted]\033[0m"
	@make -C libft/ fclean

re: fclean all