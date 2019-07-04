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

void		ft_process_flag(t_data *data_table, char *s)
{
	int		i;

	i = 0;
	 
}

void		ft_find_flag(char *s, int i, t_data *data_table)
{
	while (i != 0)
	{
		while (i != 0 && ft_isdigit(&s[i]))
			i--;
		if (s[i] == '.')
			data_table[0].value = ft_atoi(&s[i + 1]);
		else if (s[i + 1] == '0')
			data_table[1].value = ft_atoi(&s[i + 2]);
		else if (s[i] == '#')
			data_table[3].value = ft_atoi(&s[i + 1]);
		else if (s[i] == '+')
			data_table[4].value = ft_atoi(&s[i + 1]);
		else if (s[i] == '-')
			data_table[5].value = ft_atoi(&s[i + 1]);
		else
			data_table[2].value = ft_atoi(&s[i + 1]);
		i--;
	}
}

int			ft_find_type(char *s)
{
	int i;

	i = 0;
	while (*s && s[i] != 'b' && s[i] != 'd' && s[i] != 'i' && s[i] != 'o'
			&& s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != 'c'
				&& s[i] != 's' && s[i] != 'p' && s[i] != 'f' && s[i] != 'n'
					&& s[i] != 'r' && s[i] == '%')
		i++;
	return (i);
}

static int	ft_find_type_n_arg(char *s)
{
	int	i;

	i = ft_find_type(s);
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
	else if (s[i] == 'i' && s[i - b])
		i--;
	return (i);
}

int			ft_search_type(char *s, va_list args)
{
	t_data			data_table[8] = {
	{".", 0}, {"0", 0}, {" ", 0}, {"#", 0}, {"+", 0}, {"-", 0}, {NULL, 0}};
	char			*res;
	int				fct;
	int 			i;
	int				j;
	
	fct = 0;
	if (*s == '%')
		return (ft_strlcat_mod("%", 1));
	i = ft_find_type_n_arg(s);
	ft_find_flag(s, i, data_table);
	while (*g_dispatch_table[fct].name && ((ft_strncmp(&s[i], g_dispatch_table[fct].name[0], 2)) != 0))
		fct++;
//printf("valeur de fct :%d et flag:%s, valeur de s:%c\n", fct, g_dispatch_table[fct].name, s[i]);
	if ((res = g_dispatch_table[fct].fct(args)) == NULL)
		return (i);
	ft_process_flag(data_table, res);
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	while (data_table[j].flag)
		data_table[j++].value = 0;
	free(res);
	return (i);
}





