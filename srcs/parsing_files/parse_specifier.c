/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:45:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 16:46:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	parse_length_modifier(char *s, int i, t_types *typ)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		if (s[j] == 'h' && s[j + 1] == 'h' && good_type(s[j + 2]))
			typ->hh = 1;
		else if (s[j] == 'h' && good_type(s[j + 1]))
			typ->h = 1;
		else if (s[j] == 'l' && s[j + 1] == 'l' && good_type(s[j + 2]))
			typ->ll = 1;
		else if (s[j] == 'l' && good_type(s[j + 1]))
			typ->l = 1;
		else if (s[j] == 'L' && good_type(s[j + 1]))
			typ->lc = 1;
		else if (s[j] == 'z' && good_type(s[j + 1]))
			typ->z = 1;
		if (typ->hh == 1 || typ->h == 1 || typ->l == 1 || typ->ll == 1
			|| typ->z == 1)
			break ;
		j++;
	}
}

static void	parse_arguments(char *s, int i, t_data *dt)
{
	while (i >= 0)
	{
		while (ft_isdigit(s[i]) && i >= 0)
			i--;
		if (s[i + 1] == '0' && dt->padd == 0 && dt->zero == 0)
			dt->zero = ft_atoi(&s[i + 2]);
		if (s[i] == '.' && dt->dot == 0)
			dt->dot = ft_isdigit(s[i + 1]) ? ft_atoi(&s[i + 1]) : -1;
		else if (s[i] == '#')
			dt->hash = 1;
		else if (s[i] == '+')
			dt->more = 1;
		else if (s[i] == '-')
			dt->less = 1;
		else if (s[i] == ' ')
			dt->space = 1;
		if ((s[i] == '-' || s[i] == '+' || s[i] == '#' || s[i] == ' '
			|| s[i] == '%') && ft_isdigit(s[i + 1]) && s[i + 1] != '0'
				&& dt->zero == 0 && dt->padd == 0)
			dt->padd = ft_atoi(&s[i + 1]);
		i--;
	}
}

void		parse_specifier(char *s, int i, t_types *typ, t_data *dt)
{
	ft_bzero(dt, sizeof(t_data));
	ft_bzero(typ, sizeof(t_types));
	parse_arguments(s, i - 1, dt);
	parse_length_modifier(s, i, typ);
	typ->dot = dt->dot > 0 ? dt->dot : 6;
}
