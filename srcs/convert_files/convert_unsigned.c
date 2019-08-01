/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:20:20 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/25 23:20:21 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_binary(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_ustoa_base((unsigned short)(va_arg(args, unsigned int)), 2));
	else if (typ->hh == 1)
		return (ft_utoa_base((unsigned char)(va_arg(args, int)), 2));
	else if (typ->l == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long)), 2));
	else if (typ->ll == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long long)), 2));
	else if (typ->z == 1)
		return (ft_ztoa_base((va_arg(args, size_t)), 2));
	return (ft_utoa_base((va_arg(args, unsigned int)), 2));
}

char	*convert_octal(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_ustoa_base((unsigned short)(va_arg(args, unsigned int)), 8));
	else if (typ->hh == 1)
		return (ft_uctoa_base((unsigned char)(va_arg(args, unsigned int)), 8));
	else if (typ->l == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long)), 8));
	else if (typ->ll == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long long)), 8));
	else if (typ->z == 1)
		return (ft_ztoa_base((va_arg(args, size_t)), 8));
	return (ft_utoa_base((va_arg(args, unsigned int)), 8));
}

char	*convert_unsig_dec(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_ustoa((unsigned short)(va_arg(args, unsigned int))));
	else if (typ->hh == 1)
		return (ft_utoa((unsigned char)(va_arg(args, unsigned int))));
	else if (typ->l == 1)
		return (ft_ulltoa((va_arg(args, unsigned long))));
	else if (typ->ll == 1)
		return (ft_ulltoa((va_arg(args, unsigned long long))));
	else if (typ->z == 1)
		return (ft_ztoa((va_arg(args, size_t))));
	return (ft_utoa((va_arg(args, unsigned int))));
}

char	*convert_hexa(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_ustoa_base((unsigned short)(va_arg(args, unsigned int))
			, 16));
	else if (typ->hh == 1)
		return (ft_utoa_base((unsigned char)(va_arg(args, unsigned int)), 16));
	else if (typ->l == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long)), 16));
	else if (typ->ll == 1)
		return (ft_ulltoa_base((va_arg(args, unsigned long long)), 16));
	else if (typ->z == 1)
		return (ft_ztoa_base((va_arg(args, size_t)), 16));
	return (ft_utoa_base((va_arg(args, unsigned int)), 16));
}

char	*convert_hexa_caps(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_ustoa_base_caps((unsigned short)(va_arg(args, unsigned int))
			, 16));
	else if (typ->hh == 1)
		return (ft_uctoa_base_caps((unsigned char)(va_arg(args, unsigned int))
			, 16));
	else if (typ->l == 1)
		return (ft_ulltoa_base_caps((va_arg(args, unsigned long)), 16));
	else if (typ->ll == 1)
		return (ft_ulltoa_base_caps((va_arg(args, unsigned long long)), 16));
	else if (typ->z == 1)
		return (ft_ztoa_base_caps((va_arg(args, size_t)), 16));
	return (ft_utoa_base_caps((va_arg(args, unsigned int)), 16));
}
