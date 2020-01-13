/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:59 by kparis            #+#    #+#             */
/*   Updated: 2020/01/10 15:55:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_prec_and_width(t_struct *info, intmax_t num, char sign_place)
{
	(sign_place) ? write(1, &sign_place, 1) : 0;
	if (info->convert[5] == '*' && info->convert[6] == '.' && info->precision == 0)
	{
		ft_display_widht(info, '0', info->widht -
				(ft_strlen(ft_itoa(num))), 0);
		if (num != (-2147483648 - 1))
			ft_putnbrmax_fd(num, 1);
		else if ((info->len += 9) > 0)
			write(1, "2147483648", 10);
		info->m = 1;
	}
	return (info);
}
