/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:36:43 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 11:39:30 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		good_specifier(char c)
{
	if (c != ' ' && c != '.' && c != '#' && c != '+' && c != '-'
		&& !ft_isdigit(c) && c != 'l' && c != 'h' && c != 'L'
			&& c != '%' && c != 'z')
		return (1);
	return (0);
}

int		good_type(char c)
{
	if (c != 'b' && c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x'
		&& c != 'X' && c != 'c' && c != 's' && c != 'p' && c != 'f' && c != 'n'
			&& c != 'k' && c != '%' && c != 'F')
		return (0);
	return (1);
}

int		find_type(char *s)
{
	int i;

	i = 1;
	while (s[i] != '\0')
	{
		if (good_type(s[i]))
			return (i);
		else if (good_specifier(s[i]))
			return (-1);
		i++;
	}
	return (-1);
}
