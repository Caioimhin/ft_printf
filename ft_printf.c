/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:25 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:41:51 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_normal_case(char c)
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
	va_list args;
	t_tab	tab;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		ret += ft_normal_case(format[i]);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			tab = ft_initialize(tab);
			tab = parser_flags(&format[i], tab, args);
			while (ft_flag(format[i]))
				i++;
			ret += ft_send_displays(format[i], tab, args);
		}
		i++;
	}
	return (ret);
}
