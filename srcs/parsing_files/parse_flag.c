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

static char	*modifier_length(int padd, int zero, int less)
{
	char	*res;

	res = ft_strdup("%");
	if (padd > 1)
		return (ft_padding_format(res, padd, less, 0));
	if (zero > 0 && less > 0)
		return (ft_padding_format(res, zero, less, 0));
	if (zero > 0 && less == 0)
		return (ft_zero_format(res, zero, less, 0));
	return (res);
}

static int	double_pourcent(char *s, int padd, int zero, int less)
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
			if (s[i] == '0' && ft_isdigit(s[i + 1]))
				zero = ft_atoi(&s[i + 1]);
			else if (ft_isdigit(s[i]))
				padd = ft_atoi(&s[i]);
			while (ft_isdigit(s[i + 1]))
				i++;
		}
		if (good_specifier(s[i]))
			return (0);
		i++;
	}
	res = modifier_length(padd, zero, less);
	buffer_cat_free(res, ft_strlen(res), 1);
	return (i + 1);
}

int			parse_flag(char *s, va_list args, int code_color)
{
	t_data		dt;
	t_types		typ;
	char		*res;
	int			fct;
	int			i;

	if ((fct = double_pourcent(s, 0, 0, 0)) > 0)
		return (fct);
	if ((i = find_type(s)) <= 0)
		return (1);
	parse_specifier(s, i, &typ, &dt);
	while (g_dispatch_table[fct].type && (s[i] != g_dispatch_table[fct].type))
		fct++;
	if ((res = g_dispatch_table[fct].fct(args, &typ)) == NULL)
		return (i);
	if ((res = process_formats(&dt, res, *(s + i))) == NULL)
		return (i);
	if (s[i] == 'c' && res[0] == '\0')
		buffer_cat_free(res, 1, 1);
	else
		buffer_cat_free(res, ft_strlen(res), 1);
	if (code_color == 2)
		buffer_cat_free("\033[0m", 5, 0);
	return (i);
}
