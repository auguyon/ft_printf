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

# include "../libft/libft.h"
# include "ft_bonus.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define ALLOC		512

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
	char			*flag;
	int				value;
}					t_data;

/*
** Prototype :
*/

int					ft_printf(const char *str, ...);

int					ft_active_buffer_n_alloc();
void				ft_free_n_realloc();

int					ft_parse(char *str, va_list args, t_color *tab);

int					ft_strlcat_mod(char *src, unsigned int n);
char				*ft_strjoin_mod(char *s, t_data *data_table, int i);

void				ft_print_buffer(void);
void				ft_print_buffer_x(int len);

int					ft_search_type(char *s, va_list args);
int					ft_find_type(char *s);

t_color				*ft_init_tab_color();

int					ft_parse_color(char *s, t_color *tab, va_list args);
int					ft_verify_color(char *s, t_color *tab);


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

static t_table		g_dispatch_table[32] = 
{
	{"d", &(ft_convert_dec)}, 				//0
	{"i", &(ft_convert_dec)},				//1
	{"u", &(ft_convert_dec_uint)},			//2
	{"b", &(ft_convert_binary_uint)},		//3
	{"o", &(ft_convert_octal_uint)},		//4
	{"x", &(ft_convert_hexa_min_uint)},		//5
	{"X", &(ft_convert_hexa_caps_uint)},	//6
	{"c", &(ft_convert_char)},				//7
	{"s", &(ft_convert_string)},			//8
	{"p", &(ft_convert_adress)},			//9
	{"n", &(ft_convert_value_n)},			//10
	{"ib", &(ft_convert_base)},				//11
	{"r", &(ft_convert_iso)},				//12
	{"hd", &(ft_convert_dec_short)},		//13
	{"hi", &(ft_convert_dec_short)},		//14
	{"ld", &(ft_convert_dec_long)},			//15
	{"li", &(ft_convert_dec_long)},			//16
	{"zu", &(ft_convert_dec_size_t)},		//17
	{"zb", &(ft_convert_binary_size_t)},	//18
	{"zo", &(ft_convert_octal_size_t)},		//19
	{"zx", &(ft_convert_hexa_min_size_t)},	//20
	{"zX", &(ft_convert_hexa_caps_size_t)},	//21
	{"lu", &(ft_convert_dec_ullong)},		//22
	{"lb", &(ft_convert_binary_ullong)},	//23
	{"lo", &(ft_convert_octal_ullong)},		//24
	{"lx", &(ft_convert_hexa_min_ullong)},	//25
	{"lX", &(ft_convert_hexa_caps_ullong)},	//26
	{"hu", &(ft_convert_dec_ushort)},		//27
	{"hb", &(ft_convert_binary_ushort)},	//28
	{"ho", &(ft_convert_octal_ushort)},		//29
	{"hx", &(ft_convert_hexa_min_ushort)},	//30
	{"hX", &(ft_convert_hexa_caps_ushort)},	//31
	{NULL, NULL} 
};

#endif
