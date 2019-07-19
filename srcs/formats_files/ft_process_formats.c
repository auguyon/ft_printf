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

char	*ft_modulo_format(t_data *dt)
{
	char *s;

	if (dt->padd > 0 && dt->less == 0)
		s = ft_space_format_nb('i', "%", dt->space, dt->padd);
	else if (dt->padd > 0 && dt->less > 0)
		s = ft_space_format_nb_rev('i', "%", dt->space, dt->padd);
	return (s);
}

char	*ft_process_flags_nb(t_data *dt, char *res, char flag)
{
if (DEBUG == 1)
	printf("---- %s ----\n", "Process Flags NB");
	if (dt->more > 0 && dt->hash == 0)
		res = ft_more_format_nb(flag, res);
	if (dt->less > 0 && dt->hash == 0 && dt->space == 0)
		res = ft_less_format_nb(flag, res);
	if (dt->hash > 0 && (flag == 'o' || flag == 'x' || flag == 'X'))
		res = ft_hash_format_nb(flag, res);
	if (dt->dot > 0)
		res = ft_precision_format_nb(flag, res, dt->dot);
	if (dt->zero > 0)
		res = ft_zero_format_nb(flag, res, dt->zero);
	if (dt->space > 0 || dt->padd > 0)
	{
		if (dt->less == 0)
			res = ft_space_format_nb(flag, res, dt->space, dt->padd);
		else if (dt->less > 0)
			res = ft_space_format_nb_rev(flag, res, dt->space, dt->padd);
	}
	return (res);
}

char	*ft_process_flags(t_data *dt, char *res, char flag)
{
if (DEBUG == 1)
	printf("---- %s ----\n", "Process Flags");
	if (flag == 'd' || flag == 'i' || flag == 'b' || flag == 'u' || flag == 'o'
			|| flag == 'x' || flag == 'X' || flag == 'f' || flag == 'F')
		res = ft_process_flags_nb(dt, res, flag);
	if (dt->mod > 0)
		return (ft_modulo_format(dt));
	// else if (flag == 's' || flag == 'c')
	// 	res = ft_process_flags_char(dt, res, flag);
	return (res);
}