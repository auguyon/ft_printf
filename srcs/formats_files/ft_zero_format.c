/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:55 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:56 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_zero_format(char flag, char *res, unsigned int zero)
{
	unsigned int	len_res;
	unsigned int	i;
	char			*tmp;

if (DEBUG == 1)
	printf("---- %s ----\n", "Zero Format");

	i = 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (len_res >= zero)
		return (res);
	zero = zero - len_res;
	if (!(tmp = (char*)malloc(sizeof(char) * (len_res + zero + 1))))
		return (NULL);
	while (i < zero)
		tmp[i++] = '0';
	tmp = ft_strcat(tmp, res);
	if (res[0] == '-')
	{
		tmp[0] = '-';
		tmp[i] = '0';
	}
	free(res);
	return (tmp);
}