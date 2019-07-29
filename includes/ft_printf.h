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
	char			*color[21];
	char			*color_flag[21];
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

typedef struct		s_types
{
	short			hh;
	short			h;
	short			l;
	short			ll;
	short			L;
	short			z;
	short			b;
}					t_types;

/*
** Prototype :
*/

int					ft_printf(const char *str, ...);

int					ft_active_buffer_n_alloc();
void				ft_free_n_realloc();

int					parse(char *str, va_list args, t_color *tab);

void				parse_specifier(char *s, int i, t_types *typ, t_data *dt);

int					ft_strlcat_mod(char *src, unsigned int n);

int					find_type(char *s);
int					good_type(char c);
int					good_specifier(char c);

void				ft_print_buffer(void);
void				ft_print_buffer_end(void);

int					parse_flag(char *s, va_list args, int code_color);
int					ft_find_type(char *s);

void				ft_init_tab_color(t_color *t);

int					parse_color(char *s, t_color *tab, int *code_color);
int					verify_color(char *s, t_color *tab);

char				*process_formats(t_data *dt, char *res, char flag);

char				*ft_precision_format_char(char flag, char *res, unsigned int pre);
char				*ft_zero_format_char(char *res, unsigned int zero, short pre, short space);
char				*ft_padding_format_char(char *res, unsigned int padd, short less, short space);

char				*ft_zero_format(char *res, unsigned int zero, short pre, short space);
char				*ft_padding_format(char *res, unsigned int padd, short less, short space);

char				*ft_hash_format_nb(char flag, char *res);
char				*ft_more_format_nb(char flag, char *res);

char				*precision_float(int pre, char *res);

char				*convert_binary(va_list args, t_types *typ);
char				*convert_octal(va_list args, t_types *typ);
char				*convert_unsig_dec(va_list args, t_types *typ);
char				*convert_hexa(va_list args, t_types *typ);
char				*convert_hexa_caps(va_list args, t_types *typ);

char				*convert_float(va_list args, t_types *typ);

char				*convert_dec(va_list args, t_types *typ);

char				*convert_adress(va_list args, t_types *typ);
char				*convert_value_n(va_list args, t_types *typ);
char				*convert_iso(va_list args, t_types *typ);

char				*convert_string(va_list args, t_types *typ);
char				*convert_char(va_list args, t_types *typ);

/*
** Initialisation Dispatcher Table 
*/

// args . ' ' # + - 0 
// csp
// dibouxX avec les flags hh, h, l, ll, z
// f avec les flags l et L

typedef struct		s_table_entry
{
	char			type;
	char			*(*fct)(va_list args, t_types *typ);
}					t_table;

static t_table		g_dispatch_table[32] = 
{
	{'d', &(convert_dec)},
	{'i', &(convert_dec)},
	{'b', &(convert_binary)},
	{'u', &(convert_unsig_dec)},
	{'o', &(convert_octal)},
	{'x', &(convert_hexa)},
	{'X', &(convert_hexa_caps)},
	{'f', &(convert_float)},
	{'F', &(convert_float)},
	{'c', &(convert_char)},
	{'s', &(convert_string)},
	{'p', &(convert_adress)},
	{'n', &(convert_value_n)},
	{'k', &(convert_iso)},
	{'\0', NULL} 
};

#endif
