/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:40:16 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 13:42:01 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "string.h"
int		ft_verify_color(char *s, t_color *tab)
{
	int	i;

	i = 0;
	while ((ft_strnccmp(s, tab->color[i], ft_strlen(tab->color[i]))) != 0)
	{
		i++;
		if (i == 20)
			return (20);
	}
	return (i);
}

int		ft_parse_color(char *s, t_color *tab, va_list args)
{
	int		i;
	int		j;
printf("---- %s ----\n", "ft_parse_color");
	j = 0;
	if ((i = (ft_verify_color(s, tab))) != 20)
		ft_strlcat_mod(tab->color_flag[i], 7);
	else
		return (0);
	while (s[j] != '}')
		j++;
	j++;
	if (*s == '%')
	{
		ft_parse(s, args, tab);
		ft_strlcat_mod("\033[0m", 7);
	}
	return (j - 1);
}
