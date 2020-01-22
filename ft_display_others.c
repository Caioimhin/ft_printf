/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:19:13 by kparis            #+#    #+#             */
/*   Updated: 2020/01/22 16:19:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_others(t_tab tab)
{
	int					ret;

	ret = 0;
	if (tab.minus)
	{
		ft_putchar_fd('%', 1);
		if (tab.zero)
			ret += ft_dispalay_width(tab.width - 1, '0');
		else
			ret += ft_dispalay_width(tab.width - 1, ' ');
	}
	else if (!tab.minus)
	{
		if (tab.zero)
			ret += ft_dispalay_width(tab.width - 1, '0');
		else
			ret += ft_dispalay_width(tab.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (ret + 1);
}
