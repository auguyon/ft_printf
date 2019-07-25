/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:45:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 16:46:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	pass_flag(char *begin, t_color *tab, int i, int j)
{
	if (begin[j] == '%' && begin[j + 1] == '%')
		j += 2;
	else if (begin[j] == '%')
	{
		if ((j = find_type(begin + j)))
			if (j == -1)
				j += 1;
		j++;
	}
	if (begin[j] == '{')
	{
		while (i < 20)
		{
			if (ft_strnccmp(begin + j, tab->color[i], ft_strlen(tab->color[i])) == 0)
			{
				while (begin[j] != '}')
					j++;
				j++;
				break;
			}
			i++;
		}
	}
DEBUG == 1 ? printf("retour de pass flag -->%d\n", j) : 0;
	return (j);
}

static int	copy_before(char *begin, char *end, t_color *tab, int i, int j)
{
	char	*to_paste;
	int		len;

	len = 0;
	if (*begin == '%' && *end == '%')
		return (0);
	if (*end == '\n' || *(end + 1) == '\0')
		end++;
	while (begin[i] && (begin + i) != end)
	{
		if ((begin[i] == '%' || begin[i] == '{') && (i += (pass_flag(begin + i, tab, 0, 0) > 0)))
			i += 0;
		else
			len++;
		i++;
	}
	if (!(to_paste = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
DEBUG == 1 ? printf("len -> |%d|\n", len) : 0;
	while (begin[j] && i < len)
	{
		if (begin[j] && (begin[j] == '%' || begin[j] == '{'))
			j += pass_flag(begin + j, tab, 0, 0);
		to_paste[i++] = begin[j++];
	}
	to_paste[i] = '\0';
DEBUG == 1 ? printf("to_paste-> |%s|\n", to_paste) : 0;
	ft_strlcat_mod(to_paste, i);
DEBUG == 1 ? printf("begin-> |%s|\n", begin + j) : 0;
	if (begin[j] && *(begin + j) == '%')
		j += pass_flag(begin + j, tab, 0, 0);
	return (j);
}

int		parse(char *str, va_list args, t_color *tab)
{
	char	*cpy;
	int		len;
	int		reset_color;

	cpy = str;
	len = 0;
	reset_color = 0;
	while (*str)
	{
DEBUG == 1 ? printf("str -> |%.5s|\n", str) : 0;
DEBUG == 1 ? printf("cpy -> |%s|\n", cpy) : 0;
		if (*str && (*str == '\n' || *str == '%' || *str == '{'))
		{
			cpy += copy_before(cpy, str, tab, 0, 0);
DEBUG == 1 ? printf("After before-> |%s|\n", cpy) : 0;
		}
		if (*str && *str == '\n' && (len = g_buff->len))
			ft_print_buffer();
		else if (*str && *str == '%')
		{
			str += parse_flag(str, args, reset_color);
DEBUG == 1 ? printf("After Parse-> |%s|\n", str) : 0;
		}
		else if (*str && *str == '{' && (verify_color(str, tab) >= 0))
		{
			str += parse_color(str, tab, &reset_color);
		}
		str++;
	}
	if ((len == 0 ? (len = g_buff->len) : 1) && *str == '\0' && *cpy)
		copy_before(cpy, str, tab, 0, 0);
	if ((len += 1) && reset_color == 1)
		ft_strlcat_mod("\033[0m", 7);
	g_buff->w_len = 0;
	return (len);
}
