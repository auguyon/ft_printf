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

#include "../../includes/ft_printf.h"

int	ft_strlcat_mod(char *src, unsigned int n)
{
	unsigned int nb;

	nb = n;
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
	return (nb);
}

// char	*ft_strjoin_mod(char *s, struct s_data *data_table, int i) // refaire fct et free s avant le retour
// {
// 	char	*dst;
// 	char	flag[data_table[i].value];
// 	int		j;

// 	j = 0;
// 	if (data_table[j].value == 1)
// 	{
// 		flag[0] = data_table[i].flag[0];
// 		flag[1] = '\0';
// 	}
// 	else
// 	{
// 		while (j != data_table[j].value)
// 			flag[j++] = data_table[i].flag[0];
// 		flag[j] = '\0';
// 	}
// 	if (!(dst = ft_memalloc(ft_strlen(s) + data_table[j].value + 1)))
// 		return (NULL);
// 	ft_strcat((ft_strcpy(dst, flag)), s);
// 	return (dst);
// }
