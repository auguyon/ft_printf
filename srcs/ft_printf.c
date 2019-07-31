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
	static int		activ_buff = 0;
	static t_color	tab_color;
	va_list			args;
	int				len;

	if (activ_buff == 0)
	{
		active_buffer();
		activ_buff = ft_init_tab_color(&tab_color);
	}
	va_start(args, str);
	len = parse((char*)str, args, &tab_color, 0);
	va_end(args);
	return (len);
}
