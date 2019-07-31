/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_format_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:31 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_precision_format_char(char *res, unsigned int pre)
{
	char			*output;

	if (pre < ft_strlen(res))
	{
		res[pre] = '\0';
		output = ft_strsub(res, 0, pre);
		free(res);
		return (output);
	}
	return (res);
}

char	*ft_zero_format_char(char *res, unsigned int zero, short pre)
{
	char			tmp[zero];
	unsigned int	len_res;
	unsigned int	i;

	i = 0;
	len_res = ft_strlen(res);
	if (len_res >= zero)
		return (res);
	zero = zero - len_res;
	while (i < (zero + pre))
		tmp[i++] = '0';
	tmp[i] = '\0';
	res = ft_strjoin_free(tmp, res, 2);
	return (res);
}

char	*ft_padding_format_char(char *res, unsigned int padd, short less)
{
	char			tmp[padd];
	unsigned int	len_res;
	unsigned int	i;

	i = 0;
	len_res = ft_strlen(res);
	if (len_res >= padd)
		return (res);
	padd = padd - len_res;
	while (i < padd)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	res = (less == 1 ? ft_strjoin_free(res, tmp, 1)
		: ft_strjoin_free(tmp, res, 2));
	return (res);
}
