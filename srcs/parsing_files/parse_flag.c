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
	char	*tmp;
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
	tmp = ft_strdup("%");
	if (zero <= 1)
		return (ft_strlcat_mod(tmp, 1) + i);
	if (less == 1)
		res = ft_space_format_rev('%', tmp, 0, zero);
	else
		res = ft_space_format('%', tmp, 0, zero);
	ft_strlcat_mod(res, ft_strlen(res));
	free(tmp);
	return (i + 1);
}			

int			parse_flag(char *s, va_list args, int code_color)
{
	t_data		dt;
	t_types		typ;
	char		*res;
	int			fct;
	int			i;

	if ((fct = double_pourcent(s, 0, 0)) > 0)
		return (fct);
	if ((i = find_type(s)) <= 0)
		return (0);
	parse_specifier(s, i, &typ, &dt);
	while (g_dispatch_table[fct].type && (s[i] != g_dispatch_table[fct].type))
		fct++;
	if ((res = g_dispatch_table[fct].fct(args, &typ)) == NULL)
		return (i);
	if ((res = process_formats(&dt, res, *(s + i))) == NULL)
		return (i);
	ft_strlcat_mod(res, (unsigned int)ft_strlen(res));
	if (code_color == 2)
		ft_strlcat_mod("\033[0m", 5);
	return (i);
}
