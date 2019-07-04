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

#include "../../includes/ft_printf.h"

char	*ft_convert_base(va_list args)
{
	return (ft_itoa_base_caps((va_arg(args, int)), va_arg(args, int)));
}

char	*ft_convert_dec(va_list args)
{
printf("----- %s -----\n", "ft_convert_dec");
	return (ft_itoa((va_arg(args, int))));
}

char	*ft_convert_dec_short(va_list args)
{
printf("----- %s -----\n", "ft_convert_dec");
	return (ft_stoa((va_arg(args, int))));
}

char	*ft_convert_dec_long(va_list args)
{
printf("----- %s -----\n", "ft_convert_dec");
	return (ft_ulltoa((va_arg(args, int))));
}
