/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:19:40 by kevin             #+#    #+#             */
/*   Updated: 2020/01/13 10:01:42 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_stc	*ft_percent(t_stc *inf)
{
	if (inf->convert[3] == '0' && inf->precision <= 0 && !inf->convert[0])
	{
		inf->precision = inf->widht;
		inf->widht = 0;
	}
	if (inf->convert[0] != '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	if (inf->convert[3] == '0')
		ft_display_widht(inf, '0', inf->precision - 1, 1);
	write(1, "%", 1);
	if (inf->convert[0] == '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	inf->len++;
	return (inf);
}

t_stc			*ft_display_(t_stc *inf)
{
	if (inf->f_t[inf->i] == '%')
	{
		ft_percent(inf);
		return (inf);
	}
	if (inf->convert[3] == '0' && inf->precision <= 0 && !inf->convert[0])
	{
		inf->precision = inf->widht;
		inf->widht = 0;
	}
	if (inf->convert[0] != '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	if (inf->convert[3] == '0')
		ft_display_widht(inf, '0', inf->precision - 1, 1);
	write(1, &inf->f_copy[inf->i], 1);
	if (inf->convert[0] == '-')
		ft_display_widht(inf, ' ', inf->widht - 1, 1);
	inf->len++;
	return (inf);
}
