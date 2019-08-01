/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:20:07 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/25 23:20:08 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_dec(va_list args, t_types *typ)
{
	if (typ->h == 1)
		return (ft_stoa((short)(va_arg(args, int))));
	else if (typ->hh == 1)
		return (ft_ctoa((char)(va_arg(args, int))));
	else if (typ->l == 1)
		return (ft_lltoa((va_arg(args, long))));
	else if (typ->ll == 1)
		return (ft_lltoa((va_arg(args, long long))));
	else if (typ->z == 1)
		return (ft_ztoa((va_arg(args, size_t))));
	return (ft_itoa((va_arg(args, int))));
}
