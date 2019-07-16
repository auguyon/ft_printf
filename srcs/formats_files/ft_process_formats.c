/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:53:06 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/16 17:53:07 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_process_flags_nb(t_data *dt, char *res, char flag)
{
	if (dt->hash != 0 && (flag == 'o' || flag == 'x' || flag == 'X'))
		res = ft_hash_format_nb(flag, res);
	if (dt->more != 0)
		res = ft_more_format_nb(flag, res);
	if (dt->less != 0)
		res = ft_less_format_nb(flag, res);
	if (dt->dot != 0)
		res = ft_precision_format_nb(flag, res, dt->dot);
	if (dt->zero != 0)
		res = ft_zero_format_nb(flag, res, dt->zero);
	if (dt->space != 0)
		res = ft_space_format_nb(flag, res, dt->space);
	return (res);
}

char	*ft_process_flags(t_data *dt, char *res, char flag)
{
	if (flag == 'd' || flag == 'i' || flag == 'b' || flag == 'u' || flag == 'o'
			|| flag == 'x' || flag == 'X' || flag == 'f' || flag == 'F')
		res = ft_process_flags_nb(dt, res, flag);
	// else if (flag == 's' || flag == 'c')
	// 	res = ft_process_flags_char(dt, res, flag);
	return (res);
}