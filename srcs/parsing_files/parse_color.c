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

int		verify_color(char *s, t_color *tab)
{
	int	i;

	i = 0;
	while ((ft_strnccmp(s, tab->color[i], ft_strlen(tab->color[i]))) != 0)
	{
		i++;
		if (i == 20)
			return (-1);
	}
	return (i);
}

int		parse_color(char *s, t_color *tab, int *code_color)
{
	int		i;
	int		j;

	j = 0;
	if ((i = verify_color(s, tab)) >= 0)
		buffer_cat_free(tab->color_flag[i], 5, 0);
	else
		return (0);
	j = (int)ft_strlen(tab->color[i]);
	if (s[j] == '%')
		*(code_color) = 2;
	else if (i == 0)
		*(code_color) = 0;
	else
		*(code_color) = 1;
	return (j - 1);
}
