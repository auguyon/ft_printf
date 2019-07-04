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
	return (ft_ustoa((va_arg(args, unsigned short))));
}

char	*ft_convert_binary_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_binary");
	return (ft_ustoa_base((va_arg(args, unsigned short)), 2));
}

char	*ft_convert_octal_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_octal");
	return (ft_ustoa_base((va_arg(args, unsigned short)), 8));
}

char	*ft_convert_hexa_min_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_min");
	return (ft_ustoa_base((va_arg(args, unsigned short)), 16));
}

char	*ft_convert_hexa_caps_ushort(va_list args)
{
printf("----- %s -----\n", "ft_convert_hexa_caps");
	return (ft_ustoa_base_caps((va_arg(args, unsigned short)), 16));
}
