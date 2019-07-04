/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <auguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:29:05 by auguyon           #+#    #+#             */
/*   Updated: 2019/06/20 14:30:39 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
// Type à gerer : b d i o u x X c s p e f g n uz
int main()
{
    int i = 0;
    int j = 0;

    i = 0;
    j = i;
    ft_printf("bonus color : {RED}%d ca marche ?\n", 123);
    // ft_printf("test %%\n");
    // ft_printf("la date est: %r\n", 20190629);
    // ft_printf("la date et heure sont: %r\n", 20190629174520);
    // ft_printf("on test le d %*d et apres\n test \t tr", 123456);
    // ft_printf("ensuite le s %s\t", "ca fonctione askip");
    // ft_printf("pense a faire le utoa %u test behind %% \n", 42);
    // ft_printf("test du n %n test\n", &i);
    // ft_printf("ft_n = %d", i);
}
