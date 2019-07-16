 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:45:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 16:46:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_find_flag(char *s, int i, t_data *dt)
{
if (DEBUG == 4 || DEBUG == 1)
	printf("---- Find Flag ----\n s->|%s| i-> |%d|\n", s, i);
	dt->dot = 0;
	dt->zero = 0;
	dt->space = 0;
	dt->hash = 0;
	dt->more = 0;
	dt->less = 0;
	while (i >= 0)
	{
		while (ft_isdigit(s[i]) && i >= 0)
			i--;
		if (s[i + 1] == '0')
			dt->zero = ft_atoi(&s[i + 2]);
		if (s[i] == '.')
			dt->dot = ft_atoi(&s[i + 1]);
		else if (s[i] == '#')
			dt->hash = 1;
		else if (s[i] == '+')
			dt->more = 1;
		else if (s[i] == '-')
			dt->less = 1;
		else if (s[i] == ' ')
			dt->space = 1;
		i--;
	}
if (DEBUG == 1)
	printf("dot->%d zero->%d space->%d hash->%d more->%d less->%d\n",dt->dot,dt->zero, dt->space, dt->hash, dt->more,dt->less);
}

int			ft_find_type(char *s)
{
	int i;

	i = 0;
	while (*s && s[i] != 'b' && s[i] != 'd' && s[i] != 'i' && s[i] != 'o'
				&& s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != 'c'
					&& s[i] != 's' && s[i] != 'p' && s[i] != 'f' && s[i] != 'n'
						&& s[i] != 'r')
		i++;
	return (i);
}

static int	ft_find_type_n_arg(char *s)
{
	int	i;

	i = 0;
	if (s[i - 1] == '%')
		return (i);
	if (s[i - 1] == 'z' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		i--;
	else if (s[i - 1] == 'h' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		i--;
	else if (s[i - 1] == 'l' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		i--;
	else if (s[i - 1] == 'h' && (s[i] == 'd' || s[i] == 'i'))
		i--;
	else if (s[i - 1] == 'l' && (s[i] == 'd' || s[i] == 'i'))
		i--;	
	else if (s[i] == 'i' && s[i + 1] == 'b')
		i--;
	return (i);
}

int			ft_search_type(char *s, va_list args, int code_color)
{
	t_data			*data_table;
	char			*res;
	int				fct;
	int 			i;
	int				j;
	
	fct = 0;
if (DEBUG == 1)
	printf("search_type! s->|%.10s| code_couleur->|%d|\n", s, code_color);
	if (*s == '%')
		return ((ft_strlcat_mod("%", 1) + 1));
	if (!(data_table = (t_data*)malloc(sizeof(t_data))))
		return (0);
	i = ft_find_type(s);
	j = i;
	j += ft_find_type_n_arg(s);
	ft_find_flag(s, i, data_table);
	while (*g_dispatch_table[fct].name && ((ft_strncmp(&s[i], g_dispatch_table[fct].name, (j - i + 1))) != 0))
		fct++;
if (DEBUG == 1)
	printf("valeur de i :%d et flag:%s, valeur de s:%c\n", i, g_dispatch_table[fct].name, s[i]);
	if ((res = g_dispatch_table[fct].fct(args)) == NULL)
		return (i);
	res = ft_process_flags(data_table, res, *s + i); // remplacer j par i avec if h l z +1
if (DEBUG == 1)
	printf("res -> |%s| |%d|\n", res, (int)ft_strlen(res));
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	free(res);
	if (code_color == 2)
		ft_strlcat_mod("\033[0m", 5);
	return (i + 2);
}





