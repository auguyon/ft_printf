
#include "../includes/ft_printf.h"
#include <stdio.h>

// args . ' ' # + - 0 
// csp
// dibouxX avec les flags hh, h, l, ll, z
// f avec les flags l et L

int main()
{
	int n = 0;
	char c = 'B';
	char *s = "Hello World";
	char *s2 = "Salut";
	float f = 42.987654;
	long double f2 = 789456.123456;

		ft_printf("FT_ -> Double Pourcent : {%%}\n", 42);
	printf("PF_ -> Double Pourcent : {%%}\n\n", 42);


		ft_printf("FT_ -> String : {%s}\n", s);
	printf("PF_ -> String : {%s}\n\n", s);

		ft_printf("FT_ -> String with # + - ' ' : {%#s} {%+s} {%-s} {% s}\n", s2, s2, s2, s2);
	printf("PF_ -> String with # + - ' ' : {%#s} {%+s} {%-s} {% s}\n\n", s2, s2, s2, s2);

		ft_printf("FT_ -> String with padding : {%20s}\n", s);
	printf("PF_ -> String with padding : {%20s}\n\n", s);

		ft_printf("FT_ -> String with zero : {%020s}\n", s);
	printf("PF_ -> String with zero : {%020s}\n\n", s);

		ft_printf("FT_ -> String with precision : {%.5s}\n", s);
	printf("PF_ -> String with precision : {%.5s}\n\n", s);

	getchar();


		ft_printf("FT_ -> Char : {%c}\n", c);
	printf("PF_ -> Char : {%c}\n\n", c);

		ft_printf("FT_ -> Char with # + - ' ' : {%#c} {%+c} {%-c} {% c}\n", c, c, c, c);
	printf("PF_ -> Char with # + - ' ' : {%#c} {%+c} {%-c} {% c}\n\n", c, c, c, c);

		ft_printf("FT_ -> Char with padding : {%10c}\n", c);
	printf("PF_ -> Char with padding : {%10c}\n\n", c);

		ft_printf("FT_ -> Char with zero : {%010c}\n", c);
	printf("PF_ -> Char with zero : {%010c}\n\n", c);

		ft_printf("FT_ -> Char with precision : {%.10c}\n", c);
	printf("PF_ -> Char with precision : {%.10c}\n\n", c);

	getchar();

		ft_printf("FT_ -> Types d & i : {%d} {%i}\n", 42, -42);
	printf("PF_ -> Types d & i : {%d} {%i}\n\n", 42, -42);

		ft_printf("FT_ -> d & i with # + - ' ' : {%#d} {%+d} {%-d} {% d} {%#d} {%+i} {%-i} {% i}\n", 42, 42, 42, 42, -42, -42, -42, -42);
	printf("PF_ -> d & i with # + - ' ' : {%#d} {%+d} {%-d} {% d} {%#d} {%+i} {%-i} {% i}\n\n", 42, 42, 42, 42, -42, -42, -42, -42);

		ft_printf("FT_ -> d & i with padding : {%10d} {%10i}\n", 42, -42);
	printf("PF_ -> d & i with padding : {%10d} {%10i}\n\n", 42, -42);

		ft_printf("FT_ -> d & i with zero : {%010d} {%010i}\n", 42, -42);
	printf("PF_ -> d & i with zero : {%010d} {%010i}\n\n", 42, -42);

		ft_printf("FT_ -> d & i with precision : {%.10d} {%.10i}\n", 42, -42);
	printf("PF_ -> d & i with precision : {%.10d} {%.10i}\n\n", 42, -42);

	getchar();

		ft_printf("FT_ -> Types b : {%b}\n", 42);
	printf("PF_ -> Types b : {%s}\n\n", "101010");

		ft_printf("FT_ -> b with # + - ' ' : {%#b} {%+b} {%-b} {% b}\n", 42, 42, 42, 42);
	printf("PF_ -> b with # + - ' ' : {%s} {%s} {%s} {%s}\n\n", "0b101010", "101010", "101010", "101010");

		ft_printf("FT_ -> b with padding : {%10b}\n", 42);
	printf("PF_ -> b with padding : {%s}\n\n", "    101010");

		ft_printf("FT_ -> b with zero : {%010b}\n", 42);
	printf("PF_ -> b with zero : {%s}\n\n", "0000101010");

		ft_printf("FT_ -> b with precision : {%.10b}\n", 42);
	printf("PF_ -> b with precision : {%s}\n\n","0000101010");

	getchar();

		ft_printf("FT_ -> Types o : {%o} {%o}\n", 42, -42);
	printf("PF_ -> Types o : {%o} {%o}\n\n", 42, -42);

		ft_printf("FT_ -> o with # + - ' ' : {%#o} {%+o} {%-o} {% o} {%#o} {%+o} {%-o} {% o}\n", 42, 42, 42, 42, -42, -42, -42, -42);
	printf("PF_ -> o with # + - ' ' : {%#o} {%+o} {%-o} {% o} {%#o} {%+o} {%-o} {% o}\n\n", 42, 42, 42, 42, -42, -42, -42, -42);

		ft_printf("FT_ -> o with padding : {%10o} {%10o}\n", 42, -42);
	printf("PF_ -> o with padding : {%10o} {%10o}\n\n", 42, -42);

		ft_printf("FT_ -> o with zero : {%010o} {%010o}\n", 42, -42);
	printf("PF_ -> o with zero : {%010o} {%010o}\n\n", 42, -42);

		ft_printf("FT_ -> o with precision : {%.10o} {%.10o}\n", 42, -42);
	printf("PF_ -> o with precision : {%.10o} {%.10o}\n\n", 42, -42);

	getchar();

		ft_printf("FT_ -> Types u : {%u} {%u}\n", 42, -42);
	printf("PF_ -> Types u : {%u} {%u}\n\n", 42, -42);

		ft_printf("FT_ -> u with # + - ' ' : {%#u} {%+u} {%-u} {% u} {%#u} {%+u} {%-u} {% u}\n", 42, 42, 42, 42, -42, -42, -42, -42);
	printf("PF_ -> u with # + - ' ' : {%#u} {%+u} {%-u} {% u} {%#u} {%+u} {%-u} {% u}\n\n", 42, 42, 42, 42, -42, -42, -42, -42);

		ft_printf("FT_ -> u with padding : {%10u} {%10u}\n", 42, -42);
	printf("PF_ -> u with padding : {%10u} {%10u}\n\n", 42, -42);

		ft_printf("FT_ -> u with zero : {%010u} {%010u}\n", 42, -42);
	printf("PF_ -> u with zero : {%010u} {%010u}\n\n", 42, -42);

		ft_printf("FT_ -> u with precision : {%.10u} {%.10u}\n", 42, -42);
	printf("PF_ -> u with precision : {%.10u} {%.10u}\n\n", 42, -42);

	getchar();

		ft_printf("FT_ -> Types x : {%x} {%x}\n", 42, -42);
	printf("PF_ -> Types x : {%x} {%x}\n\n", 42, -42);

		ft_printf("FT_ -> x with # + - ' ' : {%#x} {%+x} {%-x} {% x} {%#x} {%+x} {%-x} {% x}\n", 42, 42, 42, 42, -42, -42, -42, -42);
	printf("PF_ -> x with # + - ' ' : {%#x} {%+x} {%-x} {% x} {%#x} {%+x} {%-x} {% x}\n\n", 42, 42, 42, 42, -42, -42, -42, -42);

		ft_printf("FT_ -> x with padding : {%10x} {%10x}\n", 42, -42);
	printf("PF_ -> x with padding : {%10x} {%10x}\n\n", 42, -42);

		ft_printf("FT_ -> x with zero : {%010x} {%010x}\n", 42, -42);
	printf("PF_ -> x with zero : {%010x} {%010x}\n\n", 42, -42);

		ft_printf("FT_ -> x with precision : {%.10x} {%.10x}\n", 42, -42);
	printf("PF_ -> x with precision : {%.10x} {%.10x}\n\n", 42, -42);

	getchar();

		ft_printf("FT_ -> Types X : {%X} {%X}\n", 42, -42);
	printf("PF_ -> Types X : {%X} {%X}\n\n", 42, -42);

		ft_printf("FT_ -> X with # + - ' ' : {%#X} {%+X} {%-X} {% X} {%#X} {%+X} {%-X} {% X}\n", 42, 42, 42, 42, -42, -42, -42, -42);
	printf("PF_ -> X with # + - ' ' : {%#X} {%+X} {%-X} {% X} {%#X} {%+X} {%-X} {% X}\n\n", 42, 42, 42, 42, -42, -42, -42, -42);

		ft_printf("FT_ -> X with padding : {%10X} {%10X}\n", 42, -42);
	printf("PF_ -> X with padding : {%10X} {%10X}\n\n", 42, -42);

		ft_printf("FT_ -> X with zero : {%010X} {%010X}\n", 42, -42);
	printf("PF_ -> X with zero : {%010X} {%010X}\n\n", 42, -42);

		ft_printf("FT_ -> X with precision : {%.10X} {%.10X}\n", 42, -42);
	printf("PF_ -> X with precision : {%.10X} {%.10X}\n\n", 42, -42);

	getchar();

		ft_printf("FT_ -> d & i with hh h ll l z : {%hhd} {%hd} {%lld} {%ld} {%zd} {%hhi} {%hi} {%lli} {%li} {%zi}\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);
	printf("PF_ -> d & i with hh h ll l z : {%hhd} {%hd} {%lld} {%ld} {%zd} {%hhi} {%hi} {%lli} {%li} {%zi}\n\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);

		ft_printf("FT_ -> b with hh h ll l z : {%hhb} {%hb} {%llb} {%lb} {%zb}\n", 42, 42, 42, 42, 42);
	printf("PF_ -> b with hh h ll l z : {%s} {%s} {%s} {%s} {%s}\n\n", "101010", "101010", "101010", "101010", "101010");

		ft_printf("FT_ -> o with hh h ll l z : {%hho} {%ho} {%llo} {%lo} {%zo} {%hho} {%ho} {%llo} {%lo} {%zo}\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);
	printf("PF_ -> o with hh h ll l z : {%hho} {%ho} {%llo} {%lo} {%zo} {%hho} {%ho} {%llo} {%lo} {%zo}\n\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);

		ft_printf("FT_ -> u with hh h ll l z : {%hhu} {%hu} {%llu} {%lu} {%zu} {%hhu} {%hu} {%llu} {%lu} {%zu}\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);
	printf("PF_ -> u with hh h ll l z : {%hhu} {%hu} {%llu} {%lu} {%zu} {%hhu} {%hu} {%llu} {%lu} {%zu}\n\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);

		ft_printf("FT_ -> x with hh h ll l z : {%hhx} {%hx} {%llx} {%lx} {%zx} {%hhx} {%hx} {%llx} {%lx} {%zx}\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);
	printf("PF_ -> x with hh h ll l z : {%hhx} {%hx} {%llx} {%lx} {%zx} {%hhx} {%hx} {%llx} {%lx} {%zx}\n\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);

		ft_printf("FT_ -> X with hh h ll l z : {%hhX} {%hX} {%llX} {%lX} {%zX} {%hhX} {%hX} {%llX} {%lX} {%zX}\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);
	printf("PF_ -> X with hh h ll l z : {%hhX} {%hX} {%llX} {%lX} {%zX} {%hhX} {%hX} {%llX} {%lX} {%zX}\n\n", 42, 42, 42, 42, 42, -42, -42, -42, -42, -42);

	getchar();

		ft_printf("FT_ -> Multi s x c X i u d b o f F: {%s} {%x} {%c} {%X} {%i} {%u} {%d} {%b} {%o}\n", s, -42, c, 42, 1, -50, -123, 4, 123);
	printf("PF_ -> Multi s x c X i u d b o f F: {%s} {%x} {%c} {%X} {%i} {%u} {%d} {%s} {%o}\n\n", s, -42, c, 42, 1, -50, -123, "100", 123);

	getchar();

		ft_printf("FT_ -> Types f : {%f}\n", f);
	printf("PF_ -> Types f : {%f}\n\n", f);

		ft_printf("FT_ -> f with # + - ' ' : {%#f} {%+f} {%-f} {% f}\n", f, f, f, f);
	printf("PF_ -> f with # + - ' ' : {%#f} {%+f} {%-f} {% f}\n\n", f, f, f, f);

		ft_printf("FT_ -> f with padding : {%10f}\n", f);
	printf("PF_ -> f with padding : {%10f}\n\n", f);

		ft_printf("FT_ -> f with zero : {%010f}\n", f);
	printf("PF_ -> f with zero : {%010f}\n\n", f);

		ft_printf("FT_ -> f with precision : {%.10f}\n", f);
	printf("PF_ -> f with precision : {%.10f}\n\n", f);

		ft_printf("FT_ -> f with l L : {%lf} {%Lf}\n", f, f2);
	printf("PF_ -> f with l L : {%lf} {%Lf}\n\n", f, f2);

	getchar();

		ft_printf("FT_ -> Types F : {%F}\n", f);
	printf("PF_ -> Types F : {%F}\n\n", f);

		ft_printf("FT_ -> F with # + - ' ' : {%#F} {%+F} {%-F} {% F}\n", f, f, f, f);
	printf("PF_ -> F with # + - ' ' : {%#F} {%+F} {%-F} {% F}\n\n", f, f, f, f);

		ft_printf("FT_ -> F with padding : {%10F}\n", f);
	printf("PF_ -> F with padding : {%10F}\n\n", f);

		ft_printf("FT_ -> F with zero : {%010F}\n", f);
	printf("PF_ -> F with zero : {%010F}\n\n", f);

		ft_printf("FT_ -> F with precision : {%.10F}\n", f);
	printf("PF_ -> F with precision : {%.10F}\n\n", f);

		ft_printf("FT_ -> F with l L : {%lF} {%LF}\n", f, f2);
	printf("PF_ -> F with l L : {%lF} {%LF}\n\n", f, f2);

	getchar();

	ft_printf("###### {RED}Bonus{Reset} ######\n\n");

	ft_printf("- Bonus color : before flag : {red}%d {blue}Blue {cyan}Cyan {red}Red {green}Green {yellow}Yellow {magenta}Magenta\n\n", 42);

	ft_printf("Flag: b, F, n and k, specifier: z\n");

	ft_printf("- Return the Size\n- 'Speed'\n- Specifier z or size_t\n- Flag b for binary\n- Flag F for float\n- Flag n for put the number of char write before the flag and entered in the variable in params\n");

	ft_printf("- Flag k for date in ISO8601\n- Buffer bonus print with the end of processus or with /n\n");

	ft_printf("- Flag date: |%k| date & hours: |%k|\n", 20190110, 20190110193100);

	ft_printf("- Flag n%n\n", &n);
	ft_printf("retour de n = |%i|\n", n);
    return (0);
}
