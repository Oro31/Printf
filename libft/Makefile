# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 11:15:10 by rvalton           #+#    #+#              #
#    Updated: 2020/09/24 22:25:50 by rvalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

SRC	=	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_itoa.c		\
		ft_memccpy.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c		\
		ft_memset.c		\
		ft_power.c		\
		ft_putchar.c		\
		ft_putchar_fd.c		\
		ft_putendl_fd.c		\
		ft_puthexa.c		\
		ft_putmem.c		\
		ft_putnbr.c		\
		ft_putnbr_fd.c		\
		ft_putstr.c		\
		ft_putstr_fd.c		\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c		\
		ft_strmapi.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strtrim.c		\
		ft_substr.c		\
		ft_tolower.c		\
		ft_toupper.c

OBJ	=	$(subst .c,.o,$(SRC))

all	:	$(NAME)

$(NAME)	: 	
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean	:
	/bin/rm -f $(OBJ)

fclean	: 	clean
	/bin/rm -f $(NAME)

re	: 	fclean all

.PHONY	:	clean fclean all re
