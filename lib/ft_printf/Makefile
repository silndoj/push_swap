CFlags = -Wall -Wextra -Werror

files = ft_printf \
		ft_putchar_count \
		ft_x \
		ft_up_x \
		ft_putstr_count \
		ft_unsigned_int \
		ft_putnbr_count \
		ft_ptr_count \
	
CFILES = $(files:%=%.c)

OFILES = $(files:%=%.o)

NAME = libftprintf.a

$(NAME) :
	gcc $(CFlags) -c $(CFILES)
	ar -rc $(NAME) $(OFILES)

all : $(NAME)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
