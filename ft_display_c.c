/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:06 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 17:29:35 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_c(t_tab tab, va_list args)
{
	if (tab.minus && tab.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_dispalay_width(tab.width - 1, ' ');
		return (tab.width);
	}
	else if (!tab.minus && tab.width > 1)
		ft_dispalay_width(tab.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	if (tab.width > 1)
		return (tab.width);
	return (1);
}
