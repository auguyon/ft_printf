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

#include "../includes/ft_printf.h"

char	*ft_flag_processor(char *s, struct s_data *data_table, char type)
{
	char	*r;
	int		i;

	i = 0;
	(void)type;
	while (data_table[i].flag)
	{
		if (data_table[i].on != 0)
		{
			r = data_table[i].fct(s, data_table, i);
		}
		i++;
	}
	return (r);
}

void		ft_find_flag(char *s, int i, t_data *data_table)
{
	int	j;

	while (i != 0 && !(j = 0))
	{
		while (data_table[j].flag)
		{
			if (s[i] == data_table[j].flag[0])
			{
				if ((s[i] == '0' && ft_isdigit(s[i - 1])) || (s[i] == '0'
					&& ft_isdigit(s[i - 1]) && ft_isdigit(s[i - 2])))
				{
					i--;
					while (s[i] != '0')
						i--;
					data_table[j].on = atoi(&s[i + 1]);
				}
				if (s[i] == 'h' && s[i - 1] == 'h')
					data_table[1].on = 1;
				else if (s[i] == 'l' && s[i - 1] == 'l')
					data_table[3].on = 1;
				else if (s[i] == '.' || s[i] == ' ')
					data_table[j].on = atoi(&s[i + 1]);
				else
					data_table[j].on = 1;
				break;
			}
			j++;
		}
		i--;
	}
	if (data_table[7].on == 1 && data_table[8].on == 1)
		data_table[8].on = 0;
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
	if ((s[i] == 'u' && s[i + 1] == 'z') || (s[i] == 'i' && s[i + 1] == 'b'))
		i++;
	return (i);
}

int			ft_search_type(char *s, va_list args)
{
	t_data			data_table[16] = {
	{"h", 0, NULL}, {"hh", 0, NULL}, {"ll", 0, NULL}, {"l", 0, NULL}, {".", 0, NULL}, {"*", 0,NULL}, {"#", 0, NULL},
	{"+", 0, &(ft_strjoin_mod)}, {"-", 0, &(ft_strjoin_mod)}, {"0", 0, &(ft_strjoin_mod)}, {" ", 0, &(ft_strjoin_mod)}, {NULL, 0, NULL} };
	char			*res;
	int				fct;
	int 			i;
	int				j;
	
	fct = 0;
	if (*s == '%')
		return (ft_strlcat_mod("%", 1));
	i = ft_find_type(s);
//printf("test->%s\n", s);

	if (s[i - 1] == 'l' && (s[i] == 'd' || s[i] == 'i' || s[i] == 'o'
		|| s[i] == 'b' || s[i] == 'x' || s[i] == 'X'))
		fct = 13;
	else if (s[i] == 'z' && s[i - 1] == 'u' && !(j = 0))
		fct = 5;
	else if (s[i] == 'b' && s[i - 1] == 'i' )
		fct = 12;
	else
		while (*g_dispatch_table[fct].name && *g_dispatch_table[fct].name && s[i] != g_dispatch_table[fct].name[0])
			fct++;
//printf("valeur de fct :%d et flag:%s, valeur de s:%c\n", fct, g_dispatch_table[fct].name, s[i]);
	if ((res = g_dispatch_table[fct].fct(args)) == NULL)
		return (i);
	if (s[i - 1] != '%')
	{
		ft_find_flag(s, i, data_table);
		res = ft_flag_processor(res, data_table, s[i]);
	}
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	while (data_table[j].flag)
		data_table[j++].on = 0;
	return (i);
}
