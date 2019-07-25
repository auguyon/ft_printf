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

# include "../libft/inc/libft.h"
# include "ft_bonus.h"

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define ALLOC		512
# define DEBUG		0
// 1 general 4 flag/args

/*
** 	Manage types : d i o u x X f F c s p n b ib k
** 	With hh h ll l and l L z
** 	* %% # + - 0 'space'
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
	ssize_t			dot;
	unsigned int	zero;
	unsigned int	padd;
	unsigned int	space;
	unsigned int	hash;
	unsigned int	more;
	unsigned int	less;
}					t_data;

/*
** Prototype :
*/

int					ft_printf(const char *str, ...);

int					ft_active_buffer_n_alloc();
void				ft_free_n_realloc();

int					parse(char *str, va_list args, t_color *tab);

void 				parse_specifier(char *s, int i, t_data *dt);

int					ft_strlcat_mod(char *src, unsigned int n);

int					find_type(char *s);
int					good_type(char c);
int					good_specifier(char c);
int					find_specifier(char *s);

void				ft_print_buffer(void);
void				ft_print_buffer_x(int len);

int					parse_flag(char *s, va_list args, int code_color);
int					ft_find_type(char *s);

t_color				*ft_init_tab_color();

int					parse_color(char *s, t_color *tab, int *code_color);
int					verify_color(char *s, t_color *tab);

char				*process_formats(t_data *dt, char *res, char flag);

char				*process_formats_float(t_data *dt, char *res, char flag);

char				*ft_precision_format_nb(char flag, char *res, unsigned int pre);
char				*ft_precision_format_char(char flag, char *res, unsigned int pre);

char				*ft_zero_format(char flag, char *res, unsigned int pre);

char				*ft_space_format(char flag, char *res, unsigned int space, unsigned int padd);
char				*ft_space_format_rev(char flag, char *res, unsigned int space, unsigned int padd);

char				*ft_hash_format_nb(char flag, char *res);

char				*ft_more_format_nb(char flag, char *res);

char				*ft_convert_base(va_list args);
char				*ft_convert_dec(va_list args);
char				*ft_convert_dec_short(va_list args);
char				*ft_convert_dec_long(va_list args);

char				*ft_convert_dec_size_t(va_list args);
char				*ft_convert_binary_size_t(va_list args);
char				*ft_convert_octal_size_t(va_list args);
char				*ft_convert_hexa_min_size_t(va_list args);
char				*ft_convert_hexa_caps_size_t(va_list args);

char				*ft_convert_dec_uint(va_list args);
char				*ft_convert_binary_uint(va_list args);
char				*ft_convert_octal_uint(va_list args);
char				*ft_convert_hexa_min_uint(va_list args);
char				*ft_convert_hexa_caps_uint(va_list args);

char				*ft_convert_dec_ullong(va_list args);
char				*ft_convert_binary_ullong(va_list args);
char				*ft_convert_octal_ullong(va_list args);
char				*ft_convert_hexa_min_ullong(va_list args);
char				*ft_convert_hexa_caps_ullong(va_list args);

char				*ft_convert_dec_ushort(va_list args);
char				*ft_convert_binary_ushort(va_list args);
char				*ft_convert_octal_ushort(va_list args);
char				*ft_convert_hexa_min_ushort(va_list args);
char				*ft_convert_hexa_caps_ushort(va_list args);

char				*ft_convert_char(va_list args);
char				*ft_convert_string(va_list args);

char				*ft_convert_double(va_list args);
char				*ft_convert_long_double(va_list args);

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

static t_table		g_dispatch_table[64] = 
{
	{"d", &(ft_convert_dec)},
	{"i", &(ft_convert_dec)},
	{"u", &(ft_convert_dec_uint)},
	{"b", &(ft_convert_binary_uint)},
	{"o", &(ft_convert_octal_uint)},
	{"x", &(ft_convert_hexa_min_uint)},
	{"X", &(ft_convert_hexa_caps_uint)},
	{"f", &(ft_convert_double)},
	{"F", &(ft_convert_double)},
	{"c", &(ft_convert_char)},
	{"s", &(ft_convert_string)},
	{"p", &(ft_convert_adress)},
	{"n", &(ft_convert_value_n)},
	{"ib", &(ft_convert_base)},
	{"r", &(ft_convert_iso)},
	{"Lf", &(ft_convert_long_double)},
	{"LF", &(ft_convert_long_double)},
	{"hd", &(ft_convert_dec_short)},
	{"hi", &(ft_convert_dec_short)},
	{"ld", &(ft_convert_dec_long)},
	{"li", &(ft_convert_dec_long)},
	{"zu", &(ft_convert_dec_size_t)},
	{"zb", &(ft_convert_binary_size_t)},
	{"zo", &(ft_convert_octal_size_t)},
	{"zx", &(ft_convert_hexa_min_size_t)},
	{"zX", &(ft_convert_hexa_caps_size_t)},
	{"lu", &(ft_convert_dec_ullong)},
	{"lb", &(ft_convert_binary_ullong)},
	{"lo", &(ft_convert_octal_ullong)},
	{"lx", &(ft_convert_hexa_min_ullong)},
	{"lX", &(ft_convert_hexa_caps_ullong)},
	{"hu", &(ft_convert_dec_ushort)},
	{"hb", &(ft_convert_binary_ushort)},
	{"ho", &(ft_convert_octal_ushort)},
	{"hx", &(ft_convert_hexa_min_ushort)},
	{"hX", &(ft_convert_hexa_caps_ushort)},
	{"hf", &(ft_convert_double)},
	{"hF", &(ft_convert_double)},
	{NULL, NULL} 
};

#endif
