/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:51:53 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/16 17:51:56 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_hash_format_nb(char flag, char *res)
{
	char	*tmp;

printf("---- %s ----\n", "Hash Format");
	tmp = NULL;
	if (flag == 'o')
		tmp = ft_strjoin("0", res);
	else if (flag == 'x')
		tmp = ft_strjoin("0x", res);
	else if (flag == 'X')
		tmp = ft_strjoin("0X", res);
	free(res);
	return (tmp);
}
