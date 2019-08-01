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

static char	*process_formats_float(t_data *dt, char *res, char flag)
{
	if (dt->dot > 0 || dt->dot == -1)
		res = precision_float(dt->dot, res);
	else
		res = precision_float(6, res);
	if (dt->more > 0)
		res = ft_more_format_nb(flag, res);
	if (dt->zero == 0 && dt->padd == 0 && dt->space == 1)
		res = ft_padding_format(res, dt->padd, dt->less, dt->space);
	if (dt->zero > 0 || dt->padd > 0)
	{
		if (dt->zero > 0 && dt->less == 0)
			res = ft_zero_format(res, (dt->zero > 0 ? dt->zero
				: dt->dot), (dt->zero > 0 ? 0 : 1), dt->space);
		if (dt->padd > 0 || (dt->zero > 0 && dt->less > 0))
			res = ft_padding_format(res, (dt->padd > 0 ? dt->padd
				: dt->zero), dt->less, dt->space);
	}
	return (res);
}

static char	*process_formats_char(t_data *dt, char *res, char flag)
{
	if (dt->dot > 0 && flag == 's')
		return (ft_precision_format_char(res, dt->dot));
	if (dt->padd > 0 || (dt->zero > 0 && dt->less > 0))
	{
		res = ft_padding_format_char(res, (dt->zero > 0 ? dt->zero
			: dt->padd), dt->less);
	}
	else if (dt->zero > 0)
		res = ft_zero_format_char(res, dt->zero, dt->less);
	return (res);
}

static int	special_change_process(t_data *dt, char **res)
{
	if (dt->zero > 0 && dt->dot > 0)
	{
		dt->padd = dt->zero;
		dt->zero = 0;
	}
	if (dt->dot != -1 && dt->padd > dt->dot)
	{
		dt->dot -= 1;
	}
	if (dt->dot == -1 && *res[0] == '0' && *res[1] == '\0')
	{
		*res[0] = ' ';
		return (1);
	}
	return (0);
}

static char	*process_formats_nb(t_data *dt, char *res, char flag)
{
	if (special_change_process(dt, &res))
		return (res);
	if (dt->space > 0 && dt->more == 0 && dt->padd == 0 && dt->dot == 0
		&& dt->zero == 0 && (flag == 'd' || flag == 'i'))
		return (ft_zero_format(res, 0, 0, dt->space));
	if (dt->more > 0 && dt->hash == 0)
		res = ft_more_format_nb(flag, res);
	if (dt->hash > 0 && (flag == 'b' || flag == 'o' || flag == 'x'
		|| flag == 'X'))
		res = ft_hash_format_nb(flag, res);
	if (dt->zero > 0 || dt->dot > 0 || dt->padd > 0)
	{
		if ((dt->zero > 0 && dt->less == 0) || dt->dot > 0)
			res = ft_zero_format(res, (dt->zero > 0 ? dt->zero
				: dt->dot), (dt->zero > 0 ? 0 : 1), dt->space);
		if ((dt->padd > 0 && dt->dot < dt->padd)
			|| (dt->zero > 0 && dt->less > 0))
			res = ft_padding_format(res, (dt->padd > 0 ? dt->padd
				: dt->zero), dt->less, dt->space);
	}
	return (res);
}

char		*process_formats(t_data *dt, char *res, char flag)
{
	if (flag == 's' && !ft_strncmp(res, "(null)", 6))
		return (res);
	else if (flag == 's' && dt->dot == -1)
	{
		free(res);
		return (NULL);
	}
	if (flag == 'f' || flag == 'F')
		res = process_formats_float(dt, res, flag);
	else if (dt->dot == 0 && dt->zero == 0 && dt->space == 0 && dt->hash == 0
		&& dt->more == 0 && dt->less == 0 && dt->padd == 0)
		return (res);
	else if (flag == 'd' || flag == 'i' || flag == 'b' || flag == 'u'
				|| flag == 'o' || flag == 'x' || flag == 'X' || flag == 'p')
		res = process_formats_nb(dt, res, flag);
	else if (flag == 's' || flag == 'c')
		res = process_formats_char(dt, res, flag);
	return (res);
}
