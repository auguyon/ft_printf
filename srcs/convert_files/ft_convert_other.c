/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:43:34 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/06 19:44:03 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert_adress(va_list args)
{
	char	*output;
	char	*tmp;

printf("----- %s -----\n", "ft_convert_adress");
	tmp = ft_itoa((va_arg(args, int)));
	if (!(output = (char*)malloc(sizeof(*tmp) * (ft_strlen(tmp) + 3))))
		return (NULL);
	output = ft_strcat("0x", tmp);
	return (output);
}

char	*ft_convert_value_n(va_list args)
{
	int		*ptr;

printf("----- %s -----\n", "ft_convert_value_n");
	ptr = va_arg(args, int*);
	*ptr = g_buff->w_len;
	printf("w_len->%d\n", g_buff->w_len);
	return(NULL);
}

char	*ft_convert_iso(va_list args)
{
	unsigned long	date;
	char			*res;

printf("----- %s -----\n", "ft_convert_iso");
	date = va_arg(args, unsigned long);
	if (date < 100000000)
	{
		printf("%s\n", "date");
		res = ft_ultoa_iso_format(date, 7);
	}
	else if (date < 100000000000000 && date >= 10000000000000)
	{
		printf("%s\n", "date et heure");
		res = ft_ultoa_iso_format(date, 13);
	}
	else
	{
		printf("%s\n", "pas valide");
		res = NULL;
	}
	return (res);
}