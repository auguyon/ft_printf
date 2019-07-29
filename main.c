
#include "../includes/ft_printf.h"
#include <stdio.h>

// args . ' ' # + - 0 
// csp
// dibouxX avec les flags hh, h, l, ll, z
// f avec les flags l et L
int main()
{
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

	// Test sur les d avec precision, padding et zero + space avec chiffre neg et pos
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
