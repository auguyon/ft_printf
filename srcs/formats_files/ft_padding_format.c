/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:31 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_zero_format(char *s, unsigned int zero, short pre, short space)
{
	char			tmp[zero];
	char			*output;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s >= zero)
		return (space == 1 && s[0] != '-' ? ft_strjoin_free(" ", s, 2) : s);
	zero -= len_s;
	zero += (pre == 1 && s[0] == '-' ? 1 : 0);
	while (i < zero)
		tmp[i++] = '0';
	tmp[i] = '\0';
	if (s[0] == '-' || s[0] == '+')
	{
		tmp[0] = (s[0] == '-' ? '-' : '+');
		tmp[i] = '0';
		tmp[i + 1] = '\0';
	}
	space == 1 && s[0] != '-' ? tmp[0] = ' ' : 0;
	output = ft_strjoin(tmp, (s[0] == '-' ? s + 1 : s));
	free(s);
	return (output);
}

char	*ft_padding_format(char *s, unsigned int padd, short less, short space)
{
	char			tmp[padd];
	char			*output;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s >= padd)
		return (space == 1 && s[0] != '-' ? ft_strjoin_free(" ", s, 2) : s);
	padd -= len_s;
	while (i < padd)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	output = (less == 1 ? ft_strjoin(s, tmp) : ft_strjoin(tmp, s));
	output = (space == 1 && s[0] != '-' && less == 1 ?
		ft_strjoin_free(" ", output, 2) : output);
	free(s);
	return (output);
}
