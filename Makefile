CFLAGS			=	-Wall -Wextra -Werror
NAME			=	push_swap


#LIB
LIBFT_LIB		=	lib/libft/
LIBFT_MAKE		=	./lib/libft/Makefile
FT_PRINTF_LIB	=	lib/ft_printf/
FT_PRINTF_MAKE	=	./lib/ft_printf/Makefile


#SRC
PUSH_SWAP_MAIN	=	src/push_swap.c
#PUSH_SWAP_SRC	=	src/

INCLUDE = -I lib/libft -I lib/ft_printf

OBJ_MAIN = $(PUSH_SWAP_MAIN:.c=.o)
#OBJ_SRC = $(PUSH_SWAP_SRC:.c=.o)

#RULES	
all: $(NAME)

.c.o:
			gcc $(CFLAGS) $(INCLUDE) -c $< -o $@


$(NAME): $(OBJ_MAIN)
		@make -C $(LIBFT_LIB)
		@make -C $(FT_PRINTF_LIB)
		@gcc $(CFLAGS) $(OBJ_MAIN) -o $(NAME) $(INCLUDE)


lib_clean:
					make -f $(LIBFT_MAKE) clean
					make -f $(FT_PRINTF_MAKE) clean

lib_fclean:
					make -f $(LIBFT_MAKE) fclean
					make -f $(FT_PRINTF_MAKE) fclean

clean:				lib_clean
						rm -rf $(OBJ_MAIN)

fclean:				clean lib_fclean
						rm -rf $(NAME)

re:					fclean all

.PHONY: all, clean, fclean, re 
