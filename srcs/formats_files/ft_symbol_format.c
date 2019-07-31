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
	char	*tmp;

	if (flag == 'o')
		tmp = ft_strjoin("0", res);
	else if (flag == 'x')
		tmp = ft_strjoin("0x", res);
	else if (flag == 'X')
		tmp = ft_strjoin("0X", res);
	else
		return (res);
	free(res);
	return (tmp);
}

char	*ft_more_format_nb(char flag, char *res)
{
	char	*tmp;

	tmp = NULL;
	if (res[0] != '-' && (flag == 'd' || flag == 'i' || flag == 'f'
		|| flag == 'F' || flag == 'b'))
		tmp = ft_strjoin("+", res);
	else
		return (res);
	free(res);
	return (tmp);
}
