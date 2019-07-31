/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:21:38 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/25 23:21:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*convert_string(va_list args, t_types *typ)
{
	char	*output;
	char	*tmp;

	(void)typ;
	if (!(tmp = (va_arg(args, char*))))
		return (ft_strdup("(null)"));
	if (!(output = (char*)malloc(sizeof(char) * ft_strlen(tmp) + 1)))
		return (NULL);
	output = ft_strcpy(output, tmp);
	return (output);
}

char	*convert_char(va_list args, t_types *typ)
{
	char *output;

	(void)typ;
	if (!(output = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	output[0] = ((unsigned char)va_arg(args, int));
	output[1] = '\0';
	return (output);
}
