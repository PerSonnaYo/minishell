# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdude <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 10:28:17 by mdude             #+#    #+#              #
#    Updated: 2020/11/10 11:43:34 by mdude            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SRC = ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memccpy.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strdup.c \
	  ft_strncmp.c \
	  ft_strcmp.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_split.c \
	  ft_realloc.c \
	  ft_strcpy.c \
	  ft_strcat.c \
	  ft_itoa.c \
	  ft_intlen.c \
	  ft_strmapi.c

BONUSSRC = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstmap.c

OSRC = $(SRC:%.c=%.o)

OBONUS = $(BONUSSRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OSRC) $(HEADERS)
	ar rcs $(NAME) $(OSRC)

all: $(NAME)

bonus: $(OSRC) $(OBONUS)
	ar rcs $(NAME) $(OBONUS)

clean:
	rm -f $(OSRC) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
