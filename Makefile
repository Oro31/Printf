# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 23:24:10 by rvalton           #+#    #+#              #
#    Updated: 2020/09/25 04:16:42 by rvalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT	= ./libft/libft.a

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

SRC	=	ft_handle_flags.c		\
		ft_is_c.c		\
		ft_is_di.c		\
		ft_is_u.c		\
		ft_is_p.c		\
		ft_is_s.c		\
		ft_is_x.c		\
		ft_printf.c		\
		ft_printf_option.c		\

OBJ	=	$(subst .c,.o,$(SRC))

all	:	$(NAME)

$(NAME)	:
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean	:
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)

fclean	:	clean
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(NAME)

re	: fclean all

.PHONY	:	clean fclean all re
