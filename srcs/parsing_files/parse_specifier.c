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

static void init_data_table(t_data *dt)
{
	dt->dot = 0;
	dt->zero = 0;
	dt->padd = 0;
	dt->hash = 0;
	dt->more = 0;
	dt->less = 0;
	dt->space = 0;
}

void 		parse_specifier(char *s, int i, t_data *dt)
{
	init_data_table(dt);
	i--;
	while (i >= 0)
	{
		while (ft_isdigit(s[i]) && i >= 0)
			i--;
		if (s[i + 1] == '0')
			dt->zero = ft_atoi(&s[i + 2]);
		if (s[i] == '.')
		{
			if (ft_isdigit(s[i + 1]))
				dt->dot = ft_atoi(&s[i + 1]);
			else
				dt->dot = -1;
		}
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
// printf("dot->%d zero->%d space->%d hash->%d more->%d less->%d padd->%d\n", dt->dot,dt->zero, dt->space, dt->hash, dt->more,dt->less, dt->padd);

}