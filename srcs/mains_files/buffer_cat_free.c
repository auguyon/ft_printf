/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_cat_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:36:43 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 11:39:30 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		init_buffer(void)
{
	ft_bzero(g_buff.buf, BUFF_SIZE);
	g_buff.len = 0;
	g_buff.w_len = 0;
}

int			active_buffer(void)
{
	void	(*ptr)(void);

	ptr = ft_print_buffer_end;
	atexit(ptr);
	init_buffer();
	return (0);
}

static void	max_buff_size(char **src, unsigned int *n)
{
	char	*tmp;

	tmp = NULL;
	if (g_buff.len != 0)
		ft_print_buffer();
	while (BUFF_SIZE <= *n)
	{
		write(1, *src, BUFF_SIZE);
		*(n) -= BUFF_SIZE;
		tmp = ft_strdup(*(src) + BUFF_SIZE);
		free(*src);
		*(src) = tmp;
	}
}

int			buffer_cat_free(char *src, unsigned int n, short code_free)
{
	unsigned int i;
	unsigned int j;

	i = g_buff.len == 0 ? 0 : g_buff.len;
	j = 0;
	if (BUFF_SIZE <= n || BUFF_SIZE <= (g_buff.len + n))
		max_buff_size(&src, &n);
	g_buff.len += n;
	g_buff.w_len += n;
	while (j < n)
		g_buff.buf[i++] = src[j++];
	if (code_free)
		free(src);
	return (n);
}
