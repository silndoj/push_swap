CFlags = -Wall -Wextra -Werror

LIBFT = Libft/

PRINTF = ft_printf/

SRC = src/

CFILES = $(src:%=%.c)

OFILES = $(src:%=%.o)

NAME = push_swap

$(NAME) :
	@make -sC $(LIBFT)
	@make -sC $(PRINTF)
	cc $(CFlags) -o $(NAME) $(OFILES) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

all : $(NAME)

clean:
	rm -rf $(OFILES)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean

re: fclean all

.PHONY: all, clean, fclean, re
