/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:22:40 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/25 23:22:49 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*convert_adress(va_list args, t_types *typ)
{
	char	*output;
	char	*tmp;

	(void)typ;
	if (!(tmp = ft_ulltoa_base((va_arg(args, unsigned long long)), 16)))
		return (NULL);
	output = ft_strjoin_free("0x", tmp, 2);
	return (output);
}

char		*convert_value_n(va_list args, t_types *typ)
{
	int	*ptr;

	(void)typ;
	ptr = va_arg(args, int*);
	*ptr = g_buff.w_len;
	return (NULL);
}

static char	*ft_ultoa_iso_format(unsigned long n, int format)
{
	unsigned long	b;
	char			*str;

	b = format;
	b += (format == 7) ? 2 : 6;
	if (!(str = (char*)malloc(sizeof(char) * b + 1)))
		return (0);
	str[b + 1] = '\0';
	if (b == 19)
		str[b--] = 'Z';
	while (b != 0)
	{
		str[b] = (n % 10) + '0';
		n = n / 10;
		b--;
		if (b == 10 && format == 13)
			str[b--] = 'T';
		else if (b == 16 || b == 13)
			str[b--] = ':';
		else if (b == 7 || b == 4)
			str[b--] = '-';
	}
	str[0] = (n % 10) + '0';
	return (str);
}

char		*convert_iso(va_list args, t_types *typ)
{
	unsigned long	date;
	char			*res;

	(void)typ;
	date = va_arg(args, unsigned long);
	if (date < 100000000)
		res = ft_ultoa_iso_format(date, 7);
	else if (date < 100000000000000 && date >= 10000000000000)
		res = ft_ultoa_iso_format(date, 13);
	else
		res = NULL;
	return (res);
}
