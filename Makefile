CFLAGS			=	-g -Wall -Wno-error
NAME			=	push_swap


#LIB
LIBFT_LIB		=	lib/libft/
LIBFT_MAKE		=	./lib/libft/Makefile
FT_PRINTF_LIB	=	lib/ft_printf/
FT_PRINTF_MAKE	=	./lib/ft_printf/Makefile


#SRC
PUSH_SWAP_MAIN	=	src/push_swap.c
PUSH_SWAP_SRC	=	src/ft_alpha_error.c \
					src/ft_atoi2.c \
					src/manipulation.c \
<<<<<<< HEAD
					src/tricks_a.c
=======
					src/tricks_a.c \
					src/tricks_b.c \
					src/tricks_ab.c \
					src/shift_stack.c \
					src/stack_inv.c 
>>>>>>> 34cbd41a01f5b679e379727702a9967d0f91e08f

INCLUDE = -L ./lib/libft -lft -L ./lib/ft_printf -lftprintf

OBJ_MAIN = $(PUSH_SWAP_MAIN:.c=.o)
OBJ_SRC = $(PUSH_SWAP_SRC:.c=.o)

#RULES	
all: $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ_SRC)
		@make -C $(LIBFT_LIB)
		@make -C $(FT_PRINTF_LIB)
		@gcc $(CFLAGS) -o $(NAME) $(OBJ_MAIN) $(OBJ_SRC) -g $(INCLUDE) 

lib_clean:
					make -C $(LIBFT_LIB) clean
					make -C $(FT_PRINTF_LIB) clean

lib_fclean:
					make -C $(LIBFT_LIB) fclean
					make -C $(FT_PRINTF_LIB) fclean

clean:				lib_clean
						rm -rf $(OBJ_MAIN) $(OBJ_SRC)

fclean:				clean lib_fclean
						rm -rf $(NAME)

re:					fclean all

.PHONY: all, clean, fclean, re 
