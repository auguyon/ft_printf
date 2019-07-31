/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:21:38 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/25 23:21:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_float(va_list args, t_types *typ)
{
	if (typ->lc == 1)
		return (ft_ldtoa((va_arg(args, long double)), typ->dot));
	return (ft_dtoa((va_arg(args, double)), typ->dot));
}
