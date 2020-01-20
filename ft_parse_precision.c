/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:25:26 by kparis            #+#    #+#             */
/*   Updated: 2020/01/20 15:34:31 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_stc	*ft_prec_just_num(t_stc *inf)
{
	while (inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9')
	{
		inf->precision *= 10;
		inf->precision += (inf->f_t[inf->i] - 48);
		inf->i++;
	}
	return (inf);
}

static t_stc	*ft_num(t_stc *inf)
{
	if (inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9')
	{
		ft_prec_just_num(inf);
		return (inf);
	}
	if (inf->f_t[inf->i + 1] == '.' && (inf->f_t[inf->i] >= '0'
				&& inf->f_t[inf->i] <= '9'))
	{
		while (inf->f_t[inf->i + 2] >= '0' && inf->f_t[inf->i + 2] <= '9')
		{
			inf->precision *= 10;
			inf->precision += (inf->f_t[inf->i + 2] - 48);
			inf->i++;
		}
		inf->i = inf->i + 2;
		return (inf);
	}
	else
	{
		inf->i++;
		if (inf->convert[6] == '.' &&
				(inf->f_t[inf->i] < '0' && inf->f_t[inf->i] > '9'))
			inf->i++;
		return (inf);
	}
}

static t_stc	*ft_dot(t_stc *inf)
{
	inf->i++;
	inf->precision = 0;
	if (inf->f_t[inf->i] == 's' || inf->f_t[inf->i] == 'c'
			|| inf->f_t[inf->i] == 'd' || inf->f_t[inf->i] == 'p'
			|| inf->f_t[inf->i] == 'x' || inf->f_t[inf->i] == 'X'
			|| inf->f_t[inf->i] == 'i' || inf->f_t[inf->i] == 'u')
		ft_parse_specifiers(inf);
	(inf->convert[0] == '-' && inf->f_t[inf->i - 1] != '.') ? inf->i -= 2 : 0;
	(inf->convert[0] != '-' && inf->f_t[inf->i - 1] != '.') ? inf->i -= 1 : 0;
	(inf->f_t[inf->i] == '*') ? inf->precision = inf->width : 0;
	(inf->f_t[inf->i] == '*') ? inf->i++ : 0;
	(inf->convert[5] == '*' && inf->n == 1) ? inf->precision = inf->width : 0;
	if (inf->convert[0] != '-' && inf->convert[5] == '*' &&
			(inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9'))
	{
		while (inf->f_t[inf->i - 1] >= '0' && inf->f_t[inf->i - 1] <= '9')
			inf->i--;
		while (inf->f_t[inf->i] >= '0' && inf->f_t[inf->i] <= '9')
		{
			inf->precision *= 10;
			inf->precision += (inf->f_t[inf->i] - 48);
			inf->i++;
		}
	}
	return (inf);
}

t_stc			*ft_parse_precision(t_stc *inf)
{
	int len;

	len = 0;
	if ((inf->convert[6] == '.') || (inf->f_t[inf->i] == '.'))
	{
		ft_dot(inf);
		ft_num(inf);
	}
	if (inf->precision == 0 && inf->width < 0)
		inf->precision = (-1);
	if (inf->p == 1)
		inf->precision = va_arg(inf->arg, int);
	return (inf);
}
