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
	printf("---- Find Flag ----\ns->|%s| i->|%d|\n", s, i);
	if (s[i] == '%')
		dt->mod = 1;
	i--;
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
		if ((s[i] == '-' || s[i] == '+' || s[i] == '#' || s[i] == ' ' || s[i] == '%') && ft_isdigit(s[i + 1]) && s[i + 1] != '0')
			dt->padd = ft_atoi(&s[i + 1]);
		i--;
	}
}

int			ft_find_type(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'b' || s[i] == 'd' || s[i] == 'i' || s[i] == 'o'
			|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'c'
				|| s[i] == 's' || s[i] == 'p' || s[i] == 'f' || s[i] == 'n'
					|| s[i] == 'r' || s[i] == '%')
			return (i);
		else if (s[i] != ' ' && s[i] != '.' && s[i] != '#' && s[i] != '+'
					&& s[i] != '-' && !ft_isdigit(s[i]) && s[i] != '%'
						&& s[i] != 'l' && s[i] != 'h')
			return (-1);
		i++;
	}
	return (-1);
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
static void ft_init_data_table(t_data *dt)
{
	dt->dot = 0;
	dt->zero = 0;
	dt->padd = 0;
	dt->hash = 0;
	dt->more = 0;
	dt->less = 0;
	dt->space = 0;
	dt->mod = 0;
}

static int		ft_flag_modulo(t_data *dt, char *s, int i,int code_color)
{
	char	*res;

	res = ft_process_flags(dt, res, *(s + i));
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	if (code_color == 2)
		ft_strlcat_mod("\033[0m", 5);
	return (i + 2);
}

int			ft_search_type(char *s, va_list args, int code_color)
{
	static t_data	*data_table;
	char			*res;
	int				fct;
	int 			i;
	int				j;

	fct = 0;
	if (*s == '%')
		return ((ft_strlcat_mod("%", 1) + 1));
	if ((i = ft_find_type(s)) == -1)
		return (0);
	if (!data_table)
		if (!(data_table = (t_data*)malloc(sizeof(t_data))))
			return (0);
	ft_init_data_table(data_table);
	ft_find_flag(s, i, data_table);
	if (s[i] == '%')
		return (ft_flag_modulo(data_table, s, i, code_color));
	j = (ft_find_type_n_arg(s) + i);
	while (*g_dispatch_table[fct].name && ((ft_strncmp(&s[i], g_dispatch_table[fct].name, (j - i + 1))) != 0))
		fct++;
	if ((res = g_dispatch_table[fct].fct(args)) == NULL)
		return (i);
	res = ft_process_flags(data_table, res, *(s + i));
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	if (code_color == 2)
		ft_strlcat_mod("\033[0m", 5);
	return (i + 2);
}





