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
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (begin[j] == '%' && begin[j + 1] == '%')
		j += 2;
	else if (begin[j] == '%')
	{
		j += (ft_find_type(begin + j));
		j++;
	}
	if (begin[j] == '{')
	{
		while ((k = (ft_strnccmp((&begin[j]), tab->color[i], ft_strlen(tab->color[i]))) != 0))
			i++;
		if (k == 0)
			while (begin[j] != '}')
				j++;
		j++;
	}
	// printf("retour de ft_pass_flag_or_color ->%d\n", j);
	return (j);
}

static int	ft_copy_before_flag(char *begin, char *end, t_color *tab, int i, int j)
{
	char	*to_paste;
	char	*cpy;
	int		len;
if (DEBUG == 1)
{
printf("%s\n", "---- ft_copy_before_flag ----");
printf("begin-> |%s| && end-> |%s|\n", begin, end);
}
	len = 0;
	cpy = begin;
	if (*end == '\n')
		end++;
	if (end[len + 1] == '\0')
		end++;
	if (*cpy == '%' || *cpy == '{')
		cpy += ft_pass_flag_or_color(cpy, tab);
	while (*cpy && cpy != end)
	{
		if (*cpy == '%' || *cpy == '{')
			cpy += ft_pass_flag_or_color(cpy, tab);
		else
			cpy++;
// printf(" cpy -> |%s|\n", cpy);
		len++;
	}
if (DEBUG == 1)
	printf("len ->%d\n", len);
	if (!(to_paste = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		if (begin[j] == '%' || begin[j] == '{')
			j += ft_pass_flag_or_color(begin + j, tab);
		to_paste[i++] = begin[j++];
	}
	to_paste[i + 1] = '\0';
if (DEBUG == 1)
	printf("to_paste-> |%s| && \t\ti-> |%u| && \t\tsize-> |%zu|\n\n", to_paste, i , ft_strlen(to_paste));
	ft_strlcat_mod(to_paste, i);
	free(to_paste);
	return (j);
}

int			ft_parse(char *str, va_list args, t_color *tab)
{
	char	*tmp;
	int		len;
	int		code_color;

	len = g_buff->len;
	tmp = str;
	code_color = 0;
	while (*str) // fct verifier si il ya un % et verifier si il est bon
	{
		if (!(*str == '%' && *tmp == '%') && (*str == '%' || *str == '\n' || *str == '{'))
		{
			tmp += ft_copy_before_flag(tmp, str, tab, 0, 0);
			printf("tmp -> |%s|\n", tmp);
		}
		if (*str && *str == '\n')
		{
			if (DEBUG == 1)
			{
				printf("str |%s| tmp |%s|\n", str, tmp);
				printf("%d\n", g_buff->len);
			}
			ft_print_buffer();
		}
		else if (*str && *str == '%')
		{
			if (DEBUG == 1)
				printf("|%s| |%s|\n", "find_%", str);
			if (DEBUG == 1)
				printf("code_color ->%d\n", code_color);
			ft_search_type(str + 1, args, code_color);
			str += ft_find_type(str);
		}
		else if (*str && *str == '{')
			tmp += ft_parse_color(str, tab, &code_color);
		str++;
	}
	if (*tmp)
		ft_copy_before_flag(tmp, --str, tab, 0, 0);
	if (code_color == 1)
		ft_strlcat_mod("\033[0m", 7);
	g_buff->w_len = 0;
	return ((g_buff->len - len));
}