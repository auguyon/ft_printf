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
			if (ft_strnccmp(begin + j, tab->color[i],
				ft_strlen(tab->color[i])) == 0)
			{
				while (begin[j] != '}')
					j++;
				j++;
				break ;
			}
			i++;
		}
	}
	return (j);
}

static int	len_of_copy(char *begin, char *end, t_color *tab, int i)
{
	int len;

	len = 0;
	while (begin[i] && (begin + i) != end)
	{
		if ((begin[i] == '%' || begin[i] == '{')
				&& (i += (pass_flag(begin + i, tab, 0, 0) > 0)))
		{
			i += 0;
		}
		else
			len++;
		i++;
	}
	return (len);
}

static int	copy_before(char *begin, char *end, t_color *tab, int i)
{
	char	*to_paste;
	int		len;
	int		j;

	j = 0;
	if (*end == '\n' || *(end + 1) == '\0')
		end++;
	len = len_of_copy(begin, end, tab, 0);
	if (!(to_paste = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (begin[j] && i < len)
	{
		if (begin[j] && (begin[j] == '%' || begin[j] == '{'))
			j += pass_flag(begin + j, tab, 0, 0);
		to_paste[i++] = begin[j++];
	}
	to_paste[i] = '\0';
	buffer_cat_free(to_paste, i, 1);
	if (begin[j] && (*(begin + j) == '%' || *(begin + j) == '{'))
		j += pass_flag(begin + j, tab, 0, 0);
	return (j);
}

int			parse(char *str, va_list args, t_color *tab, int len)
{
	char	*cpy;
	int		reset_color;

	cpy = str;
	reset_color = 0;
	while (*str)
	{
		if (*str && (*str == '\n' || *str == '%' || *str == '{'))
			cpy += copy_before(cpy, str, tab, 0);
		if (*str && *str == '\n' && (len += g_buff.len))
			ft_print_buffer();
		else if (*str && *str == '%')
			str += parse_flag(str, args, reset_color);
		else if (*str && *str == '{' && (verify_color(str, tab) >= 0))
			str += parse_color(str, tab, &reset_color);
		if (*str != '%')
			str++;
	}
	if (*str == '\0' && *cpy)
		copy_before(cpy, str, tab, 0);
	if (reset_color == 1)
		buffer_cat_free("\033[0m", 7, 0);
	len += (len == 0 || len > g_buff.len) ? g_buff.len : 0;
	g_buff.w_len = 0;
	return (len);
}
