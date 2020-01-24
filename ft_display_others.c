/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:13 by kparis            #+#    #+#             */
/*   Updated: 2020/01/24 11:45:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_others(t_tab inf)
{
	int					ret;

	ret = 0;
	if (inf.minus)
	{
		ft_putchar_fd('%', 1);
		if (inf.zero)
			ret += ft_display_width(inf.width - 1, '0');
		else
			ret += ft_display_width(inf.width - 1, ' ');
	}
	else if (!inf.minus)
	{
		if (inf.zero)
			ret += ft_display_width(inf.width - 1, '0');
		else
			ret += ft_display_width(inf.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (ret + 1);
}
