/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:49 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/24 16:09:50 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_double(va_list args)
{
	return (ft_dtoa((va_arg(args, double)), 16));
}

char	*ft_convert_long_double(va_list args)
{
	return (ft_ldtoa((va_arg(args, long double)), 16));
}
