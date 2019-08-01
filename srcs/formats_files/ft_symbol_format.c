/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbol_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:18 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:19 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_hash_format_nb(char flag, char *res)
{
	if (flag == 'o')
		res = ft_strjoin_free("0", res, 2);
	else if (flag == 'x')
		res = ft_strjoin_free("0x", res, 2);
	else if (flag == 'X')
		res = ft_strjoin_free("0X", res, 2);
	else if (flag == 'b')
		res = ft_strjoin_free("0b", res, 2);
	return (res);
}

char	*ft_more_format_nb(char flag, char *res)
{
	char	*tmp;

	tmp = NULL;
	if (res[0] != '-' && (flag == 'd' || flag == 'i' || flag == 'f'
		|| flag == 'F'))
		tmp = ft_strjoin("+", res);
	else
		return (res);
	free(res);
	return (tmp);
}
