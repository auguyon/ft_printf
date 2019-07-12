/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:23:44 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/06 19:23:59 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_convert_char(va_list args)
{
	char *output;
printf("----- %s -----\n", "ft_convert_char");

	if (!(output = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	output[0] = (va_arg(args, int));
	output[1] = '\0';
	return (output);
}

char	*ft_convert_string(va_list args)
{
	char	*output;
	char	*tmp;

printf("----- %s -----\n", "ft_convert_string");

	tmp = (va_arg(args, char*));
	if (!(output = (char*)malloc(sizeof(char) * ft_strlen(tmp) + 1)))
		return (NULL);
	output = ft_strcpy(output, tmp);
	return (output);
}
