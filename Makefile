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

SRCS	=	main.c \
			srcs/ft_printf.c \
			srcs/mains_files/ft_print.c \
			srcs/mains_files/buffer_cat_free.c \
			srcs/mains_files/find_type.c \
			srcs/parsing_files/parse.c \
			srcs/parsing_files/parse_flag.c \
			srcs/parsing_files/parse_color.c \
			srcs/parsing_files/parse_specifier.c \
			srcs/formats_files/ft_float_format.c \
			srcs/formats_files/ft_process_formats.c \
			srcs/formats_files/ft_symbol_format.c \
			srcs/formats_files/ft_padding_format.c \
			srcs/formats_files/ft_padding_format_char.c \
			srcs/convert_files/convert_unsigned.c \
			srcs/convert_files/convert_float.c \
			srcs/convert_files/convert_int.c \
			srcs/convert_files/convert_other.c \
			srcs/convert_files/convert_char.c \
			srcs/bonus_files/ft_init_tab_color.c \

CC		=	gcc

ifeq ($(DEBUG), 0)
    FLAGS		=	
	MESSAGE		= 	"Printf compiled on normal rules ! PD"
else
    FLAGS		=	-g3 -O0 -fsanitize=address
	MESSAGE		= 	"[DEBUG] Printf compiled on debug rules ! PD"
endif

INC.	=	-I ../libft/ -I includes/

OBJS	=	$(SRCS:.c=.o)

LIB		=	../libft/libft.a

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
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
			@echo $(MESSAGE)

$(OBJS)	: 	%.o: %.c
			$(CC) $(FLAGS) $(INC.) -c $< -o $@

clean	:
			@$(RM) $(OBJS)

			echo "$(_RED)Clean ! $(_GREEN)OK$(_END)"

fclean	:	clean
			@$(RM) $(NAME)

			echo "$(_RED)Fclean ! $(_GREEN)OK$(_END)"

re		:	fclean all

recl	:	all clean
