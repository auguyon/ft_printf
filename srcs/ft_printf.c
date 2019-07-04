/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:28:58 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 14:30:43 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	static int		activ_buff = 1;
	static t_color	*tab_color;
	va_list			args;
	int				len;
	
	if (activ_buff == 1)
	{
		activ_buff = ft_active_buffer_n_alloc();
		tab_color = ft_init_tab_color();
	}
	va_start(args, str);
	len = ft_parse((char*)str, args, tab_color);
	va_end(args);
	return (len);
}
