/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_widht.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:46 by kparis            #+#    #+#             */
/*   Updated: 2020/01/20 15:14:16 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_parse_widht(t_stc *inf)
{
	if (inf->convert[5] == '*')
	{
		inf->width = va_arg(inf->arg, int);
		if (inf->width < 0 && inf->convert[6] != '.')
		{
			inf->width *= (-1);
			inf->convert[0] = '-';
		}

		ft_parse_specifiers(inf);
		(inf->convert[0] == '-') ? inf->i = inf->i + 1 : 0;
	}
	else if (ft_isdigit(inf->f_t[inf->i]))
	{
		if (inf->f_t[inf->i - 1] == '0' && inf->f_t[inf->i - 2] == '.')
			return (inf);
		while (ft_isdigit(inf->f_t[inf->i]))
		{
			inf->width *= 10;
			inf->width += (inf->f_t[inf->i] - 48);
			inf->i++;
		}
	}
	if (inf->width < 0 && inf->p == 1)
	{
		inf->width *= (-1);
		inf->convert[0] = '-';
	}
	return (inf);
}
