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

static char	*process_formats_char(t_data *dt, char *res, char flag)
{
	if (!ft_strncmp(res, "(null)", 6))
		return (res);
	if (dt->dot == -1 && flag == 's')
	{
		free(res);
		return (NULL);
	}
	if (dt->padd > 0)
	{
		if (dt->less == 0)
			res = ft_space_format(flag, res, dt->space, dt->padd);
		else
			res = ft_space_format_rev(flag, res, dt->space, dt->padd);
	}
	if (dt->zero > 0)
	{
		if (dt->less == 0)
			res = ft_zero_format(flag, res, dt->zero);
		else
			res = ft_space_format_rev(flag, res, 0, dt->zero);
	}
	if (dt->dot > 0 && flag == 's')
		res = ft_precision_format_char(flag, res, dt->dot);
	return (res);
}

static char	*process_formats_nb(t_data *dt, char *res, char flag)
{
	if (dt->more > 0 && dt->hash == 0)
		res = ft_more_format_nb(flag, res);
	if (dt->hash > 0 && (flag == 'o' || flag == 'x' || flag == 'X'))
		res = ft_hash_format_nb(flag, res);
	if (dt->dot > 0)
		res = ft_precision_format_nb(flag, res, dt->dot);
	if (dt->zero > 0)
	{
		if (dt->less == 0)
			res = ft_zero_format(flag, res, dt->zero);
		else
			res = ft_space_format_rev(flag, res, 0, dt->zero);
	}
	if (dt->padd > 0 || (dt->space > 0 && !(flag == 'o' || flag == 'x'
		|| flag == 'X' || flag == 'u' || flag == 'p')))
	{
		if (dt->less == 0)
			res = ft_space_format(flag, res, dt->space, dt->padd);
		else
			res = ft_space_format_rev(flag, res, dt->space, dt->padd);
	}
	return (res);
}

char		*process_formats(t_data *dt, char *res, char flag)
{
	// printf("dot->%zd zero->%d space->%d hash->%d more->%d less->%d padd->%d\n", dt->dot,dt->zero, dt->space, dt->hash, dt->more,dt->less, dt->padd);
	if ((dt->dot == 0 && dt->zero == 0 && dt->space == 0 && dt->hash == 0
			&& dt->more == 0 && dt->less == 0 && dt->padd == 0) && (flag != 'f'
				&& flag != 'F'))
		return (res);
	if (flag == 'd' || flag == 'i' || flag == 'b' || flag == 'u' || flag == 'o'
			|| flag == 'x' || flag == 'X' || flag == 'p')
		res = process_formats_nb(dt, res, flag);
	else if (flag == 'f' || flag == 'F')
		res = process_formats_float(dt, res, flag);
	else if (flag == 's' || flag == 'c')
		res = process_formats_char(dt, res, flag);
	return (res);
}