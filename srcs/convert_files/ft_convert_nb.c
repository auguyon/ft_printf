/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:06:34 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/06 19:06:52 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert_dec(va_list args)
{
printf("----- %s -----\n", "ft_convert_dec");
	return (ft_itoa((va_arg(args, int))));
}

char	*ft_convert_size(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoa((va_arg(args, size_t))));
}

char	*ft_convert_dec_unsigned(va_list args)
{
printf("----- %s -----\n", "ft_convert_unsi");
	return (ft_utoa((va_arg(args, unsigned int))));
}

char	*ft_convert_binary(va_list args)
{
printf("----- %s -----\n", "ft_convert_binary");
	return (ft_utoa_base((va_arg(args, unsigned int)), 2));
}

char	*ft_convert_octal(va_list args)
{
printf("----- %s -----\n", "ft_convert_octal");
	return (ft_utoa_base((va_arg(args, unsigned int)), 8));
}

char	*ft_convert_hexa_min(va_list args)
{
	char	*output;
printf("----- %s -----\n", "ft_convert_min");
	
	output = ft_utoa_base((va_arg(args, unsigned int)), 16);
	return (output);
}

char	*ft_convert_hexa_caps(va_list args)
{
printf("----- %s -----\n", "ft_convert_hexa_caps");
	return (ft_utoa_base_caps((va_arg(args, unsigned int)), 16));
}

char	*ft_convert_base(va_list args)
{
	return (ft_itoa_base_caps((va_arg(args, int)), va_arg(args, int)));
}

char	*ft_convert_long(va_list args)
{
	return (ft_lltoa(va_arg(args, long long)));
}