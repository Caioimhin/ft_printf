/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:07:40 by kparis            #+#    #+#             */
/*   Updated: 2020/01/23 11:50:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	ft_printf("coucou %c\n", 'a');
	printf("coucou %c\n", 'a');


	int c;
	int c2;
	int i;
	int i2;
	int w;
	int w2;
	int y;
	int y2;

	c = 0;
	c2 = 0;
	i = 0;
	i2 = 0;
	w = 0;
	w2 = 0;
	y = 0;
	y2 = 0;
	printf("\t==TEST==\n\n");

/*
	printf("\t==Undefined behavior//Invalid conversions==\n");

	printf("le printf : %5\n");
	ft_printf("ft_printf : %5\n\n");
	//
	printf("le printf : %05\n");
	ft_printf("ft_printf : %05\n\n");

	printf("le printf : %-05\n");
	ft_printf("ft_printf : %-05\n\n");

	printf("le printf : %-5\n");
	ft_printf("ft_printf : %-5\n\n");

	printf("le printf :%.5p\n", 0);
	ft_printf("ft_printf :%.5p\n\n", 0);

	printf("le printf :%.0p\n", 0);
	ft_printf("ft_printf :%.0p\n\n", 0);

	printf("le printf :%c\n", NULL);
	ft_printf("ft_printf :%c\n\n", NULL);
*/


	printf("\t== %% ==\n\n");

	printf("le printf : %%\n");
	ft_printf("ft_printf : %%\n\n");



	printf("\t== Strings ==\n\n");

	printf("le printf %%.7s :%.7s|\n", "hello");
	ft_printf("ft_printf %%.7s :%.7s|\n\n", "hello");

	printf("le printf %%32s :|%32s|\n", "abc");
	ft_printf("ft_printf %%32s :|%32s|\n\n", "abc");

	printf("le printf %%16s :|%16s|\n", "nark nark");
	ft_printf("ft_printf %%16s :|%16s|\n\n", "nark nark");

	printf("le printf %%.3s :|%.3s|\n", "hello");
	ft_printf("ft_printf %%.3s :|%.3s|\n\n", "hello");

	printf("le printf :%.s|\n", "hello");
	ft_printf("ft_printf :%.s|\n\n", "hello");

	printf("le printf :%.00s|\n", "\0");
	ft_printf("ft_printf :%.00s|\n\n", "\0");

	printf("le printf :%.0s|\n", "hello");
	ft_printf("ft_printf :%.0s|\n\n", "hello");

	printf("le printf :%.3s%.2s\n", "holla", "bitch");
	ft_printf("ft_printf :%.3s%.2s\n\n", "holla", "bitch");

	printf("le printf :%.2s%.7s\n", "hello", "world");
	ft_printf("ft_printf :%.2s%.7s\n\n", "hello", "world");

	printf("le printf :%7.5s\n", "yolo");
	ft_printf("ft_printf :%7.5s\n\n", "yolo");

	printf("le printf :%.09s\n", NULL);
	ft_printf("ft_printf :%.09s\n\n", NULL);

	printf("le printf %%1.s:%1.s|\n", "\0");
	ft_printf("ft_printf %%1.s:%1.s|\n\n", "\0");

	printf("le printf %%.s:%.s|\n", "NULL");
	ft_printf("ft_printf %%.s:%.s|\n\n", "NULL");

	printf("le printf :%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("ft_printf :%%-*.3s LYDI == |%-*.3s|\n\n", 5, "LYDI");

	printf("le printf :|%.12s|\n", "salut");
	ft_printf("ft_printf :|%.12s|\n\n", "salut");

	printf("le printf %%.111s :|%.111s|\n", "1234567891011");
	ft_printf("ft_printf %%.111s :|%.111s|\n\n", "1234567891011");

	printf("le printf :%.03s\n", NULL);
	ft_printf("ft_printf :%.03s\n\n", NULL);

	printf("le printf :%-7.5s|\n", "yolo");
	ft_printf("ft_printf :%-7.5s|\n\n", "yolo");

	printf("le printf :%.s|\n", "NULL");
	ft_printf("ft_printf :%.s|\n\n", "NULL");

	printf("le printf :%.0s|\n", "NULL");
	ft_printf("ft_printf :%.0s|\n\n", "NULL");

	printf("le printf :|%3.s|\n", NULL);
	ft_printf("ft_printf :|%3.s|\n\n", NULL);

	printf("le printf :%10.s|\n", NULL);
	ft_printf("ft_printf :%10.s|\n\n", NULL);

	printf("le printf :|%2.s|\n", "\0");
	ft_printf("ft_printf :|%2.s|\n\n", "\0");

	printf("le printf :|%-8.s|\n", NULL);
	ft_printf("ft_printf :|%-8.s|\n\n", NULL);

	printf("le printf :|%-6.s|\n", "\0");
	ft_printf("ft_printf :|%-6.s|\n\n", "\0");

	printf("le printf :|%-10.s|\n", "\0");
	ft_printf("ft_printf :|%-10.s|\n\n", "\0");

	printf("le printf :|%.00s|\n", "\0");
	ft_printf("ft_printf :|%.00s|\n\n", "\0");

	printf("le printf :%.*s|\n", -3, "hello");
	ft_printf("ft_printf :%.*s|\n\n", -3, "hello");

	printf("le printf :%*s|\n", -3, "hello");
	ft_printf("ft_printf :%*s|\n\n", -3, "hello");

	printf("le printf :%*s|\n", -32, "abc");
	ft_printf("ft_printf :%*s|\n\n", -32, "abc");

	printf("le printf :%-*s|\n", -32, "abc");
	ft_printf("ft_printf :%-*s|\n\n", -32, "abc");

	printf("le printf %%-.09s:%-.09s|\n", "hi low");
	ft_printf("ft_printf %%-.09s:%-.09s|\n\n", "hi low");

	printf("le printf %%.*s, 3, hello :%.*s|\n", 3, "hello");
	ft_printf("ft_printf %%.*s, 3, hello :%.*s|\n\n", 3, "hello");

	printf("le printf %%-*.*s|, 7, 3, yolo :%-*.*s|\n", 7, 3, "yolo");
	ft_printf("ft_printf %%-*.*s|, 7, 3, yolo :%-*.*s|\n\n", 7, 3, "yolo");

	printf("le printf %%-*.*s|, -7, -3, yolo :%-*.*s|\n", -7, -3, "yolo");
	ft_printf("ft_printf %%-*.*s|, -7, -3, yolo :%-*.*s|\n\n", -7, -3, "yolo");

	printf("le printf %%*.15s, 17 :j'ai%*.15s\n", 17, "histoires dans ma besace");
	ft_printf("ft_printf %%*.15s, 17 :j'ai%*.15s\n\n", 17, "histoires dans ma besace");

	printf("le printf %%*.8s, 12 :j'ai%*.8s\n", 12, "histoires dans ma besace");
	ft_printf("ft_printf %%*.8s, 12 :j'ai%*.8s\n\n", 12, "histoires dans ma besace");

	printf("le printf :%%.0s, hello :|%.0s|\n", "hello");
	ft_printf("ft_printf :%%.0s, hello :|%.0s|\n\n", "hello");

	printf("\t== i d ==\n\n");

	printf("le printf : j'ai %i histoires dans ma besace\n", 1001);
	ft_printf("ft_printf : j'ai %i histoires dans ma besace\n\n", 1001);

	printf("le printf :%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("ft_printf :%%*i 42 == |%*i|\n\n", 5, 42);

	printf("le printf :|%.0i|\n", 0);
	ft_printf("ft_printf :|%.0i|\n\n", 0);

	printf("le printf :|%-5.i|\n", 0);
	ft_printf("ft_printf :|%-5.i|\n\n", 0);

	printf("le printf :j'ai %*i histoires dans ma besace\n", 4, 1001);
	ft_printf("ft_printf :j'ai %*i histoires dans ma besace\n\n", 4, 1001);

	printf("le printf :%.d, %.2d|\n", 42, 42);
	ft_printf("ft_printf :%.d, %.2d|\n\n", 42, 42);

	printf("le printf :%.0i|\n", 0);
	ft_printf("ft_printf :%.0i|\n\n", 0);

	printf("le printf :this %i number\n", 0);
	ft_printf("ft_printf :this %i number\n\n", 0);

	printf("le printf :%3i|\n", 0);
	ft_printf("ft_printf :%3i|\n\n", 0);

	printf("le printf :%03i|\n", 0);
	ft_printf("ft_printf :%03i|\n\n", 0);

	printf("le printf :%5.0i|\n", 0);
	ft_printf("ft_printf :%5.0i|\n\n", 0);

	printf("le printf :|%0*i|\n", -7, -54);
	ft_printf("ft_printf :|%0*i|\n\n", -7, -54);

	printf("le printf :%*i|\n", -14, 94827);
	ft_printf("ft_printf :%*i|\n\n", -14, 94827);

	printf("le printf :%i|\n", -14);
	ft_printf("ft_printf :%i|\n\n", -14);

	printf("le printf :%07i|\n", -54);
	ft_printf("ft_printf :%07i|\n\n", -54);

	printf("le printf :%07i|\n", 54);
	ft_printf("ft_printf :%07i|\n\n", 54);

	printf("le printf :%.i|\n", 0);
	ft_printf("ft_printf :%.i|\n\n", 0);

	printf("le printf :%010.5i|\n", -216);
	ft_printf("ft_printf :%010.5i|\n\n", -216);

	printf("le printf :%03.7d|\n", -2375);
	ft_printf("ft_printf :%03.7d|\n\n", -2375);

	printf("le printf %%.*i, 6, -3:%.*i|\n", 6, -3);
	ft_printf("ft_printf %%.*i, 6, -3:%.*i|\n\n", 6, -3);

	printf("le printf %%.*i, 6, 3:%.*i|\n", 6, 3);
	ft_printf("ft_printf %%.*i, 6, 3:%.*i|\n\n", 6, 3);

	printf("le printf %%02i, -1 :%02i|\n", -1);
	ft_printf("ft_printf %%02i, -1 :%02i|\n\n", -1);

	printf("le printf %%03d, -1 :%03d|\n", -1);
	ft_printf("ft_printf %%03d, -1 :%03d|\n\n", -1);

	printf("le printf %%.*d, 0, 42 :|%.*d|\n", 0, 42);
	ft_printf("ft_printf %%.*d, 0, 42 :|%.*d|\n\n", 0, 42);


	printf("\t== u ==\n\n");

	printf("le printf :%7u|\n", 33);
	ft_printf("ft_printf :%7u|\n\n", 33);

	printf("le printf :%%*u 42 == |%*ua\n", 5, 42);
	ft_printf("ft_printf :%%*u 42 == |%*ua\n\n", 5, 42);

	printf("le printf :|%.0u|\n", 0);
	ft_printf("ft_printf :|%.0u|\n\n", 0);

	printf("le printf :|%-5.u|\n", 0);
	ft_printf("ft_printf :|%-5.u|\n\n", 0);

	printf("le printf :|%-15.u|\n", 0);
	ft_printf("ft_printf :|%-15.u|\n\n", 0);

	printf("le printf :this %u number\n", 0);
	ft_printf("ft_printf :this %u number\n\n", 0);

	printf("le printf :%3u|\n", 0);
	ft_printf("ft_printf :%3u|\n\n", 0);

	printf("le printf :%-3u|\n", 0);
	ft_printf("ft_printf :%-3u|\n\n", 0);

	printf("le printf :%03u|\n", 0);
	ft_printf("ft_printf :%03u|\n\n", 0);

	printf("le printf :%5.0u|\n", 0);
	ft_printf("ft_printf :%5.0u|\n\n", 0);

	printf("le printf :%5.u|\n", 0);
	ft_printf("ft_printf :%5.u|\n\n", 0);

	printf("le printf :%-5.0u|\n", 0);
	ft_printf("ft_printf :%-5.0u|\n\n", 0);

	printf("le printf %%u, UINT_MAX + 1 :%u|\n", UINT_MAX + 1);
	ft_printf("ft_printf %%u, UINT_MAX + 1 :%u|\n\n", UINT_MAX + 1);

	printf("le printf %%u, 0 :%u|\n", 0);
	ft_printf("ft_printf %%u, 0 :%u|\n\n", 0);

	printf("\t== c ==\n");

	printf("le printf \\0 :%c\n", '\0');
	ft_printf("ft_printf \\0 :%c\n\n", '\0');

	printf("le printf %%*c, -1000, 'a' :%*c|\n", -1000, 'a');
	ft_printf("ft_printf %%*c, -1000, 'a' :%*c|\n\n", -1000, 'a');

	printf("le printf :%c\n", 0);
	ft_printf("ft_printf :%c\n\n", 0);

	printf("le printf %0%c, 0:0%c\n", 0);
	ft_printf("ft_printf %0%c, 0:0%c|\n\n", 0);

	printf("\tprintf ft_printf et write renvoient le nombre de bytes ecrits si 1 1 1 = OK, il y a bien un byte ecrit. Si non, 0.\n");

	int nb = 0;
	int nb2 = 0;
	int nb3 = 0;
	nb = ft_printf("c", '\0');
	nb2 = printf("c", '\0');
	nb3 = write(1, &c, 1);
	printf("\n\nI get:\n");
	printf("%d\n", nb);
	printf("%d\n", nb2);
	printf("%d\n", nb3);


/*
	printf("\t== n ==\n");

	printf("le printf %%n : %n\n", &c);
	ft_printf("ft_printf %%n : %n\n", &c2);

	printf("le printf affiche %%n : %d\n", c);
	ft_printf("ft_printf affiche %%n : %d\n\n", c2);

	printf("le printf :%c%n\n", '\0', &i);
	ft_printf("ft_printf :%c%n\n", '\0', &i2);

	printf("le printf affiche %%n : %d\n", i);
	ft_printf("ft_printf affiche %%n : %d\n\n", i2);

	printf("le printf :%-*.2i%017ukaq%18cSld%*sZFut%n\n", 8, -2147483647, 1985311988, 'A', 3, "", &w);
	ft_printf("ft_printf :%-*.2i%017ukaq%18cSld%*sZFut%n\n", 8, -2147483647, 1985311988, 'A', 3, "", &w2);
	printf("le printf affiche %%n : %d\n", w);
	ft_printf("ft_printf affiche %%n : %d\n\n", w2);

	printf("le printf :%-*.2i%017ukaq%18cSld%*sZFut??%n\n", 8, -2147483647, 1985311988, 'A', 3, "!!", &y);
	ft_printf("ft_printf :%-*.2i%017ukaq%18cSld%*sZFut??%n\n", 8, -2147483647, 1985311988, 'A', 3, "!!", &y2);
	printf("le printf affiche %%n : %d\n", y);
	ft_printf("ft_printf affiche %%n : %d\n\n", y2);

	y = 0;
	y2 = 0;
	printf("le printf :%-*.2i%017ukaq%18cSld%n\n", 8, -2147483647, 1985311988, 'A', &y);
	ft_printf("ft_printf :%-*.2i%017ukaq%18cSld%n\n", 8, -2147483647, 1985311988, 'A', &y2);
	printf("le printf affiche %%n : %d\n", y);
	ft_printf("ft_printf affiche %%n : %d\n\n", y2);

	y = 0;
	y2 = 0;
	printf("le printf :%-*.2i%017ukaq%n\n", 8, -2147483647, 1985311988, &y);
	ft_printf("ft_printf :%-*.2i%017ukaq%n\n", 8, -2147483647, 1985311988, &y2);
	printf("le printf affiche %%n : %d\n", y);
	ft_printf("ft_printf affiche %%n : %d\n\n", y2);

	y = 0;
	y2 = 0;
	printf("le printf :%-*.2i%017ukaqSld%*sZFut??%n\n", 8, -2147483647, 1985311988, 3, "!!", &y);
	ft_printf("ft_printf :%-*.2i%017ukaqSld%*sZFut??%n\n", 8, -2147483647, 1985311988, 3, "!!", &y2);
	printf("le printf affiche %%n : %d\n", y);
	ft_printf("ft_printf affiche %%n : %d\n\n", y2);


*/
	printf("\t== x X ==\n\n");

	printf("le printf %%.0x:%.0x|\n", 0);
	ft_printf("ft_printf %%.0x:%.0x|\n\n", 0);

	printf("le printf %%.x:%.x|\n", 0);
	ft_printf("ft_printf %%.x:%.x|\n\n", 0);

	printf("le printf %%5.x:%5.x|\n", 0);
	ft_printf("ft_printf %%5.x:%5.x|\n\n", 0);

	printf("le printf %%-5.X:%-5.X|\n", 0);
	ft_printf("ft_printf %%-5.X:%-5.X|\n\n", 0);

	printf("le printf %%.0X:%.0X|\n", 0);
	ft_printf("ft_printf %%.0X:%.0X|\n\n", 0);

	printf("le printf %%x:this %x number\n", 0);
	ft_printf("ft_printf %%x:this %x number\n\n", 0);

	printf("le printf %%3x:%3x|\n", 0);
	ft_printf("ft_printf %%3x:%3x|\n\n", 0);

	printf("le printf %%-3X:%-3X|\n", 0);
	ft_printf("ft_printf %%-3X:%-3X|\n\n", 0);

	printf("le printf %%03X:%03X|\n", 0);
	ft_printf("ft_printf %%03X:%03X|\n\n", 0);

	printf("le printf %%X, 0 :%X|\n", 0);
	ft_printf("ft_printf %%X, 0 :%X|\n\n", 0);

	printf("le printf %%1X, 0 :%1X|\n", 0);
	ft_printf("ft_printf %%1X, 0 :%1X|\n\n", 0);

	printf("le printf %%2X, 0 :%2X|\n", 0);
	ft_printf("ft_printf %%2X, 0 :%2X|\n\n", 0);

	printf("le printf %%10x, 0 :%10x|\n", 0);
	ft_printf("ft_printf %%10x, 0 :%10x|\n\n", 0);

	printf("le printf %%10x, 53 :%10x|\n", 53);
	ft_printf("ft_printf %%10x, 53 :%10x|\n\n", 53);

	printf("le printf %%010X, 0 :%010x|\n", 0);
	ft_printf("ft_printf %%010X, 0 :%010x|\n\n", 0);

	printf("le printf Hexadecimal value is x 444 1bc: %x\n", 444);
	ft_printf("ft_printf Hexadecimal value is x 444 1bc: %x\n\n", 444);

	printf("le printf Hexadecimal value is X 444 1BC: %X\n", 444);
	ft_printf("ft_printf Hexadecimal value is X 444 1BC: %X\n\n", 444);

	printf("le printf Hexadecimal value is x 523687 7fda7: %x\n", 523687);
	ft_printf("ft_printf Hexadecimal value is x 523687 7fda7: %x\n\n", 523687);

	printf("le printf Hexadecimal value is X 523687 7FDA7: %X\n", 523687);
	ft_printf("ft_printf Hexadecimal value is X 523687 7FDA7: %X\n\n", 523687);


	printf("\t== P ==\n\n");

	printf("le printf %%p NULL:%p|\n", NULL);
	ft_printf("ft_printf %%p NULL:%p|\n\n", NULL);

	printf("le printf %%5p NULL:%5p|\n", NULL);
	ft_printf("ft_printf %%5p NULL:%5p|\n\n", NULL);

	printf("le printf %%2p NULL:%2p|\n", NULL);
	ft_printf("ft_printf %%2p NULL:%2p|\n\n", NULL);

	printf("le printf %%5.p NULL:%5.p|\n", NULL);
	ft_printf("ft_printf %%5.p NULL:%5.p|\n\n", NULL);

	printf("le printf %%2.p NULL:%2.p|\n", NULL);
	ft_printf("ft_printf %%2.p NULL:%2.p|\n\n", NULL);

	printf("//le printf %%.5p:%.5p|\n", 0);
	ft_printf("//ft_printf %%.5p:%.5p|\n\n", 0);

	printf("//le printf %%5.p 12:%5.p|\n", 12);
	ft_printf("//ft_printf %%5.p 12:%5.p|\n\n", 12);

	printf("//le printf %%5p:%5p|\n", 0);
	ft_printf("//ft_printf %%5p:%5p|\n\n", 0);

	printf("//le printf %%.0p:%.0p|\n", 0);
	ft_printf("//ft_printf %%.0p:%.0p|\n\n", 0);

	printf("//le printf %%5.0p:%5.0p|\n", 0);
	ft_printf("//ft_printf %%5.0p:%5.0p|\n\n", 0);

	printf("le printf %%.p NULL:%.p|\n", NULL);
	ft_printf("ft_printf %%.p NULL:%.p|\n\n", NULL);

	printf("le printf %%p, (void*)ULONG_MAX + 1) :%p\n", (void*)ULONG_MAX + 1);
	ft_printf("ft_printf %%p, (void*)ULONG_MAX + 1) :%p\n\n", (void*)ULONG_MAX + 1);
/**/
	return (0);
}
