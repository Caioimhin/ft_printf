/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:31 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_send_displays(char c, t_tab inf, va_list args)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret = ft_display_c(inf, args);
	else if (c == 's')
		ret = ft_display_s(inf, args);
	else if (c == 'p')
		ret = ft_display_p(inf, args);
	else if (c == 'd' || c == 'i')
		ret = ft_display_d(inf, args);
	else if (c == 'u')
		ret = ft_display_u(inf, args);
	else if (c == 'x' || c == 'X')
		ret = ft_display_x(inf, args, c);
	else if (c == '%')
		ret = ft_display_others(inf);
	return (ret);
}

int	ft_display_width(int width, char c)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
