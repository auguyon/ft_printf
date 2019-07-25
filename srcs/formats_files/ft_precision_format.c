/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:41 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:44 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_precision_format_char(char flag, char *res, unsigned int pre)
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

char	*ft_precision_format_nb(char flag, char *res, unsigned int pre)
{
	unsigned int	len_res;
	unsigned int	i;
	short			neg;		
	char			*tmp;

	i = 0;
	neg = res[0] == '-' ? 1 : 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (len_res >= pre)
		return (res);
	if (!(tmp = (char*)malloc(sizeof(char) * (pre + len_res + 1))))
		return (NULL);
	while (i < pre - (len_res - neg))
		tmp[i++] = '0';
	tmp[i] = '\0';
	tmp = ft_strcat(tmp, res);
	if (neg == 1)
	{
		tmp[0] = '-';
		tmp[i] = '0';
	}
	free(res);
	return (tmp);
}