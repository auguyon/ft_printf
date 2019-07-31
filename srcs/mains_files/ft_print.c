/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:45:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 16:46:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_print_buffer_end(void)
{
	if (g_buff.len != 0)
		write(1, g_buff.buf, g_buff.len);
	init_buffer();
}

void		ft_print_buffer(void)
{
	if (g_buff.len != 0)
	{
		write(1, g_buff.buf, g_buff.len);
		init_buffer();
	}
}
