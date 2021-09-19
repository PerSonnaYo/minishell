NAME = minishell

NAME2 = libft/libft.a

HEADERS = minishell.h

HEADERSLIB = libft/libft.h

SRC = main.c \
	  build_fork.c \
	  dollar.c \
	  get_next_line_bonus.c \
	  get_next_line_utils_bonus.c \
	  cd.c \
	  cd_utils.c \
	  command_way.c \
	  echo.c \
	  env.c \
	  exit.c \
	  export.c \
	  first_word.c \
	  export_utils.c \
	  loci.c \
	  gnl2.c \
	  gnl3.c \
	  gnl4.c \
	  gnl5.c \
	  gnl2_utils.c \
	  handle.c \
	  handle3.c \
	  commands.c \
	  handle1.c \
	  links.c \
	  links1.c \
	  main1.c \
	  print_error.c \
	  handle2.c \
	  keys.c \
	  pipes1.c \
	  print_export.c \
	  terman.c \
	  add_export.c \
	  pwd.c \
	  parsing.c \
	  parsing1.c \
	  parsing2.c \
	  pipe2.c \
	  redirect.c \
	  redirect1.c \
	  ret_word.c \
	  signals.c \
	  utils_term0.c \
	  utils_wil0.c \
	  utils_wil1.c \
	  wilcard.c \
	  wilcard1.c \
	  wilcard2.c \
	  wilcard3.c \
	  term_utils1.c \
	  term_utils2.c \
	  term_utils3.c \
	  term_utils4.c \
	  term_utils5.c \
	  term_utils6.c \
	  term_utils7.c \
	  term_utils8.c \
	  keys1.c \
	  keys2.c \
	  unset.c

SRCLIB = 	libft/ft_bzero.c \
              libft/ft_isalnum.c \
         	  libft/ft_isalpha.c \
         	  libft/ft_isascii.c \
         	  libft/ft_isdigit.c \
         	  libft/ft_isprint.c \
         	  libft/ft_memccpy.c \
         	  libft/ft_memcpy.c \
         	  libft/ft_memmove.c \
         	  libft/ft_memset.c \
         	  libft/ft_strchr.c \
         	  libft/ft_strlcat.c \
         	  libft/ft_strlcpy.c \
         	  libft/ft_strlen.c \
         	  libft/ft_strrchr.c \
         	  libft/ft_strnstr.c \
         	  libft/ft_tolower.c \
         	  libft/ft_toupper.c \
         	  libft/ft_atoi.c \
         	  libft/ft_calloc.c \
         	  libft/ft_memchr.c \
         	  libft/ft_memcmp.c \
         	  libft/ft_strdup.c \
         	  libft/ft_strncmp.c \
         	  libft/ft_strcmp.c \
         	  libft/ft_substr.c \
         	  libft/ft_strjoin.c \
         	  libft/ft_strtrim.c \
         	  libft/ft_putchar_fd.c \
         	  libft/ft_putstr_fd.c \
         	  libft/ft_putendl_fd.c \
         	  libft/ft_putnbr_fd.c \
         	  libft/ft_split.c \
         	  libft/ft_realloc.c \
         	  libft/ft_strcpy.c \
         	  libft/ft_strcat.c \
         	  libft/ft_itoa.c \
         	  libft/ft_intlen.c \
         	  libft/ft_strmapi.c \
              libft/ft_lstnew.c \
              libft/ft_lstadd_front.c \
         	  libft/ft_lstsize.c \
         	  libft/ft_lstlast.c \
         	  libft/ft_lstadd_back.c \
         	  libft/ft_lstdelone.c \
         	  libft/ft_lstclear.c \
         	  libft/ft_lstiter.c \
         	  libft/ft_lstmap.c

OBJ = $(SRC:%.c=%.o)

OBJLIB = $(SRCLIB:%.c=%.o)

FLAGS = -ltermcap

.PHONY: all clean fclean re bonus

%.o: %.c $(HEADERS) $(HEADERSLIB)
	gcc -c $< -o $@

$(NAME): $(OBJ) $(HEADERS) $(HEADERSLIB) $(OBJLIB)
	$(MAKE) -C libft
	$(LIBMAKE)
	gcc $(SRC) $(FLAGS) libft/libft.a -o $(NAME)

$(LIBMAKE):
	$(MAKE) bonus -C libft

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
