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
    printf("% 9d\n", 123456);
    // ft_printf("test %%\n");
    // ft_printf("la date est: %r\n", 20190629);
    // ft_printf("la date et heure sont: %r\n", 20190629174520);
    //ft_printf("on test le d %*d et apres\n test \t tr", 123456);
    // ft_printf("ensuite le s %s\t", "ca fonctione askip");
    // ft_printf("pense a faire le utoa %u test behind %% \n", 42);
    // ft_printf("test du n %n test\n", &i);
    // ft_printf("ft_n = %d", i);
}


// int     printf_int(int nb)
// {
//     printf("\t-------Int-------\n");
//     printf("i = %i\n", nb);
//     ft_printf("i = %i\n", nb);
//     printf("d = %d\n", nb);
//     ft_printf("d = %i\n", nb);
//     return (0);
// }

// int     printf_Uint(unsigned int nb)
// {
//     printf("\t-------U-Int-------\n");
//     printf("o = nb = %i\n", nb);
//     ft_printf("I = nb = %i\n", nb);
//     printf("D = nb = %d\n", nb);
//     ft_printf("D = nb = %i\n", nb);
//     int i = 42;
//     printf("\t-------Int-------\n");    
//     printf("i=42,int->d->\t\t%d\n", i);
//     printf("i=42,int->i->\t\t%i\n", i);
// }

// int     ft_strcmp(const char *s1, const char *s2)
// {
//     while ((*s1 == *s2) && *s1)
//         s1++ && s2++;
//     return ((unsigned char)*s1 - (unsigned char)*s2);
// }

// int main(int ac, char av)
// {
//     int     i = 1;
    
//     while (av[i])
//     {
//         if (ft_strcmp(av[1], "d") || ft_strcmp(av[1], "i"))
//             printf_int(ft_atoi(av[2]));
//         if (ft_strcmp(av[i], "U.int"))
//             printf_Uint();
//         if (ft_strcmp(av[i], "double"))
//             printf_double();
//         if (ft_strcmp(av[i], "char"))
//             printf_char();
//         if (ft_strcmp(av[i], "char*"))
//             printf_string();
//         i++;
//     }
// }

/*
int main(void)
{
    unsigned int    ui = 42;
    double          d = 420.02;
    long double     ld = 42;
    char            c = 'c';
    char            str[4] = "test";
    unsigned long   adr = (unsigned long)str;

    printf("\t-----Unsigned Int-----\n");
    printf("ui=42,U.int->o->\t%o\n", ui);
    printf("ui=42,U.int->u->\t%u\n", ui);
    printf("ui=42,U.int->x->\t%x\n", ui);
    printf("ui=42,U.int->X->\t%X\n", ui);

    printf("\t-------Double-------\n");
    printf("d=42,Double->e->\t%e\n", d);
    printf("d=42,Double->E->\t%E\n", d);
    printf("d=42,Double->f->\t%f\n", d);
    printf("d=42,Double->f.l->\t%.lf\n", d);
    printf("ld=42,Double->f.L->\t%.Lf\n", ld);
    printf("d=42,Double->F->\t%F\n", d);
    printf("d=42,Double->g->\t%g\n", d);
    printf("d=42,Double->G->\t%G\n", d);

    printf("\t-------Char-------\n");   
    printf("c=c,char->c->\t\t%c\n", c);
    
    printf("\t-------Char*-------\n");
    printf("str=test,char*->s->\t%s\n", str);

    printf("\t-------&Char*-------\n");
    printf("char*->p->\t\t%p\n", str);
    printf("adr=&str->\t\t0x%.lx\n", adr);
}*/