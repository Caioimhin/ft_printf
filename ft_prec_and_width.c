/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:59 by kparis            #+#    #+#             */
/*   Updated: 2020/01/20 15:52:39 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_prec_and_width(t_stc *inf, intmax_t num, char sign_place)
{
	(sign_place) ? write(1, &sign_place, 1) : 0;
	if (inf->convert[5] == '*' && inf->convert[6] == '.' && inf->precision == 0)
	{
		ft_display_width(inf, '0', inf->width -
				(ft_strlen(ft_itoa(num))), 0);
		if (num != (-2147483648 - 1))
			ft_putnbrmax_fd(num, 1);
		else if ((inf->len += 9) > 0)
			write(1, "2147483648", 10);
		inf->m = 1;
	}
	return (inf);
}
