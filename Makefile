NAME = so_long
NAME2 = so_long_bonus

LIBFT = libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

SRC =	code/so_long.c \
	code/imgs.c \
	code/matr.c \
	code/keys.c \
	code/check_matr.c \
	code/floodfill.c \
	code/utils.c \
	
BNS =	code_bonus/so_long_bonus.c \
	code_bonus/floodfill_bonus.c \
	code_bonus/utils_bonus.c \
	code_bonus/check_matr_bonus.c \
	code_bonus/imgs_bonus.c \
	code_bonus/matr_bonus.c \
	code_bonus/keys_bonus.c \
	
FLAGS = -no-pie -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

all: $(NAME)

$(NAME): libcomp mlxcomp comp

maps:
		@cd maps && ls *.ber -a > list_maps.txt

libcomp:
		@make -C libft

mlxcomp:
		@cd minilibx-linux && ./configure

comp:
	gcc $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
	
bonus: libcomp mlxcomp maps
	gcc $(FLAGS) $(BNS) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME2)
            
libclean:
		@make clean -C libft
		
clean:		libclean

libfclean:
		@make fclean -C libft

fclean:   	clean libfclean
		rm -rf $(NAME) $(NAME2)
		rm -rf maps/list_maps.txt
		
re: fclean all

reb: fclean bonus

.PHONY: all re clean fclean bonus maps

.SILENT:
