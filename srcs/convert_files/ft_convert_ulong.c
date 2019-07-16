/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ulong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:43:32 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/04 20:43:34 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_dec_ullong(va_list args)
{
if (DEBUG == 1)
	printf("----- %s -----\n", "ft_convert_unsi");
	return (ft_ulltoa((va_arg(args, unsigned long))));
}

char	*ft_convert_binary_ullong(va_list args)
{
if (DEBUG == 1)
	printf("----- %s -----\n", "ft_convert_binary");
	return (ft_ulltoa_base((va_arg(args, unsigned long)), 2));
}

char	*ft_convert_octal_ullong(va_list args)
{
if (DEBUG == 1)
	printf("----- %s -----\n", "ft_convert_octal");
	return (ft_ulltoa_base((va_arg(args, unsigned long)), 8));
}

char	*ft_convert_hexa_min_ullong(va_list args)
{
if (DEBUG == 1)
	printf("----- %s -----\n", "ft_convert_min");
	return (ft_ulltoa_base((va_arg(args, unsigned long)), 16));
}

char	*ft_convert_hexa_caps_ullong(va_list args)
{
if (DEBUG == 1)
	printf("----- %s -----\n", "ft_convert_hexa_caps");
	return (ft_ulltoa_base_caps((va_arg(args, unsigned long)), 16));
}
