/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:31 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 17:30:43 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_send_displays(char c, t_tab tab, va_list args)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret = ft_display_c(tab, args);
	else if (c == 's')
		ret = ft_display_s(tab, args);
	else if (c == 'p')
		ret = ft_display_p(tab, args);
	else if (c == 'd' || c == 'i')
		ret = ft_display_d(tab, args);
	else if (c == 'u')
		ret = ft_display_u(tab, args);
	else if (c == 'x' || c == 'X')
		ret = ft_display_x(tab, args, c);
	else if (c == '%')
		ret = ft_display_others(tab);
	return (ret);
}

int	ft_dispalay_width(int width, char c)
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
