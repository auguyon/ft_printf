/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 01:54:31 by auguyon           #+#    #+#             */
/*   Updated: 2019/07/17 01:54:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_space_format_nb_rev(char flag, char *res, unsigned int space, unsigned int padd)
{
	unsigned int	len_res;
	unsigned int	i;
	char			*tmp; // a la taille de padd ? pas de malloc

if (DEBUG == 1)
	printf("---- %s ----\n", "Space Format Rev");
	i = 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (space == 1 && padd == 0)
		padd = 1;
	else if (len_res < padd)
		padd = padd - len_res;
	else
		return (res);
	if (!(tmp = (char*)malloc(sizeof(char) * (len_res + padd + 1))))
		return (NULL);
	while (i < padd)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	tmp = ft_strjoin(res, tmp);
	// free(res);
	return (tmp);
}

char	*ft_space_format_nb(char flag, char *res, unsigned int space, unsigned int padd)
{
	unsigned int	len_res;
	unsigned int	i;
	char			*tmp;
if (DEBUG == 1)
	printf("---- %s ----\n", "Space Format");
	i = 0;
	len_res = (unsigned int)ft_strlen(res);
	(void)flag;
	if (space == 1 && padd == 0)
		padd = 1;
	else if (len_res < padd)
		padd = padd - len_res;
	else
		return (res);
	if (!(tmp = (char*)malloc(sizeof(char) * (len_res + padd + 1))))
		return (NULL);
	while (i < padd)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	tmp = ft_strcat(tmp, res);
	// free(res);
	return (tmp);
}