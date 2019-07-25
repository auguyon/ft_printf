/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:45:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 16:46:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	double_pourcent(char *s, int zero, int less)
{
	char	*res;
	int		i;

	i = 1;
	while (s[i] && s[i] != '%')
	{
		if (s[i] == '-')
			less = 1;
		if (ft_isdigit(s[i]))
		{
			if (s[i] == 0 && ft_isdigit(s[i + 1]))
				zero = ft_atoi(&s[i + 2]);
			else if (ft_isdigit(s[i]))
				zero = ft_atoi(&s[i]);
			while (ft_isdigit(s[i]))
				i++;
			i--;
		}
		if (good_specifier(s[i]))
			return (0);
		i++;
	}
	if (zero <= 1)
	{
		ft_strlcat_mod(ft_strdup("%"), 1);
		return (i + 1);
	}
	if (less == 1)
		res = ft_space_format_rev('%', ft_strdup("%"), 0, zero);
	else
		res = ft_space_format('%', ft_strdup("%"), 0, zero);
	ft_strlcat_mod(res, ft_strlen(res));
	return (i + 1);
}			

int			parse_flag(char *s, va_list args, int code_color)
{
	static t_data	*data_table;
	char			*res;
	int				fct;
	int 			len;
	int				i;

	if ((fct = double_pourcent(s, 0, 0)) > 0)
		return (fct);
	if ((i = find_type(s)) <= 0)
		return (0);
	len = (find_specifier(s + i));
	if (!data_table)
		if (!(data_table = (t_data*)malloc(sizeof(t_data))))
			return (0);
	parse_specifier(s, i, data_table);
	while (*g_dispatch_table[fct].name && ((ft_strncmp(&s[i - len], g_dispatch_table[fct].name, len + 1)) != 0))
		fct++;
	if ((res = g_dispatch_table[fct].fct(args)) == NULL)
		return (i);
	if ((res = process_formats(data_table, res, *(s + i))) == NULL)
		return (i);
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	if (code_color == 2)
		ft_strlcat_mod("\033[0m", 5);
	return (i);
}
