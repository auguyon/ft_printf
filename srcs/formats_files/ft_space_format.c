/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:31 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_space_format_nb(char flag, char *res, unsigned int space)
{
	unsigned int	len_res;
	unsigned int	i;
	char			*tmp;

printf("---- %s ----\n", "Space Format");
	i = 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (len_res >= space)
		space = 1;
	else 
		space = space - len_res;
	if (!(tmp = (char*)malloc(sizeof(char) * (len_res + space + 1))))
		return (NULL);
	while (i < space)
		tmp[i++] = ' ';
	tmp = ft_strcat(tmp, res);
	free(res);
	return (tmp);
}