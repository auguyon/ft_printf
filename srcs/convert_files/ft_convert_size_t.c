/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_size_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:42:54 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/04 19:42:55 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_binary_size_t(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoa_base((va_arg(args, size_t), 2)));
}

char	*ft_convert_octal_size_t(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoac_base((va_arg(args, size_t), 8)));
}

char	*ft_convert_dec_size_t(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoa((va_arg(args, size_t))));
}

char	*ft_convert_hexa_size_t(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoa_base((va_arg(args, size_t), 16)));
}

char	*ft_convert_hexa_caps_size_t(va_list args)
{
printf("----- %s -----\n", "ft_convert_size");
	return(ft_uztoa_base_caps((va_arg(args, size_t), 16)));
}
