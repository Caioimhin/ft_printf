/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:23:06 by kparis            #+#    #+#             */
/*   Updated: 2019/11/07 14:57:31 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			count_args(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] != '%' || str[i - 1] != '%'))
			count++;
		i++;
	}
	return (count);
}

int			ft_printf(const char *str, ...)
{
	va_list		va;
	int			count;
	char		*str2;
	char		**args;

	count = 0;
	str2 = ft_strdup(str);
	va_start(va, str);
	count = count_args(str);
	if (count == 0)
	{
		ft_putstr((char *)str);
		return (0);
	}
	if (!(args = malloc(sizeof(char *) * (count + 1))))
		return (0);

	if (!(str2 = trunc_str(str2, va, args)))
		return (0);

	if (!(str2 = check_useless_0(str2)))
		return (0);

	if (!(str2 = remove_doubledash(str2)))
		return (0);

	if (!(str2 = ft_replace_flags(str2, args)))
		return (0);

	ft_display_str(str2);
	va_end(va);
	free(str2);
	return (0);
}

int			main(void)
{
	char *coucou;

	coucou = "wesh alors";
	ft_printf("\nMOI    : coucou%% %7.5d pp %0-8.5X %-12pp\n", 42, 10, coucou);
	printf("\nPrintf : coucou%% %7.5d pp %-8.5X %-12pp\n", 42, 10, coucou);
}
