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

char	*ft_precision_format_nb(char flag, char *res, unsigned int pre)
{
	unsigned int	len_res;
	unsigned int	i;
	char			*tmp;
if (DEBUG == 1)
	printf("---- %s ----\n", "Precision Format");
	i = 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (len_res >= pre)
		return (res);
	pre = pre - len_res;
	if (!(tmp = (char*)malloc(sizeof(char) * (len_res + pre + 1))))
		return (NULL);
	while (i < pre)
		tmp[i++] = '0';
	tmp = ft_strcat(tmp, res);
	free(res);
	return (tmp);
}