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

static int	ft_pass_flag_or_color(char *begin, t_color *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (begin[j] == '%' && begin[j + 1] == '%')
		j += 2;
	else if (begin[j] == '%')
	{
		j += (ft_find_type(begin + j));
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
if (DEBUG == 1)
	printf("retour de ft_pass_flag_or_color ->%d\n", j);
	return (j);
}

static int	ft_copy_before_flag(char *begin, char *end, t_color *tab, int i, int j)
{
	char	*to_paste;
	char	*cpy;
	int		len;

if (DEBUG == 1)
	printf("Copy before flag\nBegin-> |%.20s| End-> |%.10s|\n", begin, end);
	len = 0;
	cpy = begin;
	if ((*end == '%' && *(end + 1) != '%') && *begin == '%' )
		return (0);
	if (*end == '\n' || end[len + 1] == '\0')
		end++;
	if ((*begin == '%' || *begin== '{') && ((j = ft_pass_flag_or_color(begin, tab)) != 0))
		cpy += j;
if (DEBUG == 1)
	printf("after if ->\nBegin-> |%.20s| End-> |%.10s|\n", cpy, end);
	while (*cpy && cpy != end)
	{
		if ((*cpy == '%' || *cpy == '{') && ((i = ft_pass_flag_or_color(cpy, tab)) != 0))
				cpy += i;
		else
			cpy++;
		len++;
	}
if (DEBUG == 1)
	printf("len ->%d\n", len);
	if (!(to_paste = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		if (begin[j] == '%' || begin[j] == '{')
			j += ft_pass_flag_or_color(begin + j, tab);
		to_paste[i++] = begin[j++];
	}
	to_paste[i + 1] = '\0';
if (DEBUG == 1)
	printf("to_paste->|%s| && i->|%u| && size->|%zu| - Retour de copy before ->|%d|\n\n", to_paste, i , ft_strlen(to_paste), j);
	ft_strlcat_mod(to_paste, i);
	free(to_paste);
	return (j);
}

int		ft_parse(char *str, va_list args, t_color *tab)
{
	char	*tmp;
	int		len;
	int		reset_code_color;

	len = g_buff->len;
	tmp = str;
	reset_code_color = 0;
	while (*str)
	{
		if (*str && *str == '\n')
		{
			tmp += ft_copy_before_flag(tmp, str + 1, tab, 0, 0);
			ft_print_buffer();
		}
		else if (*str && *str == '%')
		{
			if (DEBUG == 1)
				printf("\n\navant ft_search_type !!!!!! ->|%s|\n\n", str);
			tmp += ft_copy_before_flag(tmp, str, tab, 0, 0);
			tmp += ft_search_type(str + 1, args, reset_code_color);
			if (*(str + 1) == '%')
				str += 2;
			if (DEBUG == 1)
				printf("TMP ap. Search Type-> |%s|\n", tmp);
		}
		else if (*str && *str == '{')
		{
			if (ft_verify_color(str, tab) >= 0)
			{
				tmp += ft_copy_before_flag(tmp, str, tab, 0, 0);
			if (DEBUG == 1)
				printf("TMP av. ft_parse_color |%s|\n", tmp);
				tmp += ft_parse_color(str, tab, &reset_code_color);
			if (DEBUG == 1)
				printf("TMP ap. ft_parse_color |%s|\n", tmp);
			}
		}
		str++;
		if (*str == '\0' && *tmp)
			ft_copy_before_flag(tmp, str, tab, 0, 0);
	}
	if (reset_code_color == 1)
		ft_strlcat_mod("\033[0m", 7);
	g_buff->w_len = 0;
	return ((g_buff->len - len));
}
