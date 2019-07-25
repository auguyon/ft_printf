/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:51:53 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/16 17:51:56 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*precision_float(int pre, char *res)
{
	char 	*output;
	int 	len;
	int		i;
	int		j;

	j = ft_strchr(res, '.') - res + 1;
	i = pre + j - 1;
	len = i + j;
	res[i + 1] = '\0';
	if (res[i] >= '5' && res[i] <= '9')
	{
		while (i >= 0)
		{
			if (res[i] == '9')
				res[i--] = '0';
			else if (res[i] == '.')
				i--;
			else
			{
				res[i] += 1;
				break ;
			}
		}
	}
	output = (i <= 0 ? (ft_strjoin("1", res)) : (ft_strsub(res, 0, len)));
	free(res);
	return (output);
}

char		*process_formats_float(t_data *dt, char *res, char flag)
{
	if (dt->dot > 0)
		res = precision_float(dt->dot, res);
	else
		res = precision_float(6, res);
	return (res);
}