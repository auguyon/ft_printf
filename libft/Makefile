# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:44:37 by auguyon           #+#    #+#              #
#    Updated: 2019/01/09 15:26:48 by auguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG = 0

CC = gcc

ifeq ($(DEBUG), 0)
    CFLAG		=	-Wall -Wextra -Werror -O2
	MESSAGE		= 	"Libft compiled on normal rules !"
else
    CFLAG		=	-Wall -Wextra -Werror -g3 -O0 -fsanitize=address
	MESSAGE		= 	"[DEBUG] Libft compiled on debug rules !"
endif

NAME = libft.a

SRC	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_isspace.c ft_isblank.c\
			ft_isctrl.c ft_isgraph.c ft_islower.c ft_ispunct.c ft_isupper.c\
			ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
			ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strnew.c\
			ft_strcpy.c ft_strdup.c ft_strndup.c ft_strlcat.c ft_strlen.c\
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c\
			ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c\
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
			ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_lstadd.c ft_lstdel.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
			ft_putstr_fd.c ft_lstiter.c ft_lstmap.c ft_strspn.c ft_strcspn.c\
			ft_strmultidel.c ft_putmultistr.c ft_strnjoin.c ft_atoi_base.c\
			ft_isxdigit.c ft_itoa_base.c ft_data_in_tab.c ft_memlcpy.c\
			ft_strccmp.c ft_strnccmp.c ft_strcchr.c ft_memlcat.c \
			ft_utoa.c ft_utoa_base.c ft_ztoa.c ft_ztoa_base.c \
			ft_itoa_base_caps.c ft_utoa_base_caps.c ft_lltoa.c\
			ft_lltoa_base.c ft_stoa.c ft_stoa_base.c ft_ztoa_base_caps.c \
			ft_ulltoa_base.c ft_ulltoa.c ft_ulltoa_base_caps.c \
			ft_ustoa_base.c ft_ustoa.c ft_ustoa_base_caps.c \

SRCDIR = ./
SRCFILL = $(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./obj/
OBJFILL = $(addprefix $(OBJDIR),$(OBJ))

INC = ./inc/

all: 			$(NAME)

$(NAME): 		$(OBJFILL)
				ar rc $@ $^
				@echo $(MESSAGE)

$(OBJDIR)%.o:	$(SRCDIR)%.c
				mkdir -p $(OBJDIR)
				$(CC) $(CFLAG) -I $(INC) -c $< -o $@

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				echo "Cleaning libft... Done !"
				rm -f $(NAME)

re: 			fclean all

# DEBUG = 0

# ifeq ($(DEBUG), 0)
#     CFLAGS		=	-Wall -Werror -Wextra
# 	MESSAGE		= 	"Libft compiled on normal rules ! PD"
# else
#     CFLAGS		=	-Wall -Wextra -Werror -g3 -O0 -fsanitize=address
# 	MESSAGE		= 	"[DEBUG] Libft compiled on debug rules ! PD"
# endif

# NAME	=	libft.a

# SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
# 			ft_isdigit.c ft_isprint.c ft_isspace.c ft_isblank.c\
# 			ft_isctrl.c ft_isgraph.c ft_islower.c ft_ispunct.c ft_isupper.c\
# 			ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
# 			ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strnew.c\
# 			ft_strcpy.c ft_strdup.c ft_strndup.c ft_strlcat.c ft_strlen.c\
# 			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c\
# 			ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c\
# 			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
# 			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
# 			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
# 			ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_lstadd.c ft_lstdel.c\
# 			ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
# 			ft_putstr_fd.c ft_lstiter.c ft_lstmap.c ft_strspn.c ft_strcspn.c\
# 			ft_strmultidel.c ft_putmultistr.c ft_strnjoin.c ft_atoi_base.c\
# 			ft_isxdigit.c ft_itoa_base.c ft_data_in_tab.c ft_memlcpy.c\
# 			ft_strccmp.c ft_strnccmp.c ft_strcchr.c ft_memlcat.c \
# 			ft_utoa.c ft_utoa_base.c ft_ztoa.c ft_ztoa_base.c \
# 			ft_itoa_base_caps.c ft_utoa_base_caps.c ft_lltoa.c\
# 			ft_lltoa_base.c ft_stoa.c ft_stoa_base.c ft_ztoa_base_caps.c \
# 			ft_ulltoa_base.c ft_ulltoa.c ft_ulltoa_base_caps.c \
# 			ft_ustoa_base.c ft_ustoa.c ft_ustoa_base_caps.c \
			
# OBJS	=	$(SRCS:.c=.o)

# CC		=	gcc

# # CFLAGS	=	-Wall -Werror -Wextra -I $(LIB)

# LIB		=	libft.h

# RM		=	rm -rf

# .SILENT	:

# all		:	$(NAME) Makefile libft.h

# $(NAME)	:	$(OBJS) $(LIB)
# 			ar rc $(NAME) $(OBJS)
# 			@echo $(MESSAGE)

# clean	:
# 			$(RM) $(OBJS)

# fclean	:	clean
# 			$(RM) $(NAME)

# re		:	fclean all

# recl	:	all clean
