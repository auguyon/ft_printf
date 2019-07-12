/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ulong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:36:40 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/04 20:36:41 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_dec_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_unsi");
	return (ft_ustoa((unsigned short)(va_arg(args, int))));
}

char	*ft_convert_binary_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_binary");
	return (ft_ustoa_base((unsigned short)(va_arg(args, int)), 2));
}

char	*ft_convert_octal_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_octal");
	return (ft_ustoa_base((unsigned short)(va_arg(args, int)), 8));
}

char	*ft_convert_hexa_min_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_min");
	return (ft_ustoa_base((unsigned short)(va_arg(args, int)), 16));
}

char	*ft_convert_hexa_caps_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_hexa_caps");
	return (ft_ustoa_base_caps((unsigned short)(va_arg(args, int)), 16));
}
