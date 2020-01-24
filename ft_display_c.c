/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:06 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_c(t_tab inf, va_list args)
{
	if (inf.minus && inf.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_display_width(inf.width - 1, ' ');
		return (inf.width);
	}
	else if (!inf.minus && inf.width > 1)
		ft_display_width(inf.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	if (inf.width > 1)
		return (inf.width);
	return (1);
}
