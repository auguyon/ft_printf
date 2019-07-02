/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:33:37 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/27 16:59:11 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define REVERSE	"\033[7m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"

# define ALLOC		1024

/*
** Manage types : d i o u x X f F c s p n b ib uz k
** With hh h ll l and l L
** * %% # + - 0 'space'
*/

/*
** Struct buffer and global variable for buffer bonus
** Struct for color bonus
** Struct for data
*/

typedef struct		s_buffer
{
	char			*buf;
	unsigned int	len;
	unsigned int	w_len;
}					t_buff;

t_buff				*g_buff;

typedef struct		s_color
{
	char			**color;
	char			**color_flag;
}					t_color;

typedef struct		s_data
{
	char			*flag;
	int				on;
	char			*(*fct)(char *s, struct s_data *data_table, int i);
}					t_data;

/*
** Prototype :
*/

int					ft_printf(const char *str, ...);

int					ft_active_buffer_n_alloc();
void				free_n_realloc();

t_color				*ft_init_tab_color();

int					ft_parse(char *str, va_list args, t_color *tab);

int					ft_strlcat_mod(char *src, unsigned int n);
char				*ft_strjoin_mod(char *s, t_data *data_table, int i);
char				*ft_ultoa_iso_format(unsigned long n, int format);

int					ft_parse_color(char *s, t_color *tab, va_list args);
int					ft_verify_color(char *s, t_color *tab);

void				ft_print_buffer(void);
void				ft_print_buffer_x(int len);

int					ft_search_type(char *s, va_list args);
int					ft_find_type(char *s);

char				*ft_convert_dec(va_list args);
char				*ft_convert_size(va_list args);
char				*ft_convert_dec_unsigned(va_list args);
char				*ft_convert_binary(va_list args);
char				*ft_convert_octal(va_list args);
char				*ft_convert_hexa_caps(va_list args);
char				*ft_convert_hexa_min(va_list args);
char				*ft_convert_base(va_list args);
char				*ft_convert_long(va_list args);

char				*ft_convert_char(va_list args);
char				*ft_convert_string(va_list args);

char				*ft_convert_adress(va_list args);
char				*ft_convert_value_n(va_list args);
char				*ft_convert_iso(va_list args);

/*
** Initialisation Dispatcher Table
*/

typedef struct		s_table_entry
{
	char			*name;
	char			*(*fct)(va_list args);
}					t_table;

static t_table		g_dispatch_table[32] = {
	{"b", &(ft_convert_binary)}, {"d", &(ft_convert_dec)},
	{"i", &(ft_convert_dec)}, {"o", &(ft_convert_octal)},
	{"uz", &(ft_convert_size)}, {"u", &(ft_convert_dec_unsigned)},
	{"c", &(ft_convert_char)}, {"x", &(ft_convert_hexa_min)},
	{"X", &(ft_convert_hexa_caps)}, {"s", &(ft_convert_string)},
	{"p", &(ft_convert_adress)}, {"n", &(ft_convert_value_n)},
	{"ib", &(ft_convert_base)}, {"l", &(ft_convert_long)},
	{"f", NULL}, {"r", &(ft_convert_iso)}, {NULL, NULL} };

#endif

/*
** 			----	BONUS	---
**
** 1 - Types : n, b, ib, uz, k :
**
** n : the number of char write before %n and entered in the variable in params;
** b : unsigned int, binary code;
** ib : 2 args, on it's a number, one it's base;
** uz : size_t;
** k : transform the number in date or date and hour for ISO8601;
**
** 2 - Buffer of 1024, when the buffer of 8096 is full, i print;
**
** 3 - When the buffer match \n, it writes or it writes at the end of process;
**
** 4 - The most static for speed;
**
** 5 - Color, if you put {color} just before % the answer is in color
**if you put {color} somewhere the all of answer is in this color or put {reset};
**
*/
