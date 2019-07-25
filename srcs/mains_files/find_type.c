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

int		find_specifier(char *s)
{
	int	i;

	i = 0;
	if (s[i - 1] == '%')
		return (0);
	if (s[i - 1] == 'z' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		return (1);
	else if (s[i - 1] == 'h' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		return (1);
	else if (s[i - 1] == 'l' && (s[i] == 'b' || s[i] == 'u' || s[i] == 'o' || s[i] == 'x' || s[i] == 'X'))
		return (1);
	else if (s[i - 1] == 'h' && (s[i] == 'd' || s[i] == 'i'))
		return (1);
	else if (s[i - 1] == 'l' && (s[i] == 'd' || s[i] == 'i'))
		return (1);	
	else if (s[i] == 'i' && s[i + 1] == 'b')
		return (1);
	else if (s[i - 1] == 'L' && s[i - 1] == 'f')
		return (1);
	return (0);
}

int		good_specifier(char c)
{
	if (c != ' ' && c != '.' && c != '#' && c != '+' && c != '-'
		&& !ft_isdigit(c) && c != 'l' && c != 'h' && c != 'L' && c != '%')
		return (1);
	return (0);
}

int		good_type(char c)
{
	if (c != 'b' && c != 'd' && c != 'i' && c != 'o' && c != 'u' && c != 'x'
		&& c != 'X' && c != 'c' && c!= 's' && c != 'p' && c != 'f' && c != 'n'
			&& c != 'r' && c != '%')
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