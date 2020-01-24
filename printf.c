/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:20:55 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	normal_char(char c)
{
	int	ret;

	ret = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		ret++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	t_tab	inf;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (ft_strcmp(format, "%") == 0)
			return (0);
		ret += normal_char(format[i]);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			inf = ft_initialize(inf);
			inf = ft_parser_flag(&format[i], inf);
			while (ft_flag(format[i]))
				i++;
			ret += ft_send_displays(format[i], inf);
			i += inf.advance;
		}
		i++;
	}
	return (ret);
}
