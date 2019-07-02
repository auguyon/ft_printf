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

#include "../includes/ft_printf.h"

static int	ft_pass_flag_or_color(char *begin, t_color *tab) // merde quelque part
{
	int	j;

	j = 0;
// printf("%s\n", "---- ft_pass_flag_or_color ----");
	if (begin[j] == '%' && begin[j + 1] == '%')
		j += 2;
	else if (begin[j] == '%')
	{
		j += (ft_find_type(begin + j));
		j++;
	}
	if (begin[j] == '{')
	{
		if ((ft_strcmp(*tab->color++, (begin + j))) == 0)
			while (begin[j] != '}')
				j++;
	}
// printf("Retour de j->%d\n", j);
	return (j);
}

static int	ft_copy_before_flag(char *begin, char *end, t_color *tab)
{
	char	*to_paste;
	char	*cpy;
	int		len;
	int		i;
	int		j;

// printf("%s\n", "---- ft_copy_before_flag ----");
	len = 0;
	j = 0;
// printf("begin ->%s && end ->%s\n", begin, end);
	cpy = begin;
	while (*cpy && cpy != end && ++len && !(i = 0))
	{
		if (*cpy == '%' || *cpy == '{')
			cpy += ft_pass_flag_or_color(cpy, tab);
		else
			cpy++;
	}
	if (!(to_paste = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		if (begin[j] == '%' || begin[j] == '{')
			j += ft_pass_flag_or_color(begin + j, tab);
		to_paste[i++] = begin[j++];
	}
// printf("to_paste-> %s && i-> %u && size-> %zu\n\n", to_paste, i , ft_strlen(to_paste));
	ft_strlcat_mod(to_paste, i);
	free(to_paste);
	return (j);
}

int			ft_parse(char *str, va_list args, t_color *tab)
{
	char	*tmp;
	int		len;

	len = g_buff->len;
	tmp = str;
	while (*str) // fct verifier si il ya un % et verifier si il est bon
	{
		if (*str && ((*str == '%' ) || *str == '{' || *str == '\n'))
			tmp += ft_copy_before_flag(tmp, str, tab);
		if (*str && *str == '\n')
			ft_print_buffer();
		else if (*str && *str == '%')
		{
			ft_search_type(str + 1, args);
			str += ft_find_type(str);
			printf("-%s-\n", str);
		}
		else if (*str && *str == '{')
			str += ft_parse_color(str, tab, args);
		str++;
	}
	if (*tmp)
		ft_copy_before_flag(tmp, --str, tab);
	g_buff->w_len = 0;
	return ((g_buff->len - len));
}