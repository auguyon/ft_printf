/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:57:24 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/04 19:57:26 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_dec_uint(va_list args)
{
	return (ft_utoa((va_arg(args, unsigned int))));
}

char	*ft_convert_binary_uint(va_list args)
{
	return (ft_utoa_base((va_arg(args, unsigned int)), 2));
}

char	*ft_convert_octal_uint(va_list args)
{
	return (ft_utoa_base((va_arg(args, unsigned int)), 8));
}

char	*ft_convert_hexa_min_uint(va_list args)
{
	return (ft_utoa_base((va_arg(args, unsigned int)), 16));
}

char	*ft_convert_hexa_caps_uint(va_list args)
{
	return (ft_utoa_base_caps((va_arg(args, unsigned int)), 16));
}
