/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_widht.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:46 by kparis            #+#    #+#             */
/*   Updated: 2020/01/13 09:59:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stc	*ft_parse_widht(t_stc *inf)
{
	if (inf->convert[5] == '*')
	{
		inf->widht = va_arg(inf->arg, int);
		if (inf->widht < 0 && inf->convert[6] != '.')
		{
			inf->widht *= (-1);
			inf->convert[0] = '-';
		}
		ft_parse_specifiers(inf);
		(inf->convert[0] == '-') ? inf->i = inf->i + 1 : 0;
	}
	else if (inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9')
	{
		if (inf->f_t[inf->i - 1] == '0' && inf->f_t[inf->i - 2] == '.')
			return (inf);
		while (inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9')
		{
			inf->widht *= 10;
			inf->widht += (inf->f_t[inf->i] - 48);
			inf->i++;
		}
	}
	if (inf->widht < 0 && inf->p == 1)
		inf->widht *= (-1);
	return (inf);
}
