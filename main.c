
#include "../includes/ft_printf.h"
#include <stdio.h>

// args . ' ' # + - 0 
// csp
// dibouxX avec les flags hh, h, l, ll, z
// f avec les flags l et L

int main()
{
	int i = 0;
	int j = 0;
	float f = 123.123456789;
	long double d = 123.1111111111123;

 // printf("16chiffre 1 %.6d chiffre 2 %.6d\n\n", 42, -42);
 //  ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42);
  
  // ft_printf("%d\n", ft_printf("|% |\n")); // a gerer ?
  // printf("%d\n\n", printf("|% |\n"));
  
  // ft_printf("%d\n", ft_printf("%z\n")); // a gerer ?
  // printf("%d\n\n", printf("%z\n"));
  
  // printf("%d\n", ft_printf("This is a float : %.3f\n", 45.236));
  // printf("%d\n", printf("This is a float : %.3f\n\n", 45.236));



	// printf("1234567891 1234567891 1234567891 123456789\n");
	// ft_printf("1234567891 1234567891 1234567891 123456789\n");
	// i = printf("This is a float : %.3f\n", 45.236);
	// j = ft_printf("This is a float : %.3f\n", 45.236);
	// printf("%d %d\n",i,j);

	// printf("%f\n", f);
	// ft_printf("%f  \n", f);


	// printf("%d  %i %#o %u %#x %#X \n", 42 ,43,45,45,45,45);
	// ft_printf("agnruygjyf {red}%d hgjnyjb \n", 45);

	// ft_printf("{RED}%d -1-{Green} %i 2-2{Reset} %#o 3-3 %u 4-4 {BLUE}%#x 5-5 {CYAN}%#X 6-6 \n", 42 ,43,45,45,45,45);

	// 	printf("%hd  %hi %ho %hu %hx %hX  \n", 42 ,43,45,45,45,45);
	// ft_printf("%hd  %hi %ho %hu %hx %hX  \n", 42 ,43,45,45,45,45);

	// 	printf("%hhd  %hhi %hho %hhu %hhx %hhX  \n", 42 ,43,45,45,45,45);
	// ft_printf("%hhd  %hhi %hho %hhu %hhx %hhX  \n", 42 ,43,45,45,45,45);

	// 	printf("%ld  %li %lo %lu %lx %lX \n", 42 ,43,45,45,45,45);
	// ft_printf("%ld  %li %lo %lu %lx %lX \n", 42 ,43,45,45,45,45);

	// 	printf("%lld  %lli %llo %llu %llx %llX \n", 42 ,43,45,45,45,45);
	// ft_printf("%lld  %lli %llo %llu %llx %llX \n", 42 ,43,45,45,45,45);

	// 	printf("%zd  %zi %zo %zu %zx %zX \n", 42 ,43,45,45,45,45);
	// ft_printf("%zd  %zi %zo %zu %zx %zX \n", 42 ,43,45,45,45,45);

	// 	printf("%d  %i %#o %u %#x %#X %c \n", 42 ,43,45,45,45,45);
	// ft_printf("%d  %i %#o %u %#x %#X %c \n", 42 ,43,45,45,45,45);

	// 	printf("%d  %i %#o %u %#x %#X %c \n", 42 ,43,45,45,45,45);
	// ft_printf("%d  %i %#o %u %#x %#X %c \n", 42 ,43,45,45,45,45);

	// printf("%p\n", i);
	// ft_printf("%p\n", i);
	// printf("%d\n", 42);
	// ft_printf("%d\n", 42);
	// ft_printf("{% 02s}\n", "Bonjour");
	// printf("{% 02s}\n", "Bonjour");

	// ft_printf("{% 2s}\n", "Bonjour");
	// printf("{% 2s}\n", "Bonjour");

	// ft_printf("{% .2s}\n", "Bonjour");
	// printf("{% .2s}\n", "Bonjour");

	// ft_printf("{% 09s}\n", "Bonjour");
	// printf("{% 09s}\n", "Bonjour");

	// ft_printf("{% 9s}\n", "Bonjour");
	// printf("{% 9s}\n", "Bonjour");

	// ft_printf("{% .9s}\n", "Bonjour");
	// printf("{% .9s}\n", "Bonjour");

	// ft_printf("{%+09s}\n", "Bonjour");
	// printf("{%+09s}\n", "Bonjour");

	// ft_printf("{%-09s}\n", "Bonjour");
	// printf("{%-09s}\n", "Bonjour");

	// ft_printf("{%.s}\n", "Bonjour");
	// printf("{%.s}\n", "Bonjour");

	// ft_printf("{%   #s}\n", "Bonjour");
	// printf("{%   #s}\n", "Bonjour");

	// ft_printf("{% 2d}\n", 42);
	// printf("{% 2d}\n", 42);

	// ft_printf("{% .2d}\n", 42);
	// printf("{% .2d}\n", 42);

	// ft_printf("{% 02d}\n", 42);
	// printf("{% 02d}\n", 42);

	// ft_printf("{% 5d}\n", 42);
	// printf("{% 5d}\n", 42);

	// ft_printf("{% .5d}\n", 42);
	// printf("{% .5d}\n", 42);

	// ft_printf("{% 05d}\n", 42);
	// printf("{% 05d}\n", 42);

	// ft_printf("{% 2d}\n", -42);
	// printf("{% 2d}\n", -42);

	// ft_printf("{% .2d}\n", -42);
	// printf("{% .2d}\n", -42);

	// ft_printf("{% 02d}\n", -42);
	// printf("{% 02d}\n", -42);

	// ft_printf("{% 5d}\n", -42);
	// printf("{% 5d}\n", -42);

	// ft_printf("{% .5d}\n", -42);
	// printf("{% .5d}\n", -42);

	// ft_printf("{% 05d}\n", 42);
	// printf("{% 05d}\n", 42);

	// ft_printf("%s\n", "----------------");

	// ft_printf("{% -2d}\n", 42);
	// printf("{% -2d}\n", 42);

	// ft_printf("{% -.2d}\n", 42);
	// printf("{% -.2d}\n", 42);

	// ft_printf("{% -02d}\n", 42);
	// printf("{% -02d}\n", 42);

	// ft_printf("{% -5d}\n", 42);
	// printf("{% -5d}\n", 42);

	// ft_printf("{% -.5d}\n", 42);
	// printf("{% -.5d}\n", 42);

	// ft_printf("{% -05d}\n", 42);
	// printf("{% -05d}\n", 42);

	// ft_printf("{% -2d}\n", -42);
	// printf("{% -2d}\n", -42);

	// ft_printf("{% -.2d}\n", -42);
	// printf("{% -.2d}\n", -42);

	// ft_printf("{% -02d}\n", -42);
	// printf("{% -02d}\n", -42);

	// ft_printf("{% -5d}\n", -42);
	// printf("{% -5d}\n", -42);

	// ft_printf("{% -.5d}\n", -42);
	// printf("{% -.5d}\n", -42);

	// ft_printf("{% -05d}\n", 42);
	// printf("{% -05d}\n", 42);
    return (0);
}
