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

int		ft_parse_color(char *s, t_color *tab, int *code_color)
{
	int		i;
	int		j;
printf("---- %s ----\n", "ft_parse_color");
	j = 0;
	printf("%s\n", s);
	if ((i = (ft_verify_color(s, tab))) != 20)
	{
		printf("Application couleur ->%s\n", tab->color[i]);
		ft_strlcat_mod(tab->color_flag[i], 5);
	}
	else
		return (0);
	j = (int)ft_strlen(tab->color[i]);
	if (s[j] == '%')
		*(code_color) = 2;
	else if (i == 0)
		*(code_color) = 0;
	else
		*(code_color) = 1;
	return (j);
}
