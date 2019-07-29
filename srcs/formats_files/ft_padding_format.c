/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:31 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_zero_format(char *res, unsigned int zero, short pre, short space)
{
	unsigned int	len_res;
	unsigned int	i;
	char			tmp[zero];

	i = 0;
	len_res = ft_strlen(res);
	if (len_res >= zero)
		return (space == 1 && res[0] != '-' ? ft_strjoin_free(" ", res, 2) : res);
	zero = zero - len_res;
	while (i < (zero + pre))
		tmp[i++] = '0';
	tmp = ft_strjoin(tmp, res);
	if (res[0] == '-' || res[0] == '+')
	{
		tmp[0] = (res[0] == '-' ? '-' : '+');
		tmp[i] = '0';
	}
	space == 1 && res[0] != '-' ? tmp[0] == ' ' : 0;
	free(res);
	return (tmp);
}

char	*ft_padding_format(char *res, unsigned int padd, short less, short space)
{
	unsigned int	len_res;
	unsigned int	i;
	char			tmp[padd];

	i = 0;
	len_res = ft_strlen(res);
	if (len_res >= padd)
		return (space == 1 && res[0] != '-' ? ft_strjoin_free(" ", res, 2) : res);
	padd = (padd - len_res) - less;
	if (res[0] == '-' && less == 0)
		padd -= 1;
	while (i < padd)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	tmp = (less == 1 ? ft_strjoin(res, tmp) : ft_strjoin(tmp, res));
	tmp = (space == 1 && res[0] != '-' && less == 1 ? ft_strjoin_free(" ", tmp, 2) : tmp);
	free(res);
	return (tmp);
}
