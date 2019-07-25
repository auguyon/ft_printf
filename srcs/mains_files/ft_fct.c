/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:36:43 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 11:39:30 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_strlcat_mod(char *src, unsigned int n)
{
	unsigned int nb;

	nb = n;
	g_buff->buf += g_buff->len;
	g_buff->len += n;
	g_buff->w_len += n;
	while (n != 0)
	{
		*(g_buff->buf) = *src;
		g_buff->buf++;
		src++;
		n--;
	}
	g_buff->buf -= g_buff->len;
	src -= nb;
	if (*src)
		free(src);
	return (nb);
}
