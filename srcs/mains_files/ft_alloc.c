/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:54:00 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 15:42:33 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_realloc_buffer(int realloc)
{
	unsigned int	len_tmp;
	unsigned int	w_len_tmp;
	void			*tmp;

	len_tmp = g_buff->len;
	w_len_tmp = g_buff->w_len;
	tmp = ft_strjoin(tmp, (char*)g_buff->buf);
	free(g_buff->buf);
	if (!(g_buff->buf = (char*)malloc(sizeof(char) * (ALLOC * realloc))))
			return ;
	g_buff->buf = ft_strcpy(g_buff->buf, tmp);
	g_buff->len = len_tmp;
	g_buff->w_len = w_len_tmp;
	// free(tmp);
}

static void	ft_alloc_buffer(int code)
{
	static int	realloc = 1;
	int			i;

	i = 0;
	if (code == 0)
	{
		if (!(g_buff = (t_buff*)malloc(sizeof(t_buff))))
			return ;
		if (!(g_buff->buf = (char*)malloc(sizeof(char) * (ALLOC))))
			return ;
		g_buff->len = 0;
		g_buff->w_len = 0;
		while (i < ALLOC * realloc)
			g_buff->buf[i++] = '\0';
	}
	else if (code == 1)
	{
		if (realloc != 4)
			ft_realloc_buffer(realloc);
		else
		{
			ft_print_buffer();
			ft_alloc_buffer(2);
		}
	}
	else if (code == 2)
	{
		realloc = 1;
		ft_alloc_buffer(0);
	}
	realloc++;
}

void		ft_free_n_realloc()
{
	free(g_buff->buf);
	free(g_buff);
	ft_alloc_buffer(2);
}

int			ft_active_buffer_n_alloc()
{
	void	(*ptr)(void);

	ptr = ft_print_buffer;
	atexit(ptr);
	ft_alloc_buffer(0);
	return (0);
}
