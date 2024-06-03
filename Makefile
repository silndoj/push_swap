CFlags			=	-Wall -Wextra -Werror
PUSH_SWAP		=	push_swap
NAME			=	$(PUSH_SWAP)

#LIB
LIBFT			=	libft.a
LIBFT_LIB		=	lib/libft
LIBFT_A			=	$(LIBFT_LIB)/$(LIBFT)
CFLAGS			+=	-I $(LIBFT_LIB)

FT_PRINTF		=	ft_printf.a
FT_PRINTF_LIB	=	lib/ft_printf
FT_PRINTF_A		=	$(PRINTF_LIB)/$(PRINTF)
CFLAGS			+=	-I $(PRINTF_LIB)

MAKE			=	make --no-print-directory -C

#SRC
PUSH_SWAP_SRC	=	src/push_swap.c
PUSH_SWAP_INC	=	inc/push_swap.h

#RULES	
all:			$(PUSH_SWAP)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_A) $(FT_PRINTF_A)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c $(PUSH_SWAP_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
					$(MAKE) $(LIBFT_LIB)
$(FT_PRINTF_A):
					$(MAKE) $(FT_PRINTF_LIB)

$(PUSH_SWAP):		$(LIB) $(PUSH_SWAP_OBJ)
					gcc $(CFLAGS) $(LIB) $(PUSH_SWAP_OBJ) -o $@


lib_clean:
					$(MAKE) $(LIBFT_LIB) clean
					$(MAKE) $(FT_PRINTF_LIB) clean

lib_fclean:
					$(MAKE) $(LIBFT_LIB) fclean
					$(MAKE) $(FT_PRINTF_LIB) fclean

clean:				lib_clean
						rm -rf obj

fclean:				clean lib_fclean
						rm -rf $(NAME)

re:					fclean all


.PHONY: all, clean, fclean, re 
