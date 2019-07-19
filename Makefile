# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 18:18:07 by auguyon           #+#    #+#              #
#    Updated: 2019/07/12 16:42:04 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG 	= 0

NAME	=	ft_printf
#srcs/convert_files/ft_convert_float.c
SRCS	=	main.c \
			srcs/ft_printf.c \
			srcs/mains_files/ft_alloc.c \
			srcs/mains_files/ft_print.c \
			srcs/mains_files/ft_fct_mod.c \
			srcs/parsing_files/ft_parse.c \
			srcs/parsing_files/ft_search.c \
			srcs/formats_files/ft_process_formats.c \
			srcs/formats_files/ft_hash_format.c \
			srcs/formats_files/ft_less_format.c \
			srcs/formats_files/ft_more_format.c \
			srcs/formats_files/ft_precision_format.c \
			srcs/formats_files/ft_space_format.c \
			srcs/formats_files/ft_zero_format.c \
			srcs/convert_files/ft_convert_char.c \
			srcs/convert_files/ft_convert_nb.c \
			srcs/convert_files/ft_convert_other.c \
			srcs/convert_files/ft_convert_size_t.c \
			srcs/convert_files/ft_convert_uint.c \
			srcs/convert_files/ft_convert_ulong.c \
			srcs/convert_files/ft_convert_ushort.c \
			srcs/bonus_files/ft_init_tab_color.c \
			srcs/bonus_files/ft_parse_color.c \

CC		=	gcc

ifeq ($(DEBUG), 0)
    FLAGS		=	
	MESSAGE		= 	"Printf compiled on normal rules ! PD"
else
    FLAGS		=	-Wall -Wextra -Werror -g3 -O0 -fsanitize=address
	MESSAGE		= 	"[DEBUG] Printf compiled on debug rules ! PD"
endif

INC.	=	-I libft/ -I includes/

OBJS	=	$(SRCS:.c=.o)

LIB		=	libft/libft.a

RM		=	rm -rf

.SILENT	:

.PHONY	: 	all clean fclean re

#Colors
_BLACK=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m

_END=\x1b[0m

all		:	$(NAME)

$(NAME)	:	$(OBJS) Makefile includes/
			make -C libft/
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
			@echo $(MESSAGE)

$(OBJS)	: 	%.o: %.c
			$(CC) $(FLAGS) $(INC.) -c $< -o $@

clean	:
			@$(RM) $(OBJS)
			make clean -C libft/

			echo "$(_RED)Clean ! $(_GREEN)OK$(_END)"

fclean	:	clean
			@$(RM) $(NAME)
			make fclean -C libft/

			echo "$(_RED)Fclean ! $(_GREEN)OK$(_END)"

re		:	fclean all

recl	:	all clean
			make recl -C libft/
