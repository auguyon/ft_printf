/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:36:43 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 11:39:30 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlcat_mod(char *src, unsigned int n)
{
	// printf("\nsrc == :%s\n", src);
	// printf("adresse%p\n", g_buff->buf);
	// printf("valeur de len :%d\n", g_buff->len);
	// write(1, g_buff->buf, g_buff->len);
	// write(1, "\n\n", 2);
	g_buff->buf += g_buff->len;
	g_buff->len += n;
	g_buff->w_len += n;
	while (n != 0)
	{
		*(g_buff->buf) = *src;
	// printf("\tbuff :%c\t\t src :%c\n", *(char*)g_buff->buf, *(char*)src);
		g_buff->buf++;
		src++;
		n--;
	}
	g_buff->buf -= g_buff->len;
	// printf("adresse%p\n", g_buff->buf + 1);
	// printf("valeur de len %d\n", g_buff->len);
	// write(1, g_buff->buf, g_buff->len);
	// write(1, "\n\n", 2);
	return (1);
}

char	*ft_strjoin_mod(char *s, struct s_data *data_table, int i)
{
	char	*dst;
	char	flag[data_table[i].on];
	int		j;

	j = 0;
	if (data_table[i].on == 1)
	{
		flag[0] = data_table[i].flag[0];
		flag[1] = '\0';
	}
	else
	{
		while (j != data_table[i].on)
			flag[j++] = data_table[i].flag[0];
		flag[j] = '\0';
	}
	if (!(dst = ft_memalloc(ft_strlen(s) + data_table[i].on + 1)))
		return (NULL);
	ft_strcat((ft_strcpy(dst, flag)), s);
	return (dst);
}

char	*ft_ultoa_iso_format(unsigned long n, int format)
{
	unsigned long	b;
	char			*str;

	b = format;
	b += (format == 7) ? 2 : 6;
	if (!(str = (char*)malloc(sizeof(char) * b + 1)))
		return (0);
	str[b + 1] = '\0';
	if (b == 19)
		str[b--] = 'Z';
	while (b != 0)
	{
		str[b] = (n % 10) + '0';
		n = n / 10;
		b--;
		if (b == 10 && format == 13)
			str[b--] = 'T';
		else if (b == 16 || b == 13)
			str[b--] = ':';
		else if (b == 7 || b == 4)
			str[b--] = '-';
	}
	str[0] = (n % 10) + '0';
	return (str);
}