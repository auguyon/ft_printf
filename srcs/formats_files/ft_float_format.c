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

static void	rounded(char **res, int i)
{
	while (i >= 0)
	{
		if (*res[i] == '9')
			*res[i--] = '0';
		else if (*res[i] == '.')
			i--;
		else
		{
			*res[i] += 1;
			break ;
		}
	}
}

char		*precision_float(int pre, char *res)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = ft_strchr(res, '.') - res + 1;
	if (pre == -1)
	{
		res[j - 1] = '\0';
		return (res);
	}
	while (res[j] != '\0' || i != pre)
	{
		j++;
		i++;
	}
	i += j;
	len = i;
	if (res[i] != '\0' && res[i] >= '5' && res[i] <= '9')
		rounded(&res, i);
	output = (i <= 0 ? (ft_strjoin("1", res)) : (ft_strsub(res, 0, len)));
	free(res);
	return (output);
}
